#include<QStringList>
#include<QGridLayout>

#include "MainWindow.h"

MainWindow::MainWindow(std::shared_ptr<User> u) : user(u){
	setWindowTitle("Minarelli Tranchino Calendar");
	alw = new ActivityListWidget(user->getActivityLists()[0]);
   	setupUI();
}

MainWindow::~MainWindow(){
	delete ui;
}

void MainWindow::setupUI(){
	this->resize( 500, 200 );
    QVBoxLayout* leftLayout = new QVBoxLayout;
    QHBoxLayout* mainLayout = new QHBoxLayout;
    listWidget = new QListWidget;
    createList();
	// First Column
	addButton = new QPushButton("Add Activity List");
	removeButton = new QPushButton("Remove Activity List");
    leftLayout->addWidget(listWidget);
    leftLayout->addWidget(addButton);
    leftLayout->addWidget(removeButton); 
    mainLayout->addLayout(leftLayout);
    
	setCentralWidget(alw);
   	
   	this->setLayout(mainLayout);
}

void MainWindow::createList(){
	for(auto it : user->getActivityLists()){
		listWidget->addItem( QString::fromStdString(it->getName()) );
	}
}
