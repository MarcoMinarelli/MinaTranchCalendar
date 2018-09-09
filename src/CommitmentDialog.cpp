#include <QErrorMessage>
#include<QMessageBox>

#include <iostream>
#include "CommitmentDialog.h"
#include "Time.h"
#include "Date.h"

CommitmentDialog::CommitmentDialog( QWidget *parent) : QDialog(parent), toReturn(Date(1, 1, 2001), Date(2, 2, 2002), Time(3, 3, 03), Time(4, 4, 04), false, " ", " ", " "  ){

	
	noteLabel = new QLabel("Note of the Commitment");
   	urlLabel = new QLabel("URL of the Commitment");
   	placeLabel = new QLabel("Place");
    startLabel = new QLabel("Start Date of the Commitment");
    endLabel = new QLabel("End Date of the Commitment");
    startTimeLabel = new QLabel("Start Time of the Commitment");
    endTimeLabel = new QLabel("End Time of the Commitment");
    
    noteEdit = new QLineEdit;
    urlEdit = new QLineEdit;
    placeEdit = new QLineEdit;
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
    
    dateValidator = new QRegExpValidator( QRegExp("^(?:[012][0-9]):(?:[012345]\\d):?(?:[012345]\\d)?$"), this );
    urlValidator = new QRegExpValidator ( QRegExp("^(http::\\/\\/|https\\/\\/)?www\\.[\\w]+\\.[a-z]{2,3}(\\/\\w*)?$"), this); 
    
    
    startTimeEdit->setValidator(dateValidator);
    endTimeEdit->setValidator(dateValidator);
    
    urlEdit->setValidator(urlValidator);
    buttonBox = new QDialogButtonBox(QDialogButtonBox::Help | QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    
	setupUi();
	setupListeners();
	setWindowTitle("Input a Commitment");
}

void CommitmentDialog::verify(){
	try{
		if(noteEdit->text().isEmpty()){
			QMessageBox::warning(this, tr("Error"), tr( "The Commitment Note is empty" ));
		}else if(urlEdit->text().isEmpty()){
			QMessageBox::warning(this, tr("Error"), tr( "The Commitment URL is empty" ));
		}else if(startTimeEdit->text().isEmpty()){
			QMessageBox::warning(this, tr("Error"), tr( "The Start Time is empty" ));
		}else if(endTimeEdit->text().isEmpty()){
			QMessageBox::warning(this, tr("Error"), tr( "The End Time is empty" ));
		}else{
			Date start(startCal->selectedDate().day(), startCal->selectedDate().month(), startCal->selectedDate().year());
			Date end(endCal->selectedDate().day(), endCal->selectedDate().month(), endCal->selectedDate().year());
			if(startTimeEdit->text().size() == 5){
				startTimeEdit->setText(startTimeEdit->text().append(":00"));
			}
			if(endTimeEdit->text().size() == 5){
				endTimeEdit->setText(endTimeEdit->text().append(":00"));
			}
			Time startT = Time::fromString(startTimeEdit->text().toUtf8().constData());
			Time endT = Time::fromString(endTimeEdit->text().toUtf8().constData());
			std::string note = noteEdit->text().toUtf8().constData();
			std::string url = urlEdit->text().toUtf8().constData();
			std::string place = placeEdit->text().toUtf8().constData();
			Commitment c(start, end, startT, endT, false, note, url, place );
			this->toReturn = c;
			accept();
		    return;
        }
	}catch(std::runtime_error &e){
		std::string errorMex = "Error in some fields ";
		errorMex.append( e.what() );
		QMessageBox::warning(this, tr("Error"), QString::fromStdString(errorMex) );
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
	delete placeLabel;
	delete placeEdit;
	delete startLabel;
	delete startCal;
	delete endLabel;
	delete endCal;
	delete startTimeLabel;
	delete startTimeEdit;
	delete endTimeLabel;
	delete endTimeEdit;
	delete buttonBox;
	delete dateValidator;
	delete urlValidator;
}

void CommitmentDialog::setupUi(){
	QGridLayout *mainLayout = new QGridLayout;
	mainLayout->addWidget(noteLabel, 1, 0);
	mainLayout->addWidget(noteEdit, 1, 1);
	mainLayout->addWidget(urlLabel, 2, 0);
	mainLayout->addWidget(urlEdit, 2, 1);
	mainLayout->addWidget(placeLabel, 3, 0);
	mainLayout->addWidget(placeEdit, 3, 1);
	mainLayout->addWidget(startLabel, 4, 0);
	mainLayout->addWidget(startCal, 4, 1);
	mainLayout->addWidget(endLabel, 5, 0);
	mainLayout->addWidget(endCal, 5, 1);
	mainLayout->addWidget(startTimeLabel, 6, 0);
	mainLayout->addWidget(startTimeEdit, 6, 1);
	mainLayout->addWidget(endTimeLabel, 7, 0);
	mainLayout->addWidget(endTimeEdit, 7, 1);
	mainLayout->addWidget(buttonBox, 8, 0, 8, 1);
	this->setLayout(mainLayout);	

}

Commitment CommitmentDialog::getInsertedCommitment(){
	return toReturn;
}

void CommitmentDialog::help(){
	QMessageBox::about (
		this,
		QString::fromStdString("Time input"),
		QString::fromStdString("The Time format used is \n HH:MM:SS \n \n And the URL is in format \n www.someurl.someExt") );
}
