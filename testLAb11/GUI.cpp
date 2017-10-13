#include "GUI.h"
#include <QDebug>
#include <string.h>
#include <iostream>
#include <exception>
#include <qmessagebox.h>
#include "RepositoryExceptions.h"

/*
GUI::GUI(std::vector<TrenchCoat> _trenchCoats, QWidget * parent) : QWidget{ parent }, trenchCoats{ _trenchCoats }
{
	
	this->initGUI();
	this->connectSignalsAndSlots();
	this->populateTrenchCoatList();
}*/

GUI::GUI(Controller& __ctrl, QWidget * parent) : ctrl{ __ctrl }, QWidget{ parent }
{
	this->trenchCoats = this->ctrl.getRepo()->getCoats();
	this->initGUI();
	this->connectSignalsAndSlots();
	this->populateTrenchCoatList();
}

GUI::~GUI()
{
}

void GUI::initGUI()
{
	//General layout of the window
	QHBoxLayout* layout = new QHBoxLayout{ this };

	// top
	QWidget* top = new QWidget{};
	QHBoxLayout* hLayoutS = new QHBoxLayout{ top };
	QWidget* searchWidget = new QWidget{};
	QFormLayout* searchLayout = new QFormLayout{ searchWidget };
	this->searchEdit = new QLineEdit{};

	//QRadioButton* radioButtonSorted = new QRadioButton("Sorted");
	//QRadioButton* radioButtonShuffled = new QRadioButton("Shuffled");
	this->sortedButton = new QRadioButton{ "Sorted" };
	this->shuffledButton = new QRadioButton("Shuffled");
	

	// left side - just the list
	this->coatsList = new QListWidget{};
	this->radioButtons = new QListWidget{};

	// set the selection model
	this->coatsList->setSelectionMode(QAbstractItemView::SingleSelection);
	layout->addWidget(this->coatsList);	

	//layout->addWidget(radioButtonSorted);
	//layout->addWidget(radioButtonShuffled);
	layout->addWidget(sortedButton);
	layout->addWidget(shuffledButton);

	// right side - coat information + buttons
	QWidget* rightSide = new QWidget{};
	QVBoxLayout* vLayout = new QVBoxLayout{ rightSide };
	// coat information
	QWidget* coatsDataWidget = new QWidget{};
	QFormLayout* formLayout = new QFormLayout{ coatsDataWidget };
	
	

	this->IDEdit = new QLineEdit{};
	this->sizeEdit = new QLineEdit{};
	this->lengthEdit = new QLineEdit{};
	this->colourEdit = new QLineEdit{};
	this->priceEdit = new QLineEdit{};
	this->quantityEdit = new QLineEdit{};
	this->photographEdit = new QTextEdit{};

	QFont f{ "Verdana", 12 };
	QLabel* IDLabel = new QLabel{ "&ID :" };
	IDLabel->setBuddy(this->IDEdit);
	QLabel* sizeLabel = new QLabel{ "&Size :" };
	sizeLabel->setBuddy(this->sizeEdit);
	QLabel* lengthLabel = new QLabel{ "&Length :" };
	lengthLabel->setBuddy(this->lengthEdit);
	QLabel* colourLabel = new QLabel{ "&Colour : " };
	colourLabel->setBuddy(this->colourEdit);
	QLabel* priceLabel = new QLabel{ "&Price : " };
	priceLabel->setBuddy(this->priceEdit);
	QLabel* quantityLabel = new QLabel{ "&Quantity : " };
	quantityLabel->setBuddy(this->quantityEdit);
	QLabel* photographLabel = new QLabel{ "&Photograph : " };
	photographLabel->setBuddy(this->photographEdit);

	QLabel* searchLabel = new QLabel{ "&Search: " };
	searchLabel->setBuddy(this->searchEdit);

	IDLabel->setFont(f);
	sizeLabel->setFont(f);
	lengthLabel->setFont(f);
	colourLabel->setFont(f);
	priceLabel->setFont(f);
	quantityLabel->setFont(f);
	photographLabel->setFont(f);
	searchLabel->setFont(f);

	this->IDEdit->setFont(f);
	this->sizeEdit->setFont(f);
	this->lengthEdit->setFont(f);
	this->colourEdit->setFont(f);
	this->priceEdit->setFont(f);
	this->quantityEdit->setFont(f);
	this->photographEdit->setFont(f);
	this->searchEdit->setFont(f);

	formLayout->addRow(IDLabel, this->IDEdit);
	formLayout->addRow(sizeLabel, this->sizeEdit);
	formLayout->addRow(lengthLabel, this->lengthEdit);
	formLayout->addRow(colourLabel, this->colourEdit);
	formLayout->addRow(priceLabel, this->priceEdit);
	formLayout->addRow(quantityLabel, this->quantityEdit);
	formLayout->addRow(photographLabel, this->photographEdit);
	

	searchLayout->addRow(searchLabel, this->searchEdit);
	//hLayoutS->addWidget(searchWidget);

	vLayout->addWidget(coatsDataWidget);

	// buttons
	QWidget* buttonsWidget = new QWidget{};
	QHBoxLayout* hLayout = new QHBoxLayout{ buttonsWidget };
	this->addCoatButton = new QPushButton("Add Coat");
	this->addCoatButton->setFont(f);
	this->deleteCoatButton = new QPushButton("Delete Coat");
	this->deleteCoatButton->setFont(f);
	this->updateCoatButton = new QPushButton("Update Coat");
	this->updateCoatButton->setFont(f);
	hLayout->addWidget(this->addCoatButton);
	hLayout->addWidget(this->deleteCoatButton);
	hLayout->addWidget(this->updateCoatButton);

	vLayout->addWidget(buttonsWidget);
	

	// add everything to the big layout
	layout->addWidget(this->coatsList);
	layout->addWidget(rightSide);
	//layout->addWidget(top);
}

void GUI::connectSignalsAndSlots()
{
	// when the vector of coats is updated - re-populate the list
	QObject::connect(this, &GUI::coatsUpdatedSignal, this, &GUI::populateTrenchCoatList);

	// add a connection: function listItemChanged() will be called when an item in the list is selected
	QObject::connect(this->coatsList, &QListWidget::itemSelectionChanged, this, [this]() {this->listItemChanged(); });

	// add button connections
	QObject::connect(this->addCoatButton, SIGNAL(clicked()), this, SLOT(addTrenchCoatButtonHandler()));
	QObject::connect(this->deleteCoatButton, SIGNAL(clicked()), this, SLOT(deleteTrenchCoatButtonHandler()));
	QObject::connect(this->updateCoatButton, SIGNAL(clicked()), this, SLOT(updateTrenchCoatButtonHandler()));
	QObject::connect(this->sortedButton, SIGNAL(clicked()), this, SLOT(sortedTrenchCoatButtonHandler()));
	QObject::connect(this->shuffledButton, SIGNAL(clicked()), this, SLOT(shuffledTrenchCoatButtonHandler()));

	// connect the addTrenchCoat signal to the addTrenchCoat slot, which adds a coat to vector
	QObject::connect(this, SIGNAL(addTrenchCoatSignal(const int& , const double& , const double& , const std::string& , const
		double& , const	double& , const	std::string& )), this, SLOT(addTrenchCoat(const int& , const double& , const double& , const std::string& , const
			double& , const	double& , const	std::string&)));
	QObject::connect(this, SIGNAL(updateTrenchCoatSignal(const int&, const double&, const double&, const std::string&, const
		double&, const	double&, const	std::string&)), this, SLOT(updateTrenchCoat(const int&, const double&, const double&, const std::string&, const
			double&, const	double&, const	std::string&)));
	//QObject::connect(this, SIGNAL(sortedTrenchCoatSignal()), this, SLOT(sortedTrenchCoat()));
	//QObject::connect(this, SIGNAL(shuffledTrenchCoatSignal()), this, SLOT(shuffledTrenchCoat()));
}

void GUI::updateTrenchCoat(const int& ID, const double& size, const double& length, const std::string& colour, const
	double& price, const	double& quantity, const	std::string& photograph)
{
	try
	{
		this->ctrl.updateCoatFromRepository(ID, size, length, colour, price, quantity, photograph);
	}

	catch (TrenchCoatException& ex)
	{
		QMessageBox::critical(this, "TrenchCoatException", ex.what());
		/*for (auto e : ex.getErrors())
		{
			const char * error = e.c_str();
			QMessageBox::about(this, "Trench Coat Exception", error);
		}*/

	}
	catch (RepositoryException& ex)
	{
		QMessageBox::critical(this, "Repository Exception", ex.what());
	}
	catch (FileException& ex)
	{
		QMessageBox::critical(this, "File Exception", ex.what());
	}
	catch (std::exception &ex)
	{
		QMessageBox::critical(this, tr("Error"), tr(ex.what()));
	}
	//this->trenchCoats.push_back(TrenchCoat{ ID,size,length,colour,price,quantity,photograph });

	// emit the signal: the coats were updated
	emit coatsUpdatedSignal();
}

void GUI::sortedTrenchCoatButtonHandler()
{
	this->sorted = 1;
	emit coatsUpdatedSignal();
}

void GUI::shuffledTrenchCoatButtonHandler()
{
	this->sorted = 0;
	emit coatsUpdatedSignal();
}



void GUI::addTrenchCoat(const int& ID, const double& size, const double& length, const std::string& colour, const
	double& price, const	double& quantity, const	std::string& photograph)
{
	try 
	{
		this->ctrl.addCoatToRepository(ID, size, length, colour, price, quantity, photograph);
	}
	
	catch (TrenchCoatException& ex)
	{
		
		/*for (auto e : ex.getErrors())
		{
			const char * error = e.c_str();
			QMessageBox::about(this, "Trench Coat Exception",error);
		}*/
		QMessageBox::critical(this, "TrenchCoatException", ex.what());

	}
	catch (RepositoryException& ex)
	{
		QMessageBox::critical(this, "Repository Exception", ex.what());
	}
	catch (FileException& ex)
	{
		QMessageBox::critical(this, "File Exception", ex.what());
	}
	catch (std::exception &ex)
	{
		QMessageBox::critical(this, tr("Error"), tr(ex.what()));
	}
	//this->trenchCoats.push_back(TrenchCoat{ ID,size,length,colour,price,quantity,photograph });

	// emit the signal: the coats were updated
	emit coatsUpdatedSignal();
}


void GUI::addTrenchCoatButtonHandler()
{
	// read data from the textboxes and add the new coat
	QString ID=this->IDEdit->text();
	QString size= this->sizeEdit->text();
	QString length = this->lengthEdit->text();
	QString colour= this->colourEdit->text();
	QString  price= this->priceEdit->text();
	QString quantity = this->quantityEdit->text();
	QString photograph = this->photographEdit->toPlainText();

	// emit the addTrenchCoat signal
	emit addTrenchCoatSignal(ID.toInt(), size.toDouble(),length.toDouble(),colour.toStdString(),price.toDouble(),quantity.toDouble(),photograph.toStdString());
}

void GUI::deleteTrenchCoatButtonHandler()
{
	
	QString ID = this->IDEdit->text();
	try
	{
		this->ctrl.deleteCoatFromRepository(ID.toInt());
	}
	catch (RepositoryException& ex)
	{
		QMessageBox::critical(this, "Repository Exception", ex.what());
	}
	// emit the signal: the coats were updated
	emit coatsUpdatedSignal();
}

void GUI::updateTrenchCoatButtonHandler()
{

	QString ID = this->IDEdit->text();
	QString size = this->sizeEdit->text();
	QString length = this->lengthEdit->text();
	QString colour = this->colourEdit->text();
	QString  price = this->priceEdit->text();
	QString quantity = this->quantityEdit->text();
	QString photograph = this->photographEdit->toPlainText();

	// emit the addTrenchCoat signal
	emit updateTrenchCoatSignal(ID.toInt(), size.toDouble(), length.toDouble(), colour.toStdString(), price.toDouble(), quantity.toDouble(), photograph.toStdString());
}

void GUI::populateTrenchCoatList()
{

	this->trenchCoats = this->ctrl.getRepo()->getCoats();
	if (this->sorted == 1)
	{
		this->trenchCoats= this->ctrl.sortByPrice(this->trenchCoats);
	}
	// clear the list, if there are elements in it
	if (this->coatsList->count() > 0)
		this->coatsList->clear();

	for (auto c : this->trenchCoats)
	{
		
		QString itemInList = QString::fromStdString(std::to_string(c.getID()) + ", " + std::to_string(c.getSize()) +", "+ std::to_string(c.getLength()) + ", " + c.getColour() + ", " + std::to_string(c.getPrice()) + ", " + std::to_string(c.getQuantity()));
		QFont f{ "Verdana", 12 };
		QListWidgetItem* item = new QListWidgetItem{ itemInList };
		item->setFont(f);
		this->coatsList->addItem(item);
	}

	// set the selection on the first item in the list
	if (this->trenchCoats.size() > 0)
		this->coatsList->setCurrentRow(0);
}

int GUI::getSelectedIndex()
{
	if (this->coatsList->count() == 0)
		return -1;

	// get selected index
	QModelIndexList index = this->coatsList->selectionModel()->selectedIndexes();
	if (index.size() == 0)
	{
		this->IDEdit->clear();
		this->sizeEdit->clear();
		this->lengthEdit->clear();
		this->colourEdit->clear();
		this->priceEdit->clear();
		this->quantityEdit->clear();
		this->photographEdit->clear();
	
		return -1;
	}

	int idx = index.at(0).row();
	return idx;
}

void GUI::listItemChanged()
{
	int idx = this->getSelectedIndex();
	if (idx == -1)
		return;

	// get the song at the selected index
	if (idx >= this->trenchCoats.size())
		return;
	TrenchCoat c = this->trenchCoats[idx];

	this->IDEdit->setText(QString::number(c.getID()));
	this->sizeEdit->setText(QString::number(c.getSize()));
	this->lengthEdit->setText(QString::number(c.getLength()));
	this->colourEdit->setText(QString::fromStdString(c.getColour()));
	this->priceEdit->setText(QString::number(c.getPrice()));
	this->quantityEdit->setText(QString::number(c.getQuantity()));
	this->photographEdit->setText(QString::fromStdString(c.getPhotograph()));
	
}
