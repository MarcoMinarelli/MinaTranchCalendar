#include<QGridLayout>


#include "ActivityListWidget.h"

const int numColumns = 6; 

ActivityListWidget::ActivityListWidget(ActivityList al, QWidget *parent = 0) : activities(al){
	fillTable();
	QButton addButton("Add a task");
	QButton removeButton("Remove a task");
	setupUI();
}

void ActivityListWidget::fillTable(){
	for(auto it : al){
		string item = it->second.getNote() + " " + it->second.getStartDate() + " " + it->second.getStartTime() + " " + it->second.getStartTime()+ " " + it->second.getEndDate() + " " + it->second.getEndTime() + " " + it->second.getUrl();
		
		table.insertRow ( table.rowCount() );
		table.setItem   ( table.rowCount()-1,  0, new QTableWidgetItem());
	}
}



void ActivityListWidget::setupUI(){
	QGridLayout layout;
	layout.addWidget(table, 0, 0);
	layout.addWidget(addButton, 2, 0);
	layout.addWidget(removeButton, 2, 2);
}


bool ActivityListWidget::insertRows(int position, int rows, const QModelIndex &index = QModelIndex()) override{
	//TODO get new Commitment data, then create the Commitment object, add it to ActivityList via addCommitment(...) method and then  
	// call again fillTable()
}

bool ActivityListWidget::removeRows(int position, int rows, const QModelIndex &index = QModelIndex()) override{
	QList <QTableWidgetItem *> items = table.selectedItems();

 	//TODO get the row to delete, create the Commitment object and delete it from the ActivityList via removeCommitment(...)
 }
