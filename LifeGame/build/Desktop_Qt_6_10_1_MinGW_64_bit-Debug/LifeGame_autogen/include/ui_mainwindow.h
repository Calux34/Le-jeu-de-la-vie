/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridcontainer;
    QSlider *horizontalSlider;
    QPushButton *boutonNext;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *boutonStart;
    QPushButton *boutonStop;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridcontainer = new QWidget(centralwidget);
        gridcontainer->setObjectName("gridcontainer");
        gridcontainer->setGeometry(QRect(11, 76, 678, 462));
        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setGeometry(QRect(11, 11, 141, 22));
        horizontalSlider->setOrientation(Qt::Orientation::Horizontal);
        boutonNext = new QPushButton(centralwidget);
        boutonNext->setObjectName("boutonNext");
        boutonNext->setGeometry(QRect(500, 20, 93, 29));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(696, 437, 93, 29));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(696, 473, 93, 29));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(696, 509, 93, 29));
        boutonStart = new QPushButton(centralwidget);
        boutonStart->setObjectName("boutonStart");
        boutonStart->setGeometry(QRect(260, 20, 93, 29));
        boutonStop = new QPushButton(centralwidget);
        boutonStop->setObjectName("boutonStop");
        boutonStop->setGeometry(QRect(380, 20, 93, 29));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        boutonNext->setText(QCoreApplication::translate("MainWindow", "Restart", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        boutonStart->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        boutonStop->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
