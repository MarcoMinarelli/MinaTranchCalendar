#include<QGridLayout>
#include<QStringList>
#include<QTreeWidgetItem>

#include "ActivityListWidget.h"


ActivityListWidget::ActivityListWidget(std::shared_ptr<ActivityList> al, QWidget *parent) : activities(al){
	fillTree();
	QPushButton addButton("Add a task");
	QPushButton removeButton("Remove a task");
	setupUI();
}

void ActivityListWidget::fillTree(){
	treeView.setItemsExpandable(false) ;
	treeView.setHeaderLabels(QStringList() << "Note " << "Start Date" << "Start Time" << "End Date" << "End Time" << "Url"); 
	for(auto it : activities->getCommitments() ){
		QTreeWidgetItem *treeItem = new QTreeWidgetItem();

		treeItem->setText(0,  QString::fromStdString (it.second.getNotes()) );
		treeItem->setText(1,  QString::fromStdString (it.second.getStartDate().toString() ) );
		treeItem->setText(2,  QString::fromStdString (it.second.getStartTime().toString() ) );
		treeItem->setText(3,  QString::fromStdString (it.second.getEndDate().toString() ) );
		treeItem->setText(4,  QString::fromStdString (it.second.getEndTime().toString() ) );
		treeItem->setText(5,  QString::fromStdString (it.second.getUrl()) );
		
		treeView.addChild(treeItem);
		delete treeItem;
	}
}



void ActivityListWidget::setupUI(){
	QGridLayout mainLayout;
	QGridLayout underLayout;
	mainLayout.addWidget(treeView, 1, 1);
	underLayout.addWidget(addButton, 1, 0);
	underLayout.addWidget(removeButton, 2, 0);
	mainLayout.addLayout(&underLayout, 2, 1);
	setLayout(mainLayout);
}


bool ActivityListWidget::insertCommitment(){
	//TODO get new Commitment data, then create the Commitment object, add it to ActivityList via addCommitment(...) method and then  
	// call again fillTable()
}

bool ActivityListWidget::removeCommitments(){
	QList <QTreeWidgetItem *> items = treeView.currentItems();

 	//TODO get the row to delete, create the Commitment object and delete it from the ActivityList via removeCommitment(...)
 }
