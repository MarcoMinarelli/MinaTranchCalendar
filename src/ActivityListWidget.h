#ifndef ACTIVITY_LIST_WIDGET_H
#define ACTIVITY_LIST_WIDGET_H

#include <memory>

#include <QWidget>
#include <QTreeWidget>
#include <QPushButton>

#include "ActivityList.h"

class ActivityListWidget : public QWidget{
	Q_OBJECT

public:
	ActivityListWidget(std::shared_ptr<ActivityList> al, QWidget *parent = 0);		
	~ActivityListWidget() { delete ui; }
	
	bool insertCommitment();
	bool removeCommitments();
	
private:

	void setupUI();
	void fillTree();

	
	std::shared_ptr<ActivityList> activities;
	QTreeWidget* treeView;
	QPushButton* addButton;
	QPushButton* removeButton;
	ActivityListWidget *ui;

};
#endif
