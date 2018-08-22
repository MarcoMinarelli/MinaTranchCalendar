#include <QErrorMessage>
#include<QMessageBox>

#include <iostream>
#include "CommitmentDialog.h"
#include "Time.h"
#include "Date.h"

CommitmentDialog::CommitmentDialog( QWidget *parent) : QDialog(parent), toReturn(Date(1, 1, 2001), Date(2, 2, 2002), Time(3, 3, 03), Time(4, 4, 04), false, " ", " "  ){

	
	noteLabel = new QLabel("Note of the Commitment");
   	urlLabel = new QLabel("URL of the Commitment");
    startLabel = new QLabel("Start Date of the Commitment");
    endLabel = new QLabel("End Date of the Commitment");
    startTimeLabel = new QLabel("Start Time of the Commitment");
    endTimeLabel = new QLabel("End Time of the Commitment");
    
    noteEdit = new QLineEdit;
    urlEdit = new QLineEdit;
    startCal = new QCalendarWidget;
    endCal = new QCalendarWidget;
    startTimeEdit = new QLineEdit;
    endTimeEdit = new QLineEdit;
    
    
    startCal->setMinimumDate(QDate(1900, 1, 1));
    startCal->setMaximumDate(QDate(3000, 1, 1));
    startCal->setGridVisible(true);
    endCal->setMinimumDate(QDate(1900, 1, 1));
    endCal->setMaximumDate(QDate(3000, 1, 1));
    endCal->setGridVisible(true);
    
    val = new QRegExpValidator( QRegExp("(?:[01]\\d|2[0123]):(?:[012345]\\d):(?:[012345]\\d)"), this );
    
    startTimeEdit->setValidator(val);
    endTimeEdit->setValidator(val);
    
    buttonBox = new QDialogButtonBox(QDialogButtonBox::Help | QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    
	setupUi();
	setupListeners();
	setWindowTitle("Input a Commitment");
}

void CommitmentDialog::verify(){
	try{
		Date start(startCal->selectedDate().day(), startCal->selectedDate().month(), startCal->selectedDate().year());
		Date end(endCal->selectedDate().day(), endCal->selectedDate().month(), endCal->selectedDate().year());
		Time startT = Time::fromString(startTimeEdit->text().toUtf8().constData());
		Time endT = Time::fromString(endTimeEdit->text().toUtf8().constData());
		std::string note = noteEdit->text().toUtf8().constData();
		std::string url = urlEdit->text().toUtf8().constData();
		Commitment c(start, end, startT, endT, false, note, url );
		toReturn = c;
		accept();
        return;
	}catch(std::runtime_error &e){
		QErrorMessage error;
		error.showMessage( QString::fromStdString("Error in some fields"));
	}

}

void CommitmentDialog::setupListeners(){
	connect(buttonBox, &QDialogButtonBox::accepted, this, &CommitmentDialog::verify);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &CommitmentDialog::reject);
    connect(buttonBox, &QDialogButtonBox::helpRequested, this, &CommitmentDialog::help);
}

CommitmentDialog::~CommitmentDialog(){
	delete noteLabel;
	delete noteEdit;
	delete urlLabel;
	delete urlEdit;
	delete startLabel;
	delete startCal;
	delete endLabel;
	delete endCal;
	delete startTimeLabel;
	delete startTimeEdit;
	delete endTimeLabel;
	delete endTimeEdit;
	delete buttonBox;
	delete val;
}

void CommitmentDialog::setupUi(){
	QGridLayout *mainLayout = new QGridLayout;
	mainLayout->addWidget(noteLabel, 1, 0);
	mainLayout->addWidget(noteEdit, 1, 1);
	mainLayout->addWidget(urlLabel, 2, 0);
	mainLayout->addWidget(urlEdit, 2, 1);
	mainLayout->addWidget(startLabel, 3, 0);
	mainLayout->addWidget(startCal, 3, 1);
	mainLayout->addWidget(endLabel, 4, 0);
	mainLayout->addWidget(endCal, 4, 1);
	mainLayout->addWidget(startTimeLabel, 5, 0);
	mainLayout->addWidget(startTimeEdit, 5, 1);
	mainLayout->addWidget(endTimeLabel, 6, 0);
	mainLayout->addWidget(endTimeEdit, 6, 1);
	mainLayout->addWidget(buttonBox, 7, 0, 7, 1);
	this->setLayout(mainLayout);	

}

Commitment CommitmentDialog::getInsertedCommitment(){
	return toReturn;
}

void CommitmentDialog::help(){
	QMessageBox::about (
		this,
		QString::fromStdString("Time input"),
		QString::fromStdString("The Time format used is \n HH:MM:SS") );
}
