#include<QStringList>
#include<QTreeWidgetItem>
#include<QMessageBox>
#include <iostream>

#include "ActivityListWidget.h"
#include "CommitmentDialog.h"

/**
	Constructor of the class
	@param al: the ActivityList that the widget displays
	@param parent: the parent of this widget
*/
ActivityListWidget::ActivityListWidget(std::shared_ptr<ActivityList> al, std::shared_ptr<ActivityListController> alc, std::shared_ptr<User> u, QWidget *parent) : activities(al), activityController(alc), user(u), QWidget(parent){
	treeView = new QTreeWidget;
	fillTree();
	addButton = new QPushButton("Add a task");
	removeButton = new QPushButton("Remove a task");
	importantButton = new QPushButton("Add to Important Task");
	titleLabel = new QLabel( QString::fromStdString( activities->getName() ) );
	descLabel = new QLabel( QString::fromStdString( activities->getDescription() ) );
	titleLabel->setAlignment(Qt::AlignCenter);
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
	if(activities->getName() != "Important Tasks" ){
		importantButton->setVisible(true);
	}else if(activities->getName() == "Important Tasks" && importantButton != nullptr){
		importantButton->setVisible(false);
	}
	titleLabel->setText( QString::fromStdString( activities->getName() ) );
	descLabel->setText (  QString::fromStdString( activities->getDescription() ) );
}

/**
	Method that set up the listeners, in order to use the GUI
*/
void ActivityListWidget::setupListeners(){
	connect(addButton, SIGNAL (released()), this, SLOT (handleAddButton()));
	connect(removeButton, SIGNAL (released()), this, SLOT (handleRemoveButton()));
	connect(treeView, SIGNAL(itemDoubleClicked(QTreeWidgetItem *, int)), this, SLOT(handleChangeSelectedItem(QTreeWidgetItem *, int)));
	connect(importantButton, SIGNAL(released()), this, SLOT(handleImportantButton()));
}

/**
	Method that fill the tree with the datas of the ActivityList's Commitments
*/
void ActivityListWidget::fillTree(){
	treeView->clear();
	treeView->setItemsExpandable(false) ;
	treeView->setHeaderLabels(QStringList() << "Status" << "Notes " << "Start Date" << "Start Time" << "End Date" << "End Time" << "Url" << "Place"); 
	Date tod = Date::today();
	
	for(auto it : activities->getCommitments() ){
		QTreeWidgetItem *treeItem = new QTreeWidgetItem();
		if(tod < it.second.getStartDate()  ){
			treeItem->setText(0,  "To do" );
			treeItem->setForeground(0, QBrush( QColor(Qt::green) ) ) ;
		}else if (it.second.getEndDate() < tod ){
			treeItem->setText(0,  "Passed");
			treeItem->setForeground(0, QBrush( QColor(Qt::red) ) ) ;
		}else if(it.second.getStartDate() < tod && tod < it.second.getEndDate() ){
			treeItem->setText(0, "To do now" );
			treeItem->setForeground(0, QBrush( QColor(Qt::blue) ) ) ;
		}
		treeItem->setText(1,  QString::fromStdString (it.second.getNotes()) );
		treeItem->setText(2,  QString::fromStdString (it.second.getStartDate().toString() ) );
		treeItem->setText(3,  QString::fromStdString (it.second.getStartTime().toString() ) );
		treeItem->setText(4,  QString::fromStdString (it.second.getEndDate().toString() ) );
		treeItem->setText(5,  QString::fromStdString (it.second.getEndTime().toString() ) );
		treeItem->setText(6,  QString::fromStdString (it.second.getUrl()) );
		treeItem->setText(7,  QString::fromStdString (it.second.getPlace()) );
		
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
	mainLayout->addWidget(titleLabel);
	mainLayout->addWidget(descLabel);
	mainLayout->addWidget(treeView);
	underLayout->addWidget(addButton);
	underLayout->addWidget(removeButton);
	underLayout->addWidget(importantButton);
	importantButton->setVisible(false);
	mainLayout->addLayout(underLayout);
	this->setLayout(mainLayout);
}


ActivityListWidget::~ActivityListWidget(){
	activities->detach(this);
}

QSize ActivityListWidget::sizeHint() const{
	return QSize(100, 110);
}

/**
	The following methods allow to handle the action displayed by the buttons
*/
void ActivityListWidget::handleAddButton(){
	CommitmentDialog dialog(this);
	if(dialog.exec() == QDialog::Accepted){
		activityController->add( dialog.getInsertedCommitment() );
	}
}


void ActivityListWidget::handleRemoveButton(){
	QList <QTreeWidgetItem *> items = treeView->selectedItems();
	if(items.size() > 0){
		for(auto it : items){
			//the commitment that will be deleted is reconstructed using the data inside the cells 
		
			Commitment c(Date::fromString(it->text(2).toUtf8().constData() ), //start date
						Date::fromString( it->text(4).toUtf8().constData() ), //end date
						Time::fromString( it->text(3).toUtf8().constData() ), //start time
						Time::fromString( it->text(5).toUtf8().constData() ), //end time
						false, //repeat
						it->text(1).toUtf8().constData() , //notes
						it->text(6).toUtf8().constData(), //url
						it->text(7).toUtf8().constData() //place
						);
			activityController->remove(c); 
		}
	}
}

void ActivityListWidget::handleChangeSelectedItem(QTreeWidgetItem * selected, int col){
		QMessageBox::about( this, "Commitment data", 
					"Start Date: " + selected->text(1) + " <br>" +
					"Start Time: " + selected->text(2) + " <br>" +
					"End Date: " + selected->text(3) + " <br>" +
					"End Time: " + selected->text(4) + " <br>" +
					"Notes: " + selected->text(0) + " <br>" +
					"URL: <a href=" + selected->text(5) + ">" + selected->text(5) + "</a> <br>" +
					"Place: " + selected->text(6) + " <br>"
					 
		);
	
}


void ActivityListWidget::handleImportantButton(){

	if(treeView->selectedItems().size() > 0){
		QTreeWidgetItem *selected = treeView->selectedItems().at(0);
		Commitment c(Date::fromString( selected->text(1).toUtf8().constData() ), //start date
						Date::fromString( selected->text(3).toUtf8().constData() ), //end date
						Time::fromString( selected->text(2).toUtf8().constData() ), //start time
						Time::fromString( selected->text(4).toUtf8().constData() ), //end time
						false, //repeat
						selected->text(0).toUtf8().constData() , //notes
						selected->text(5).toUtf8().constData(), //url
						selected->text(6).toUtf8().constData() //place
						);
		// adds the Commitment to the user important tasks 
		user->getActivityLists().at(0)->addCommitment(c);
	}
}
