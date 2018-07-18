#include<QGridLayout>

#include"BorderLayout.h"
#include "ActivityListWidget.h"


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
		table.setItem   ( table.rowCount()-1,  0, new QTableWidgetItem(item));
	}
}



void ActivityListWidget::setupUI(){
	BorderLayout mainLayout;
	QGridLayout underLayout;
	mainLayout.addWidget(table,BorderLayout::Center);
	underLayout.addWidget(addButton, 1, 0);
	underLayout.addWidget(removeButton, 2, 0);
	mainLayout.addLayout(underLayout, BorderLayout::South);
	setLayout(mainLayout);
}


bool ActivityListWidget::insertCommitment(){
	//TODO get new Commitment data, then create the Commitment object, add it to ActivityList via addCommitment(...) method and then  
	// call again fillTable()
}

bool ActivityListWidget::removeCommitments(){
	QList <QTableWidgetItem *> items = table.selectedItems();

 	//TODO get the row to delete, create the Commitment object and delete it from the ActivityList via removeCommitment(...)
 }
