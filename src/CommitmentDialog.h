#ifndef COMMITMENT_DIALOG_H
#define COMMITMENT_DIALOG_H


#include <QDialog>
#include <QLabel>
#include <QDialogButtonBox>
#include <QCalendarWidget>
#include <QGridLayout>
#include <QRegExpValidator> 
#include <QLineEdit>


#include "Commitment.h"

class CommitmentDialog : public QDialog{
	Q_OBJECT
	
public:
    CommitmentDialog(QWidget *parent);
	~CommitmentDialog();

	Commitment getInsertedCommitment();

public slots:
    void verify();
	void help();

private:

	void setupUi();
	void setupListeners();

 	QLabel *noteLabel;
    QLabel *urlLabel;
    QLabel *placeLabel;
    QLabel *startLabel;
    QLabel *endLabel;
    QLabel *startTimeLabel;
    QLabel *endTimeLabel;
	QDialogButtonBox *buttonBox;
	

	QLineEdit *noteEdit;
	QLineEdit *urlEdit;
	QLineEdit *placeEdit;
	QCalendarWidget *startCal;
	QCalendarWidget *endCal;
	QLineEdit *startTimeEdit;
	QLineEdit *endTimeEdit;
	
	QGridLayout *mainLayout;
	QRegExpValidator *dateValidator;
	QRegExpValidator *urlValidator;
	
	
	Commitment toReturn;
};

#endif
