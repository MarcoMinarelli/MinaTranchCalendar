#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <vector>

#include <QMainWindow>
#include <QPushButton>
#include <QScrollArea>


#include "User.h"
#include "ActivityListWidget.h"

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    MainWindow(User u, QWidget *parent = 0);
	~MainWindow();
private slots:


private:
	void setupUI();
	void createButtons();
	
	ActivityListWidget alw;
	std::vector<QPushButton *> buttons;
	QScrollArea* scrollArea;
	MainWindow *ui;
	User user;
};


#endif
