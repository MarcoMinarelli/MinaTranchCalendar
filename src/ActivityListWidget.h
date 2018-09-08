#ifndef ACTIVITY_LIST_WIDGET_H
#define ACTIVITY_LIST_WIDGET_H

#include <memory>

#include <QWidget>
#include <QTreeWidget>
#include <QPushButton>
#include <QSize>
#include <QBoxLayout>
#include <QLabel>

#include "ActivityList.h"
#include "ActivityListController.h"
#include "User.h"

class ActivityListWidget : public QWidget, Observer{
	Q_OBJECT

public:
	ActivityListWidget(std::shared_ptr<ActivityList> al, std::shared_ptr<ActivityListController> alc , std::shared_ptr<User> u, QWidget *parent = 0);		
	~ActivityListWidget();
	
	void setActivityList(std::shared_ptr<ActivityList> al); 	
	bool insertCommitment();
	bool removeCommitments();
	
	QSize sizeHint() const;
	
	virtual void update() override;
	
private slots:
	void handleAddButton();
	void handleRemoveButton();
	void handleImportantButton();
	void handleChangeSelectedItem(QTreeWidgetItem * item, int col);
	
private:

	void setupUI();
	void setupListeners();
	void fillTree();

	
	std::shared_ptr<ActivityList> activities;
	std::shared_ptr<ActivityListController> activityController;
	std::shared_ptr<User> user;
	
	QLabel* titleLabel;
	QLabel* descLabel;
	QTreeWidget* treeView;
	QPushButton* addButton;
	QPushButton* removeButton;
	QPushButton* importantButton;
	QVBoxLayout* mainLayout;
	QHBoxLayout* underLayout;
};
#endif
