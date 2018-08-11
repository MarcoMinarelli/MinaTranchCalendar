#include<iostream>

#include<QStringList>
#include<QGridLayout>
#include<QLineEdit>
#include<QDir>
#include<QInputDialog>

#include "MainWindow.h"

/**
	Costructor
	@param u: the user whose ActivityLists and tasks will be shown
	@param us: the controller 
*/
MainWindow::MainWindow(std::shared_ptr<User> u, std::shared_ptr<UserController> uc) : user(u), userController(uc){
	setWindowTitle("Minarelli Tranchino Calendar");
	std::shared_ptr<ActivityListController> alc(new ActivityListController(user->getActivityLists()[1]));
	alw = new ActivityListWidget(user->getActivityLists()[1], alc);
	listWidget = new QListWidget;
	addButton = new QPushButton("Add Activity List");
	removeButton = new QPushButton("Remove Activity List");
	showButton = new QPushButton("Show Activity List");
	mainWid = new QWidget;
	user->attach(this);
   	setupUI();
   	setupListeners();
}

MainWindow::~MainWindow(){
	delete alw;
	delete listWidget;
	delete addButton;
	delete removeButton;
	user->detach(this);
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
		userController->removeList(it->text().toUtf8().constData());
	}
	
}

void MainWindow::handleChangeSelectedItem(){
	//get the first selected item
	std::string selected = listWidget->selectedItems().at(0)->text().toUtf8().constData();
	
	for(auto it : user->getActivityLists()){
		if(it->getName() == selected){
			alw->setActivityList(it);
			break;
		}
	}
}

/**
	Method that allows to set up the graphical components
*/
void MainWindow::setupUI(){
	this->resize( 1500, 500 );
    QVBoxLayout* leftLayout = new QVBoxLayout;
    QHBoxLayout* mainLayout = new QHBoxLayout;
    createList();
	// First Column
	leftLayout->addWidget(listWidget);
    leftLayout->addWidget(addButton);
    leftLayout->addWidget(removeButton);
    leftLayout->addWidget(showButton); 
    mainLayout->addLayout(leftLayout);
    
	mainLayout->addWidget(alw);
	
   	//mainLayout->addWidget(commitLabel);
   	
   	this->setCentralWidget(mainWid);
   	mainWid->setLayout(mainLayout);
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
