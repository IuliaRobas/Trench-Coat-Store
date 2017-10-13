/********************************************************************************
** Form generated from reading UI file 'testlab11.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTLAB11_H
#define UI_TESTLAB11_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_testLAb11Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *testLAb11Class)
    {
        if (testLAb11Class->objectName().isEmpty())
            testLAb11Class->setObjectName(QStringLiteral("testLAb11Class"));
        testLAb11Class->resize(600, 400);
        menuBar = new QMenuBar(testLAb11Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        testLAb11Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(testLAb11Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        testLAb11Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(testLAb11Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        testLAb11Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(testLAb11Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        testLAb11Class->setStatusBar(statusBar);

        retranslateUi(testLAb11Class);

        QMetaObject::connectSlotsByName(testLAb11Class);
    } // setupUi

    void retranslateUi(QMainWindow *testLAb11Class)
    {
        testLAb11Class->setWindowTitle(QApplication::translate("testLAb11Class", "testLAb11", 0));
    } // retranslateUi

};

namespace Ui {
    class testLAb11Class: public Ui_testLAb11Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTLAB11_H
