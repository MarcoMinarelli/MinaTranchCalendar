#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <vector>
#include <memory>

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QListWidget>
#include <QCloseEvent>
#include <QBoxLayout>

#include "User.h"
#include "UserController.h"
#include "ActivityListWidget.h"
#include "Observer.h"

class MainWindow : public QMainWindow, Observer{
    Q_OBJECT

public:
    explicit MainWindow(std::shared_ptr<User> u, std::shared_ptr<UserController> uc);
	~MainWindow();
	
	virtual void closeEvent (QCloseEvent *event) override;
	virtual void update() override;
	
private slots:
	void handleAddButton();
	void handleRemoveButton();
	void handleChangeSelectedItem(QListWidgetItem * item);
	
private:
	void setupUI();
	void createList();
	void setupListeners();
	
	ActivityListWidget *alw;
	QListWidget *listWidget;
	QPushButton *addButton;
	QPushButton *removeButton;
	QWidget *mainWid;
	QVBoxLayout* leftLayout;
	QHBoxLayout* mainLayout;
	
	
	std::shared_ptr<User> user;
	std::shared_ptr<ActivityList> acList;
	std::shared_ptr<ActivityList> impList;
	std::shared_ptr<UserController> userController;
};


#endif
