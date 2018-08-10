#include<QGridLayout>
#include<QStringList>
#include<QTreeWidgetItem>

#include "ActivityListWidget.h"


/**
	Constructor of the class
	@param al: the ActivityList that the widget displays
	@param parent: the parent of this widget
*/
ActivityListWidget::ActivityListWidget(std::shared_ptr<ActivityList> al, QWidget *parent) : activities(al), QWidget(parent){
	treeView = new QTreeWidget;
	fillTree();
	addButton = new QPushButton("Add a task");
	removeButton = new QPushButton("Remove a task");
	showButton = new QPushButton("Show selected task");
	al->attach(this);
	setupUI();
}

/**
	Method that allows to set the ActivityList that is displayed
	@param al: The ActivityList to show
*/
void ActivityListWidget::setActivityList(std::shared_ptr<ActivityList> al){
	this-> activities = al;
	fillTree();
}

/**
	Method that set up the listeners, in order to use the GUI
*/
void ActivityListWidget:setupListeners(){
	connect(addButton, SIGNAL (released()), this, SLOT (handleAddButton()));
	connect(removeButton, SIGNAL (released()), this, SLOT (handleRemoveButton()));
	connect(showButton, SIGNAL(released()), this, SLOT(handleChangeSelectedItem()));
}
}

/**
	Method that fill the tree with the datas of the ACtivityList's Commitments
*/
void ActivityListWidget::fillTree(){
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
	fillTree();
}

/**
	Method that allows to set up the graphical components
*/
void ActivityListWidget::setupUI(){
	QVBoxLayout *mainLayout = new QGridLayout;
	QHBoxLayout *underLayout = new QGridLayout;
	mainLayout->addWidget(treeView, 1, 1);
	underLayout->addWidget(addButton, 1, 0);
	underLayout->addWidget(removeButton, 2, 0);
	underLayout->addWidget(showButton, 2, 0);
	mainLayout->addLayout(underLayout, 2, 1);
	this->setLayout(mainLayout);
}


ActivityListWidget::~ActivityListWidget(){
	delete treeView;
	delete removeButton;
	delete addButton;
	delete ui;
}

QSize ActivityListWidget::sizeHint() const{
	return QSize(100, 110);
}

/**
	The following methods allow to handle the action displayed by the buttons
*/
void MainWindow::handleAddButton(){
	//TODO get new Commitment data, then create the Commitment object, add it to ActivityList via addCommitment(...) method and then  
	// call again fillTable()
}


void MainWindow::handleRemoveButton(){
	QList <QTreeWidgetItem *> items = treeView->selectedItems();
	for(auto it : selected){
		//the commitment that will be deleted is reconstructed using the data inside the cells

		Commitment c(Date.fromString(it->text(1)) , //start date
					Date.fromString( it->text(3)) , //end date
					Time.fromString( it->text(2)) , //start time
					Time.fromString( it->text(4)) , //end time
					false, //repeat
					it->text(0) , //notes
					it->text(5) //url
					);
		//calls activityListController->remove(c);
	}
}

void MainWindow::handleChangeSelectedItem(){
	//get the first selected item
	std::string selected = listWidget->selectedItems().at(0)->text().toUtf8().constData();
	
	for(auto it : user->getActivityLists()){
		
	}
}

