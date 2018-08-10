#ifndef ACTIVITY_LIST_WIDGET_H
#define ACTIVITY_LIST_WIDGET_H

#include <memory>

#include <QWidget>
#include <QTreeWidget>
#include <QPushButton>
#include <QSize>

#include "ActivityList.h"

class ActivityListWidget : public QWidget, Observer{
	Q_OBJECT

public:
	ActivityListWidget(std::shared_ptr<ActivityList> al, QWidget *parent = 0);		
	~ActivityListWidget();
	
	void setActivityList(std::shared_ptr<ActivityList> al); 	
	bool insertCommitment();
	bool removeCommitments();
	
	QSize sizeHint() const;
	
	virtual void update() override;
	
private slots:
	void handleAddButton();
	void handleRemoveButton();
	void handleChangeSelectedItem();
	
private:

	void setupUI();
	void setupListeners();
	void fillTree();

	
	std::shared_ptr<ActivityList> activities;
	QTreeWidget* treeView;
	QPushButton* addButton;
	QPushButton* removeButton;
	QPushButton* showButton;
	ActivityListWidget *ui;

};
#endif
