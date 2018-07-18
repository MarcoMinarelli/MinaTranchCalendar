#ifndef ACTIVITY_LIST_WIDGET_H
#define ACTIVITY_LIST_WIDGET_H

#include <QWidget>
#include <QTableWidget>
#include <QPushButton>

#include "ActivityList.h"

class ActivityListWidget : public QWidget{
	Q_OBJECT

public:
	ActivityListWidget(ActivityList al, QWidget *parent = 0);		
	~ActivityListWidget() {}
	
	bool insertCommitment();
	bool removeCommitments();
	
private:

	void setupUI();
	void fillTable();


	ActivityList activities;
	QTableWidget table;
	QPushButton addButton;
	QPushButton removeButton;

}
#endif
