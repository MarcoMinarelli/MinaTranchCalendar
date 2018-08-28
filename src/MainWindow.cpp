#include<iostream>

#include<QStringList>
#include<QLineEdit>
#include<QDir>
#include<QInputDialog>
#include<QMessageBox>


#include "MainWindow.h"

/**
	Costructor
	@param u: the user whose ActivityLists and tasks will be shown
	@param us: the controller 
*/
MainWindow::MainWindow(std::shared_ptr<User> u, std::shared_ptr<UserController> uc) : user(u), userController(uc){
	setWindowTitle("Minarelli Tranchino Calendar");
	std::shared_ptr<ActivityListController> alc(new ActivityListController(user->getActivityLists().at(0)));
	alw = new ActivityListWidget(user->getActivityLists().at(0), alc, user);
	listWidget = new QListWidget;
	addButton = new QPushButton("Add Activity List");
	removeButton = new QPushButton("Remove Activity List");
	showButton = new QPushButton("Show Activity List");
	mainWid = new QWidget;
	leftLayout = new QVBoxLayout;
    mainLayout = new QHBoxLayout;
	user->attach(this);
   	setupUI();
   	setupListeners();
}

MainWindow::~MainWindow(){
	user->detach(this);
	delete alw;
	delete listWidget;
	delete addButton;
	delete showButton;
	delete removeButton;
	delete mainWid;
	delete leftLayout;
	delete mainLayout;
}


/**
	Method that set up the listeners, in order to use the GUI
*/
void MainWindow::setupListeners(){
	connect(addButton, SIGNAL (released()), this, SLOT (handleAddButton()));
	connect(removeButton, SIGNAL (released()), this, SLOT (handleRemoveButton()));
	connect(showButton, SIGNAL(released()), this, SLOT(handleChangeSelectedItem()));
}

/**
	The following methods allow to handle the action displayed by the buttons
*/
void MainWindow::handleAddButton(){
	bool ok;
    QString text = QInputDialog::getText(mainWid, tr("Adding a Activity List - I"),
                                         tr("Activity List name:"), QLineEdit::Normal,
                                         QDir::home().dirName(), &ok);
    if (ok && !text.isEmpty()){
    	std::string name = text.toUtf8().constData();
    	text = QInputDialog::getText(mainWid, tr("Adding a Activity List - II"),
                                         tr("Activity List Description:"), QLineEdit::Normal,
                                         QDir::home().dirName(), &ok);
       	std::string desc = text.toUtf8().constData();
       	std::shared_ptr<ActivityList> ptr( new ActivityList(name, desc) );
       	userController->addList(ptr);
	}
}


void MainWindow::handleRemoveButton(){
	QList<QListWidgetItem *> selected = listWidget->selectedItems();
	for(auto it : selected){
		if(it->text() != QString::fromStdString("Important Tasks")){
			alw->setActivityList(user->getActivityLists().at(0));
			userController->removeList(it->text().toUtf8().constData());
		}else{
			QMessageBox::about(this, "Impossible delete Activity List", "Impossible delete this Activity List");
		}
	}
	
}

void MainWindow::handleChangeSelectedItem(){
	//get the first selected item
	if( listWidget->selectedItems().size() > 0){
		std::string selected = listWidget->selectedItems().at(0)->text().toUtf8().constData();
		for(auto it : user->getActivityLists()){
			if(it->getName() == selected){
				alw->setActivityList(it);
				break;
			}
		}
	}
}


void MainWindow::closeEvent (QCloseEvent *event){
	QMessageBox::StandardButton resBtn = QMessageBox::question( this, tr("Minarelli Tranchino Calendar"),
                                                                tr("Are you sure?\n"),
                                                                QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
                                                                QMessageBox::Yes);
    if (resBtn != QMessageBox::Yes) {
        event->ignore();
    } else {
    	userController->onClose();
        event->accept();
    }

}

/**
	Method that allows to set up the graphical components
*/
void MainWindow::setupUI(){
	this->resize( 1500, 500 );
    createList();
    
	leftLayout->addWidget(listWidget);
    leftLayout->addWidget(addButton);
    leftLayout->addWidget(removeButton);
    leftLayout->addWidget(showButton); 
    mainLayout->addLayout(leftLayout);
    
	mainLayout->addWidget(alw);
   	
   	
   	mainWid->setLayout(mainLayout);
   	this->setCentralWidget(mainWid);
}

void MainWindow::update(){
	createList();
}

/**
	Method that allows to create the list which contains all the ActivityLists names
*/
void MainWindow::createList(){
	listWidget->clear();
	for(auto it : user->getActivityLists()){
		listWidget->addItem( QString::fromStdString(it->getName()) );
	}
}
