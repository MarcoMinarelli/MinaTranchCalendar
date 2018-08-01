#include<QStringList>

#include "MainWindow.h"

MainWindow::MainWindow(User u, QWidget *parent) : user(u), QMainWindow(parent){
	setWindowTitle("Minarelli Tranchino Calendar");
	ActivityListWidget alw(user.getActivityLists()[0]);
   	setupUI();
}

MainWindow::~MainWindow(){
	delete ui;
}

void MainWindow::setupUI(){
	this->resize( 500, 200 );
    QGridLayout leftLayout;
    QGridLayout mainLayout;
	// First Column
	addButton = new QPushButton("Add Activity List");
	removeButton = new QPushButton("Remove Activity List");
    listModel->setStringList(createList());
    leftLayout.addWidget(listModel, 1, 1);
    leftLayout.addWidget(addButton, 2, 1)
    leftLayout.addWidget(removeButton, 2, 2); 
    mainLayout.addLayout(leftLayout, 1, 1);
    
    mainLayout.addWidget(alw, 1, 2);
   	
   	setLayout(mainLayout);
}

void MainWindow::createList(){
	QStringList list;
	for(auto it : user.getActivityLists()){
		list << it->getName();
	}
}
