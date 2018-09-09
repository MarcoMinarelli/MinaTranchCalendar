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
	impList = user->getActivityLists().at(0);
	
	if(user->getActivityLists().size() >= 2){ //if there are more than one list, the second lsit is taken as counter list
		acList = user->getActivityLists().at(1);
		acList->attach(this);
	}
	
	listWidget = new QListWidget;
	addButton = new QPushButton("Add Activity List");
	removeButton = new QPushButton("Remove Activity List");
	mainWid = new QWidget;
	leftLayout = new QVBoxLayout;
    mainLayout = new QHBoxLayout;
	
	user->attach(this);
	impList->attach(this);
	
	
   	setupUI();
   	setupListeners();
}

MainWindow::~MainWindow(){
	user->detach(this);
	if(acList != nullptr){
		acList->detach(this);
	}
	impList->detach(this);
	//delete alw;
	//delete listWidget;
	//delete addButton;
	//delete removeButton;
	//delete mainWid;
	//delete leftLayout;
	//delete mainLayout;
}

/**
	Method that set up the listeners, in order to use the GUI
*/
void MainWindow::setupListeners(){
	connect(addButton, SIGNAL (released()), this, SLOT (handleAddButton()));
	connect(removeButton, SIGNAL (released()), this, SLOT (handleRemoveButton()));
	connect(listWidget, SIGNAL(itemDoubleClicked(QListWidgetItem *)), this, SLOT(handleChangeSelectedItem(QListWidgetItem *)));
}

/**
	The following methods allow to handle the action displayed by the buttons
*/
void MainWindow::handleAddButton(){
	bool ok;
    QString text = QInputDialog::getText(mainWid, tr("Adding a Activity List - I"),
                                         tr("Activity List name:"), QLineEdit::Normal,
                                         QDir::home().dirName(), &ok);
    if (ok && !text.isEmpty() && !text.contains("(")){
    	std::string name = text.toUtf8().constData();
    	text = QInputDialog::getText(mainWid, tr("Adding a Activity List - II"),
                                         tr("Activity List Description:"), QLineEdit::Normal,
                                         QDir::home().dirName(), &ok);
       	std::string desc = text.toUtf8().constData();
       	std::shared_ptr<ActivityList> ptr( new ActivityList(name, desc) );
       	userController->addList(ptr);
       	if(user->getActivityLists().size() == 2){ //if the new list is the second, then it's taken as counter list
       		acList = ptr;
       	}
	}
}


void MainWindow::handleRemoveButton(){
	if(listWidget->selectedItems().size() > 0){
		QListWidgetItem * selected = listWidget->selectedItems().at(0);
			if(selected->text() != QString::fromStdString("Important Tasks")){
				alw->setActivityList(impList);
				acList->detach(this);
				std::string toDel = selected->text().toUtf8().constData();
				userController->removeList(toDel.substr(0, toDel.find('(')));
			}else{
				QMessageBox::about(this, "Impossible delete Activity List", "Impossible delete this Activity List");
			}
	}
}


void MainWindow::handleChangeSelectedItem(QListWidgetItem * item){
	//get the first selected item
		std::string selected = item->text().toUtf8().constData();
		selected = selected.substr(0, selected.find('('));
		for(auto it : user->getActivityLists()){
			if(it->getName() == selected){
				alw->setActivityList(it);
				if(selected != "Important Tasks"){
					acList->detach(this);
					acList = it;
					acList->attach(this);
				}
				break;
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
		std::string s = it->getName();
		s+="(";
		s+=std::to_string(it->getCommitments().size());
		s+=")";
		listWidget->addItem( QString::fromStdString(s) );
	}
}
