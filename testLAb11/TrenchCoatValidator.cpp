#include "TrenchCoatValidator.h"
#include <exception>

using namespace std;
/*
TrenchCoatException::TrenchCoatException(std::vector<std::string> _errors) : errors{ _errors }
{
}

std::vector<std::string> TrenchCoatException::getErrors() const
{
	return this->errors;
}
*/
TrenchCoatException::TrenchCoatException() : exception{}, message{ "" }
{
}

TrenchCoatException::TrenchCoatException(const std::string & msg) : message{ msg }
{
}

const char * TrenchCoatException::what()
{
	return this->message.c_str();
}

const char * IDException::what()
{
	return "ID cannot be smaller than 0!";
}

const char * SizeException::what()
{
	return "Size cannot be smaller than 0!";
}

const char * LengthException::what()
{
	return "Length cannot be smaller than 0!";
}


const char * ColourException::what()
{
	return "The colour must have at least 3 characters!";
}


const char * PriceException::what()
{
	return "Price cannot be smaller than 0!";
}


const char * QuantityException::what()
{
	return "Quantity cannot be smaller than 0!";
}

const char * PhotographException::what()
{
	return "The photograph link must start either with \"www\" or \"http\"!";
}


void TrenchCoatValidator::validate(const TrenchCoat& c)
{
	vector<string> errors;
	if (c.getID() < 0)
		//errors.push_back("ID cannot be smaller than 0.\n");
		throw IDException();		
	if (c.getSize() < 0)
		throw SizeException();
		//errors.push_back("Size cannot be smaller than 0.\n");
	if (c.getLength() < 0)
		throw LengthException();
		//errors.push_back("Length cannot be smaller than 0.\n");
	if (c.getColour().size() < 3)
		throw ColourException();
		//errors.push_back("The colour must have at least 4 characters.\n");
	if (c.getPrice() < 0)
		throw PriceException();
		//errors.push_back("Price cannot be smaller than 0.\n");
	if (c.getQuantity() < 0)
		throw QuantityException();
		//errors.push_back("Quantity cannot be smaller than 0.\n");

	// search for "www" or "http" at the beginning of the source string
	int posWww = c.getPhotograph().find("www");
	int posHttp = c.getPhotograph().find("http");
	if (posWww != 0 && posHttp != 0)
		//errors.push_back("The photograph link must start either with \"www\" or \"http\".\n");
		throw PhotographException();
	/*if (errors.size() > 0)
	{
		errors.insert(errors.begin(), "\n");
		throw TrenchCoatException(errors);
	}*/
}
