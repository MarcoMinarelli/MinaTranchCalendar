#ifndef
#define ACTIVITY_LIST_WIDGET_H

#include <QWidget>
#include <QTableWidget>
#include <QPushButton>

#include "ActivityList.h"

class ActivityListWidget{
	Q_OBJECT

public:
	ActivityListWidget(ActivityList al, QWidget *parent = 0);		
	~ActivityListWidget() {}
	bool insertRows(int position, int rows, const QModelIndex &index = QModelIndex()) override;
    bool removeRows(int position, int rows, const QModelIndex &index = QModelIndex()) override;

private:

	void setupUI();
	void fillTable();

	ActivityList activities;
	QTableWidget table;
	QPushButton addButton;
	QPushButton removeButton;

}
#endif
