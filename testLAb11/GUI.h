#pragma once
#include "TrenchCoat.h"
#include "Controller.h"
#include <qwidget.h>
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <qradiobutton.h>
#include <qabstractbutton.h>

class GUI :public QWidget
{
	Q_OBJECT
public:
	GUI();
	GUI(Controller& __ctrl, QWidget *parent = 0);
	//GUI(std::vector<TrenchCoat> trenchCoats, QWidget *parent = 0);
	~GUI();

private:
	int sorted = 0;
	std::vector<TrenchCoat> trenchCoats;
	Controller& ctrl;

	QListWidget* radioButtons;
	QListWidget* coatsList;
	QLineEdit* IDEdit;
	QLineEdit* sizeEdit;
	QLineEdit* lengthEdit;
	QLineEdit* colourEdit;
	QLineEdit* priceEdit;
	QLineEdit* quantityEdit;
	QTextEdit* photographEdit;

	QLineEdit* searchEdit;

	QPushButton* addCoatButton;
	QPushButton* deleteCoatButton;
	QPushButton* updateCoatButton;

	QRadioButton* sortedButton;
	QRadioButton* shuffledButton;

	void initGUI();
	int getSelectedIndex();
	void connectSignalsAndSlots();

	void populateTrenchCoatList();
	// When an item in the list is clicked, the text boxes get filled with the item's information
	void listItemChanged();

signals:
	void coatsUpdatedSignal();
	void addTrenchCoatSignal(const int& ID, const double& size,const double& length,const std::string& colour,const
	double& price,const	double& quantity,const	std::string& photograph);
	void updateTrenchCoatSignal(const int& ID, const double& size, const double& length, const std::string& colour, const
		double& price, const	double& quantity, const	std::string& photograph);
	//void sortedTrenchCoatSignal();
	//void shuffledTrenchCoatSignal();

public slots:
	void addTrenchCoatButtonHandler();
	void deleteTrenchCoatButtonHandler();
	void updateTrenchCoatButtonHandler();
	void sortedTrenchCoatButtonHandler();
	void shuffledTrenchCoatButtonHandler();

	void updateTrenchCoat(const int& ID, const double& size, const double& length, const std::string& colour, const
		double& price, const	double& quantity, const	std::string& photograph);
	void addTrenchCoat(const int& ID, const double& size, const double& length, const std::string& colour, const
		double& price, const	double& quantity, const	std::string& photograph);
	//void sortedTrenchCoat();
	//void shuffledTrenchCoat();
};