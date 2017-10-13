#include "AllQt.h"
#include "TrenchCoat.h"
#include "Utils.h"
#include "CSVShoppingBasket.h"
#include "RepositoryExceptions.h"
#include "FileShoppingBasket.h"

#include <vector>
#include <QDebug>
#include <string.h>
#include <iostream>
#include <exception>
#include <qmessagebox.h>

AllQt::AllQt(Controller& c, QWidget* parent) :ctrl{ c }, QWidget{ parent }
{
	this->initGUI();
	this->coatsInRepo = this->ctrl.getRepo()->getCoats();
	this->coatsInBasket = this->ctrl.getShoppingBasket()->getAll();
	this->populateRepoList();

}

AllQt::~AllQt()
{

}

void AllQt::initGUI()
{
	QHBoxLayout* layout = new QHBoxLayout{ this };

	//left side component, which is a vertical layout
	QWidget* leftWidget = new QWidget{};
	QVBoxLayout* leftSide = new QVBoxLayout{ leftWidget };

	//coats list
	this->repoList = new QListWidget{};
	this->repoList->setSelectionMode(QAbstractItemView::SingleSelection);

	//data for the coat
	QWidget* coatDataWidget = new QWidget{};
	QFormLayout* formLayout = new QFormLayout{ coatDataWidget };

	this->IDEdit = new QLineEdit{};
	this->sizeEdit = new QLineEdit{};
	this->lengthEdit = new QLineEdit{};
	this->colourEdit = new QLineEdit{};
	this->priceEdit = new QLineEdit{};
	this->quantityEdit = new QLineEdit{};
	this->photographEdit = new QTextEdit{};

	formLayout->addRow("&ID: ", this->IDEdit);
	formLayout->addRow("Size: ", this->sizeEdit);
	formLayout->addRow("Lenght: ", this->lengthEdit);
	formLayout->addRow("Colour: ", this->colourEdit);
	formLayout->addRow("Price: ", this->priceEdit);
	formLayout->addRow("Quantity: ", this->quantityEdit);
	formLayout->addRow("Photograph: ", this->photographEdit);

	//buttons
	QWidget* buttonsWidget = new QWidget{};
	QGridLayout* gridLayout = new QGridLayout{ buttonsWidget };
	this->addButton = new QPushButton("Add");
	this->deleteButton = new QPushButton("Delete");
	this->updateButton = new QPushButton("Update");
	this->filterButton = new QPushButton("Filter");

	gridLayout->addWidget(addButton,0,0);
	gridLayout->addWidget(deleteButton,0,1);
	gridLayout->addWidget(updateButton,0,2);
	gridLayout->addWidget(filterButton,0,3);

	//add everything to the left layout
	leftSide->addWidget(new QLabel{ "Available coats" });
	leftSide->addWidget(repoList);
	leftSide->addWidget(coatDataWidget);
	leftSide->addWidget(buttonsWidget);

	//middle component
	QWidget* middleWidget = new QWidget{};
	QVBoxLayout*  vLayoutMiddle = new QVBoxLayout{ middleWidget };
	this->moveOneCoatButton = new QPushButton{ "Add coat to basket" };
	this->moveAllCoatsButton = new QPushButton{ "Add all coats to basket" };
	
	QWidget* upperPart = new QWidget{};
	QVBoxLayout* vLayoutUpperPart = new QVBoxLayout{ upperPart };
	vLayoutUpperPart->addWidget(this->moveOneCoatButton);
	vLayoutUpperPart->addWidget(this->moveAllCoatsButton);
	vLayoutMiddle->addWidget(upperPart);

	//right side: the shopping basket
	QWidget* rightWidget = new QWidget{};
	QVBoxLayout* rightSide = new QVBoxLayout{ rightWidget };

	//basket
	this->shoppingBasket = new QListWidget{};
	this->shoppingBasket->setSelectionMode(QAbstractItemView::SingleSelection);

	//buttons for the basket
	QWidget* basketButtonsWidget = new QWidget{};
	QHBoxLayout* basketButtonsLayout = new QHBoxLayout{ basketButtonsWidget };
	this->displayButton = new QPushButton{ "&Display" };
	basketButtonsLayout->addWidget(displayButton);
	this->nextButton = new QPushButton{ "&Next" };
	basketButtonsLayout->addWidget(nextButton);

	QWidget* fileButtonsWidget = new QWidget{};
	QHBoxLayout* fileButtonsLayout = new QHBoxLayout{ fileButtonsWidget };
	fileButtonsLayout->addWidget(new QLabel{ "File saving options: " });
	this->CSVFileButton=new QRadioButton{ "&CSV" };
	fileButtonsLayout->addWidget(CSVFileButton);
	this->HTMLFileButton = new QRadioButton{ "&HTML" };
	fileButtonsLayout->addWidget(HTMLFileButton);

	//add everything to the right layout
	rightSide->addWidget(new QLabel{ "Shopping Basket" });
	rightSide->addWidget(shoppingBasket);
	rightSide->addWidget(basketButtonsWidget);
	rightSide->addWidget(fileButtonsWidget);

	//add all layouts to the main layout
	layout->addWidget(leftWidget);
	layout->addWidget(middleWidget);
	layout->addWidget(rightWidget);

	this->connectSignalsAndSlots();

}

void AllQt::connectSignalsAndSlots()
{
	//when an item in the list is selected
	QObject::connect(this->repoList, SIGNAL(itemSelectionChanged()), this, SLOT(listItemChanged()));
	QObject::connect(this->shoppingBasket, SIGNAL(itemSelectionChanged()), this, SLOT(listItemChanged()));

	//button connections
	QObject::connect(this->addButton, SIGNAL(clicked()), this, SLOT(addCoat()));
	QObject::connect(this->deleteButton, SIGNAL(clicked()), this, SLOT(deleteCoat()));
	QObject::connect(this->updateButton, SIGNAL(clicked()), this, SLOT(updateCoat()));
	QObject::connect(this->filterButton, SIGNAL(clicked()), this, SLOT(filterCoatsRepo()));

	QObject::connect(this->moveOneCoatButton, SIGNAL(clicked()), this, SLOT(moveCoatToShoppingBasket()));
	QObject::connect(this->moveAllCoatsButton, SIGNAL(clicked()), this, SLOT(moveAllCoatsToShoppingBasket()));

	QObject::connect(this->displayButton, SIGNAL(clicked()), this, SLOT(display()));
	QObject::connect(this->nextButton, SIGNAL(clicked()), this, SLOT(next()));
	
	QObject::connect(this->CSVFileButton, SIGNAL(clicked()), this, SLOT(saveToCSV()));
	QObject::connect(this->HTMLFileButton, SIGNAL(clicked()), this, SLOT(saveToHtml()));

}

void AllQt::populateRepoList()
{
	if (this->repoList->count() > 0)
		this->repoList->clear();
	for (auto c : this->coatsInRepo)
	{
		QString coat=QString::fromStdString(std::to_string(c.getID()) + ", " + std::to_string(c.getSize()) + ", " + std::to_string(c.getLength()) + ", " + c.getColour() + ", " + std::to_string(c.getPrice()) + ", " + std::to_string(c.getQuantity()));
		QListWidgetItem* item = new QListWidgetItem(coat);
		this->repoList->addItem(item);
	}

	//set selection on the first item in the list
	if (this->coatsInRepo.size() > 0)
		this->repoList->setCurrentRow(this->coatsInRepo.size()-1);
	

}

void AllQt::populateShoppingBasket()
{
	if (this->shoppingBasket->count() > 0)
		this->shoppingBasket->clear();
	
	for (auto c : this->ctrl.getShoppingBasket()->getAll())
	{
		
		QString coat = QString::fromStdString(std::to_string(c.getID()) + ", " + std::to_string(c.getSize()) + ", " + std::to_string(c.getLength()) + ", " + c.getColour() + ", " + std::to_string(c.getPrice()) + ", " + std::to_string(c.getQuantity()));
		QListWidgetItem* item = new QListWidgetItem(coat);
		this->shoppingBasket->addItem(item);

	}

}

int AllQt::getShoppingBasketListSelectedIndex()
{
	if(this->shoppingBasket->count() == 0)
	{
		return -1;
	}
	QModelIndexList index = this->shoppingBasket->selectionModel()->selectedIndexes();
	
	if (index.size() == 0)
	{
		return -1;
	}

	int idx = index.at(0).row();
	return idx;
}

int AllQt::getRepoListSelectedIndex()
{
	if (this->repoList->count() == 0)
	{
		return -1;
	}

	//get selected index
	QModelIndexList index = this->repoList->selectionModel()->selectedIndexes();
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

void AllQt::listItemChanged()
{
	int idx = this->getRepoListSelectedIndex();
	if (idx == -1)
		return;

	// get the song at the selected index
	if (idx >= this->coatsInRepo.size())
		return;
	TrenchCoat c = this->coatsInRepo[idx];

	this->IDEdit->setText(QString::number(c.getID()));
	this->sizeEdit->setText(QString::number(c.getSize()));
	this->lengthEdit->setText(QString::number(c.getLength()));
	this->colourEdit->setText(QString::fromStdString(c.getColour()));
	this->priceEdit->setText(QString::number(c.getPrice()));
	this->quantityEdit->setText(QString::number(c.getQuantity()));
	this->photographEdit->setText(QString::fromStdString(c.getPhotograph()));

}

void AllQt::addCoat()
{
	/*int idx = this->getRepoListSelectedIndex();
	if (idx == -1 || idx >= this->coatsInRepo.size())
		return;*/
	// read data from the textboxes and add the new coat
	QString ID = this->IDEdit->text();
	QString size = this->sizeEdit->text();
	QString length = this->lengthEdit->text();
	QString colour = this->colourEdit->text();
	QString  price = this->priceEdit->text();
	QString quantity = this->quantityEdit->text();
	QString photograph = this->photographEdit->toPlainText();

	try
	{
		this->ctrl.addCoatToRepository(ID.toInt(), size.toDouble(), length.toDouble(), colour.toStdString(), price.toDouble(), quantity.toDouble(), photograph.toStdString());
		this->coatsInRepo = this->ctrl.getRepo()->getCoats();
		this->populateRepoList();
		//this->repoList->setCurrentRow(this->coatsInRepo.size()-1);
	}
	catch (TrenchCoatException& ex)
		{
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

}

void AllQt::filterCoatsRepo()
{
	QString size = this->sizeEdit->text();
	try
	{
		this->coatsInRepo = this->ctrl.listTrenchCoatsWithSizeCtrl(size.toInt());
		this->populateRepoList();
	}
	catch (TrenchCoatException& ex)
	{
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
}

void AllQt::deleteCoat()
{
	QString ID = this->IDEdit->text();
	try
	{
		this->ctrl.deleteCoatFromRepository(ID.toInt());
		this->coatsInRepo = this->ctrl.getRepo()->getCoats();
		this->populateRepoList();
	}
	catch (TrenchCoatException& ex)
	{
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
}

void AllQt::updateCoat()
{
	QString ID = this->IDEdit->text();
	QString size = this->sizeEdit->text();
	QString length = this->lengthEdit->text();
	QString colour = this->colourEdit->text();
	QString  price = this->priceEdit->text();
	QString quantity = this->quantityEdit->text();
	QString photograph = this->photographEdit->toPlainText();

	try
	{
		this->ctrl.updateCoatFromRepository(ID.toInt(), size.toDouble(), length.toDouble(), colour.toStdString(), price.toDouble(), quantity.toDouble(), photograph.toStdString());
		this->coatsInRepo = this->ctrl.getRepo()->getCoats();
		this->populateRepoList();
	}
	catch (TrenchCoatException& ex)
	{
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
}

void AllQt::display()
{
	int idx = getShoppingBasketListSelectedIndex();
	//QMessageBox::critical(this, "index", QString::fromStdString(std::to_string (idx)));
	if (idx == -1 || idx >= this->coatsInBasket.size())
		return;
	TrenchCoat& c = this->coatsInBasket[idx];
	c.display();
	
	//QMessageBox::critical(this, "index",QString::fromStdString(std::to_string(c.getID())));
}

void AllQt::next()
{
	int idx = getShoppingBasketListSelectedIndex();
	idx++;
	if (idx == -1)
		return;
	if (idx == this->coatsInBasket.size())
	{	this->shoppingBasket->setCurrentRow(0);
		idx = 0;
	}
	else
		this->shoppingBasket->setCurrentRow(idx);
	TrenchCoat& c = this->coatsInBasket[idx];	
	
	c.display();
	

}

void AllQt::moveCoatToShoppingBasket()
{
	int idx = this->getRepoListSelectedIndex();
	if (idx == -1 || idx >= this->coatsInRepo.size())
		return;

	const TrenchCoat& c = this->coatsInRepo[idx];
	int ID = c.getID();
	double size = c.getSize();
	double length = c.getLength();
	std::string colour = c.getColour();
	double price = c.getPrice();
	double quantity = c.getQuantity() - 1;
	std::string link =c.getPhotograph();
	this->ctrl.updateCoatFromRepository(ID, size, length, colour, price, quantity, link);
	this->ctrl.addCoatToShoppingBasketCtrl(c);
	this->coatsInBasket = this->ctrl.getShoppingBasket()->getAll();
	this->populateShoppingBasket();
	this->coatsInRepo = this->ctrl.getRepo()->getCoats();
	this->populateRepoList();
}

void AllQt::moveAllCoatsToShoppingBasket()
{
	for (auto c : this->coatsInRepo)
	{
		this->ctrl.addCoatToShoppingBasketCtrl(c);
	}
	this->coatsInBasket = this->ctrl.getShoppingBasket()->getAll();
	this->populateShoppingBasket();
	for (auto c : this->coatsInRepo)
	{
		int ID = c.getID();
		double size = c.getSize();
		double length = c.getLength();
		std::string colour = c.getColour();
		double price = c.getPrice();
		double quantity = c.getQuantity() - 1;
		std::string link = c.getPhotograph();
		this->ctrl.updateCoatFromRepository(ID, size, length, colour, price, quantity, link);
	}
	this->coatsInRepo = this->ctrl.getRepo()->getCoats();
	this->populateRepoList();
}

void AllQt::saveToCSV()
{
	FileShoppingBasket* CSVbasket = new CSVShoppingBasket{};
	for (auto c : this->ctrl.getShoppingBasket()->getAll())
	{
		CSVbasket->add(c);
	}
	//CSVbasket = this->ctrl.getShoppingBasket();
	try
	{
		CSVbasket->setFilename("C:\\Users\\Utilizator\\Desktop\\ff.txt");
		CSVbasket->writeToFile();
		//this->ctrl.saveShoppingBasket("C:\Users\Utilizator\Desktop\ff.txt");
	}
	catch (std::exception &ex)
	{
		QMessageBox::critical(this, "Error",ex.what());
	}

	//delete this->ctrl.getShoppingBasket();

}

void AllQt::saveToHtml()
{
	QMessageBox::critical(this, "Error", "hello");
}