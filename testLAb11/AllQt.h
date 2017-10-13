#pragma once

#include "Controller.h"

#include <QtWidgets/qmainwindow.h>
#include <qlistwidget.h>
#include <qformlayout.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include<qtextedit.h>
#include <qradiobutton.h>

class AllQt :public QWidget
{
	Q_OBJECT
public:

	AllQt(Controller& c, QWidget *parent = 0);
	~AllQt();

private:

	Controller& ctrl;
	std::vector<TrenchCoat> coatsInRepo;
	std::vector<TrenchCoat> coatsInBasket;
	
	QListWidget* repoList;
	QLineEdit* IDEdit;
	QLineEdit* sizeEdit;
	QLineEdit* lengthEdit;
	QLineEdit* colourEdit;
	QLineEdit* priceEdit;
	QLineEdit* quantityEdit;
	QTextEdit* photographEdit;

	QPushButton* addButton;
	QPushButton* deleteButton;
	QPushButton* updateButton;
	QPushButton* filterButton;

	QPushButton* displayButton;
	QPushButton* nextButton;

	QRadioButton* CSVFileButton;
	QRadioButton* HTMLFileButton;

	QPushButton* moveOneCoatButton;
	QPushButton* moveAllCoatsButton;

	QRadioButton* sortedButton;
	QRadioButton* shuffledButton;

	QListWidget* shoppingBasket;

	void initGUI();
	void populateRepoList();
	void populateShoppingBasket();
	void connectSignalsAndSlots();
	int getRepoListSelectedIndex();
	int getShoppingBasketListSelectedIndex();

private slots:

	void listItemChanged();

	void addCoat();
	void deleteCoat();
	void updateCoat();
	//filter all coats with size smaller than the given one
	void filterCoatsRepo();

	void moveCoatToShoppingBasket();
	void moveAllCoatsToShoppingBasket();

	void display();
	void next();

	void saveToCSV();
	void saveToHtml();


};