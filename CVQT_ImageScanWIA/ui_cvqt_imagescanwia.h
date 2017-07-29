/********************************************************************************
** Form generated from reading UI file 'cvqt_imagescanwia.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CVQT_IMAGESCANWIA_H
#define UI_CVQT_IMAGESCANWIA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CVQT_ImageScanWIA
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionScan;
    QAction *actionExit;
    QWidget *centralWidget;
    QLabel *label;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CVQT_ImageScanWIA)
    {
        if (CVQT_ImageScanWIA->objectName().isEmpty())
            CVQT_ImageScanWIA->setObjectName(QStringLiteral("CVQT_ImageScanWIA"));
        CVQT_ImageScanWIA->resize(682, 779);
        actionOpen = new QAction(CVQT_ImageScanWIA);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(CVQT_ImageScanWIA);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionScan = new QAction(CVQT_ImageScanWIA);
        actionScan->setObjectName(QStringLiteral("actionScan"));
        actionExit = new QAction(CVQT_ImageScanWIA);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralWidget = new QWidget(CVQT_ImageScanWIA);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 640, 480));
        label->setStyleSheet(QLatin1String("background-color: rgb(215, 215, 215);\n"
"border-color: rgb(8, 8, 8);"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(20, 510, 641, 181));
        CVQT_ImageScanWIA->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CVQT_ImageScanWIA);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 682, 29));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        CVQT_ImageScanWIA->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CVQT_ImageScanWIA);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        CVQT_ImageScanWIA->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CVQT_ImageScanWIA);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        CVQT_ImageScanWIA->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionScan);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);

        retranslateUi(CVQT_ImageScanWIA);

        QMetaObject::connectSlotsByName(CVQT_ImageScanWIA);
    } // setupUi

    void retranslateUi(QMainWindow *CVQT_ImageScanWIA)
    {
        CVQT_ImageScanWIA->setWindowTitle(QApplication::translate("CVQT_ImageScanWIA", "CVQT_ImageScanWIA", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("CVQT_ImageScanWIA", "Open", Q_NULLPTR));
        actionSave->setText(QApplication::translate("CVQT_ImageScanWIA", "Save", Q_NULLPTR));
        actionScan->setText(QApplication::translate("CVQT_ImageScanWIA", "Scan", Q_NULLPTR));
        actionExit->setText(QApplication::translate("CVQT_ImageScanWIA", "Exit", Q_NULLPTR));
        label->setText(QString());
        menuFile->setTitle(QApplication::translate("CVQT_ImageScanWIA", "File", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CVQT_ImageScanWIA: public Ui_CVQT_ImageScanWIA {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CVQT_IMAGESCANWIA_H
