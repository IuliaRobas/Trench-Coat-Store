#pragma once
#include <string>
#include "TrenchCoat.h"
#include <vector>
/*
class TrenchCoatException
{
private:
	std::vector<std::string>errors;
public:
	TrenchCoatException(std::vector<std::string> _errors);
	std::vector<std::string> getErrors() const;
};

class TrenchCoatValidator
{
public:
	TrenchCoatValidator() {}
	static void validate(const TrenchCoat& c);
};
*/

class TrenchCoatException : public std::exception
{
protected:
	std::string message;

public:
	TrenchCoatException();
	TrenchCoatException(const std::string& msg);
	virtual ~TrenchCoatException() {}
	virtual const char* what();
};

class IDException : public TrenchCoatException
{
	const char* what();
};

class SizeException : public TrenchCoatException
{
	const char* what();
};

class LengthException : public TrenchCoatException
{
	const char* what();
};


class ColourException : public TrenchCoatException
{
	const char* what();
};


class PriceException : public TrenchCoatException
{
	const char* what();
};

class QuantityException : public TrenchCoatException
{
	const char* what();
};

class PhotographException : public TrenchCoatException
{
	const char* what();
};


class TrenchCoatValidator
{
public:
	TrenchCoatValidator() {}
	static void validate(const TrenchCoat& c);
};