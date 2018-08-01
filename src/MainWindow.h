#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <vector>
#include <memory>
#include <QMainWindow>
#include <QPushButton>
#include <QScrollArea>
#include <QStringListModel>

#include "User.h"
#include "ActivityListWidget.h"

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    MainWindow(std::shared_ptr<User> u, QWidget *parent = 0);
	~MainWindow();
private slots:


private:
	void setupUI();
	void createList();
	
	ActivityListWidget alw;
	QStringListModel *listModel;
	QPushButton *addButton;
	QPushButton *removeButton;
	MainWindow *ui;
	std::shared_ptr<User> user;
};


#endif
