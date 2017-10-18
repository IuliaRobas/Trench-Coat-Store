#include <QtWidgets/QApplication>
#include <qtextstream.h>
#include <iostream>
#include <crtdbg.h>
#include <QTextStream>

#include "TrenchCoat.h"
#include "GUI.h"
#include "AllQt.h"
//#include "UI.h"
#include "ShoppingBasket.h"
#include "Tests.h"
#include "RepositoryExceptions.h"
#include "CSVShoppingBasket.h"
#include "HTMLShoppingBasket.h"
#include "RepositoryFile.h"


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	VirtualRepository* repo = new RepositoryFile{ "TrenchCoats.txt" };
	//FileShoppingBasket* CSVbasket = new CSVShoppingBasket{};
	ShoppingBasket* basket=new ShoppingBasket{};
	Controller ctrl{ repo ,basket,TrenchCoatValidator{} };
	AllQt qt{ ctrl };
	qt.show();
	return a.exec();

	
}

