#include<QStringList>
#include<QGridLayout>

#include "MainWindow.h"

MainWindow::MainWindow(std::shared_ptr<User> u, std::shared_ptr<UserController> uc) : user(u), userController(uc){
	setWindowTitle("Minarelli Tranchino Calendar");
	alw = new ActivityListWidget(user->getActivityLists()[1]);
	listWidget = new QListWidget;
	commitLabel = new QLabel("Here the events datas will be shown");
	addButton = new QPushButton("Add Activity List");
	removeButton = new QPushButton("Remove Activity List");
   	setupUI();
}

MainWindow::~MainWindow(){
	delete ui;
}

void MainWindow::setupUI(){
	this->resize( 1000, 500 );
	QWidget *mainWid = new QWidget;
    QVBoxLayout* leftLayout = new QVBoxLayout;
    QHBoxLayout* mainLayout = new QHBoxLayout;
    createList();
	// First Column
	leftLayout->addWidget(listWidget);
    leftLayout->addWidget(addButton);
    leftLayout->addWidget(removeButton); 
    mainLayout->addLayout(leftLayout);
    
	mainLayout->addWidget(alw);
	
   	mainLayout->addWidget(commitLabel);
   	
   	this->setCentralWidget(mainWid);
   	mainWid->setLayout(mainLayout);
}

void MainWindow::createList(){
	for(auto it : user->getActivityLists()){
		listWidget->addItem( QString::fromStdString(it->getName()) );
	}
}
