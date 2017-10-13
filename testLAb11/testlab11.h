#ifndef TESTLAB11_H
#define TESTLAB11_H

#include <QtWidgets/QMainWindow>
#include "ui_testlab11.h"

class testLAb11 : public QMainWindow
{
	Q_OBJECT

public:
	testLAb11(QWidget *parent = 0);
	~testLAb11();

private:
	Ui::testLAb11Class ui;
};

#endif // TESTLAB11_H
