#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <vector>
#include <memory>
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QListWidget>

#include "User.h"
#include "UserController.h"
#include "ActivityListWidget.h"
#include "Observer.h"

class MainWindow : public QMainWindow, Observer{
    Q_OBJECT

public:
    MainWindow(std::shared_ptr<User> u, std::shared_ptr<UserController> uc);
	~MainWindow();
	
	virtual void update() { };//TODO give correct implementation
private slots:


private:
	void setupUI();
	void createList();
	
	ActivityListWidget *alw;
	QListWidget *listWidget;
	QPushButton *addButton;
	QPushButton *removeButton;
	QLabel *commitLabel;
	MainWindow *ui;
	
	
	std::shared_ptr<User> user;
	std::shared_ptr<UserController> userController;
};


#endif
