/********************************************************************************
** Form generated from reading UI file 'playlistqt.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYLISTQT_H
#define UI_PLAYLISTQT_H

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

class Ui_PlayListQtClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PlayListQtClass)
    {
        if (PlayListQtClass->objectName().isEmpty())
            PlayListQtClass->setObjectName(QStringLiteral("PlayListQtClass"));
        PlayListQtClass->resize(600, 400);
        menuBar = new QMenuBar(PlayListQtClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        PlayListQtClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PlayListQtClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        PlayListQtClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(PlayListQtClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        PlayListQtClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(PlayListQtClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        PlayListQtClass->setStatusBar(statusBar);

        retranslateUi(PlayListQtClass);

        QMetaObject::connectSlotsByName(PlayListQtClass);
    } // setupUi

    void retranslateUi(QMainWindow *PlayListQtClass)
    {
        PlayListQtClass->setWindowTitle(QApplication::translate("PlayListQtClass", "PlayListQt", 0));
    } // retranslateUi

};

namespace Ui {
    class PlayListQtClass: public Ui_PlayListQtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYLISTQT_H
