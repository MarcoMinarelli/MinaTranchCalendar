#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <vector>
#include <memory>
#include <QMainWindow>
#include <QPushButton>
#include <QScrollArea>
#include <QListWidget>

#include "User.h"
#include "ActivityListWidget.h"

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    MainWindow(std::shared_ptr<User> u);
	~MainWindow();
private slots:


private:
	void setupUI();
	void createList();
	
	ActivityListWidget *alw;
	QListWidget *listWidget;
	QPushButton *addButton;
	QPushButton *removeButton;
	MainWindow *ui;
	std::shared_ptr<User> user;
};


#endif
