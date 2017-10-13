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
	//QTextStream(stdout) << "string to print" << endl;
	//UI ui{ ctrl };
	//ui.startUI();
	//std::vector<TrenchCoat> coats{ TrenchCoat{ 10,36,10,"white",400,40,"https://cdn-images.farfetch-contents.com/11/43/71/44/11437144_8384040_400.jpg" } };
	//GUI gui{ctrl};
	//gui.show();
	AllQt qt{ ctrl };
	qt.show();
	return a.exec();

	//try
	//{

		//Repository repo{ "Coats.txt" };	

		//VirtualRepository* repo = new RepositoryFile{ "TrenchCoats.txt" };
		//FileShoppingBasket* HTMLbasket = new HTMLShoppingBasket{};
		//cout << "std out!";
		//cout << "\n**********************************************************";
		//cout << "\nSHOPPING BASKET FILE STORAGE OPTIONS.\n";
		//cout << "1 - CSV file.\n";
		//cout << "2 - HTML file.\n";
		//cout << "0 - Exit.\n";
		//cout << "**********************************************************\n";
		//int option ;
		//cout << "Input your option: ";
		//if (option == 0)
			//return 0;
		//switch (option)
		//{
		//case 1:
		//{
			//FileShoppingBasket* CSVbasket = new CSVShoppingBasket{};
			//Controller ctrl{ repo ,CSVbasket,TrenchCoatValidator{} };
			//UI ui{ ctrl };
			//ui.startUI();
		//}
		//case 2:
		//{
			//FileShoppingBasket* HTMLbasket = new HTMLShoppingBasket{};
			//Controller ctrl{ repo ,HTMLbasket,TrenchCoatValidator{} };
			//UI ui{ ctrl };
			//ui.startUI();
		//}
		//}

	//}
	//catch (FileException& e)
//	{
		//cout << "Repository file could not be opened! The application will terminate." << endl;
		//return 1;
	//}


//	return 0;


	//testLAb11 w;
	//w.show();
	//std::vector<TrenchCoat> coats{TrenchCoat{ 10,36,10,"white",400,40,"https://cdn-images.farfetch-contents.com/11/43/71/44/11437144_8384040_400.jpg"}};
	//*/
}

