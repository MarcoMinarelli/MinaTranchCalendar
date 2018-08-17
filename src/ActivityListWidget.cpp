#include<QGridLayout>
#include<QStringList>
#include<QTreeWidgetItem>
#include<QMessageBox>
#include <iostream>

#include "ActivityListWidget.h"


/**
	Constructor of the class
	@param al: the ActivityList that the widget displays
	@param parent: the parent of this widget
*/
ActivityListWidget::ActivityListWidget(std::shared_ptr<ActivityList> al, std::shared_ptr<ActivityListController> alc, QWidget *parent) : activities(al), activityController(alc),  QWidget(parent){
	treeView = new QTreeWidget;
	fillTree();
	addButton = new QPushButton("Add a task");
	removeButton = new QPushButton("Remove a task");
	showButton = new QPushButton("Show selected task");
	activities->attach(this);
	setupUI();
	setupListeners();
}

/**
	Method that allows to set the ActivityList that is displayed
	@param al: The ActivityList to show
*/
void ActivityListWidget::setActivityList(std::shared_ptr<ActivityList> al){
	activities->detach(this);
	this-> activities = al;
	activityController->setActivityList(al);
	activities->attach(this);
	fillTree();
}

/**
	Method that set up the listeners, in order to use the GUI
*/
void ActivityListWidget::setupListeners(){
	connect(addButton, SIGNAL (released()), this, SLOT (handleAddButton()));
	connect(removeButton, SIGNAL (released()), this, SLOT (handleRemoveButton()));
	connect(showButton, SIGNAL(released()), this, SLOT(handleChangeSelectedItem()));
}

/**
	Method that fill the tree with the datas of the ActivityList's Commitments
*/
void ActivityListWidget::fillTree(){
	treeView->clear();
	treeView->setItemsExpandable(false) ;
	treeView->setHeaderLabels(QStringList() << "Notes " << "Start Date" << "Start Time" << "End Date" << "End Time" << "Url"); 
	for(auto it : activities->getCommitments() ){
		QTreeWidgetItem *treeItem = new QTreeWidgetItem();

		treeItem->setText(0,  QString::fromStdString (it.second.getNotes()) );
		treeItem->setText(1,  QString::fromStdString (it.second.getStartDate().toString() ) );
		treeItem->setText(2,  QString::fromStdString (it.second.getStartTime().toString() ) );
		treeItem->setText(3,  QString::fromStdString (it.second.getEndDate().toString() ) );
		treeItem->setText(4,  QString::fromStdString (it.second.getEndTime().toString() ) );
		treeItem->setText(5,  QString::fromStdString (it.second.getUrl()) );
		
		treeView->addTopLevelItem(treeItem);
	}
	
}


void ActivityListWidget::update(){
	this->fillTree();
}

/**
	Method that allows to set up the graphical components
*/
void ActivityListWidget::setupUI(){
	QVBoxLayout *mainLayout = new QVBoxLayout;
	QHBoxLayout *underLayout = new QHBoxLayout;
	mainLayout->addWidget(treeView);
	underLayout->addWidget(addButton);
	underLayout->addWidget(removeButton);
	underLayout->addWidget(showButton);
	mainLayout->addLayout(underLayout);
	this->setLayout(mainLayout);
}


ActivityListWidget::~ActivityListWidget(){
	delete treeView;
	delete removeButton;
	delete addButton;
	delete showButton;
}

QSize ActivityListWidget::sizeHint() const{
	return QSize(100, 110);
}

/**
	The following methods allow to handle the action displayed by the buttons
*/
void ActivityListWidget::handleAddButton(){
	//TODO get new Commitment data, then create the Commitment object, add it to ActivityList via addCommitment(...) method and then  
	// call again fillTable()
}


void ActivityListWidget::handleRemoveButton(){
	QList <QTreeWidgetItem *> items = treeView->selectedItems();
	
	for(auto it : items){
		//the commitment that will be deleted is reconstructed using the data inside the cells 
		
		Commitment c(Date::fromString(it->text(1).toUtf8().constData() ), //start date
					Date::fromString( it->text(3).toUtf8().constData() ), //end date
					Time::fromString( it->text(2).toUtf8().constData() ), //start time
					Time::fromString( it->text(4).toUtf8().constData() ), //end time
					false, //repeat
					it->text(0).toUtf8().constData() , //notes
					it->text(5).toUtf8().constData() //url
					);
		activityController->remove(c); 
	}
}

void ActivityListWidget::handleChangeSelectedItem(){
	//get the first selected item
	QTreeWidgetItem *selected = treeView->selectedItems().at(0);
	QMessageBox::about( this, "Commitment data", 
				"Start Date: " + selected->text(1) + " <br>" +
				"Start Time: " + selected->text(2) + " <br>" +
				"End Date: " + selected->text(3) + " <br>" +
				"End Time: " + selected->text(4) + " <br>" +
				"Notes: " + selected->text(0) + " <br>" +
				"URL: <a href=" + selected->text(5) + ">" + selected->text(5) + " <br>"
	);
}

