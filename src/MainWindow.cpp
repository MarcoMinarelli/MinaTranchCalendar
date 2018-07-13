#include "MainWindow.h"

MainWindow::MainWindow(User u, QWidget *parent) : user(u), QMainWindow(parent){
	setWindowTitle("Minarelli Tranchino Calendar");
   	setupUI();
}

MainWindow::~MainWindow(){
	delete ui;
}

void MainWindow::setupUI(){
	this->resize( 500, 200 );
    scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable( true );
    //layout->addWidget( scrollArea );
    //auto * container = new QWidget();
    //scrollArea->setWidget( container );
   	
}

void MainWindow::createButtons(){
	int i = 0;
	int lastPos = 10;
	for(auto it : user.getActivityLists()){
		buttons.push_back(new QPushButton(it->getName()));
		buttons[i] -> setGeometry (QRect (50, lastPos+=20, 113, 20));
	}
}
