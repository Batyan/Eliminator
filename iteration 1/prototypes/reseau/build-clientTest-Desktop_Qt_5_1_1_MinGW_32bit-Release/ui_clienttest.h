/********************************************************************************
** Form generated from reading UI file 'clienttest.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTTEST_H
#define UI_CLIENTTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_clientTest
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QPushButton *msgButton;
    QLineEdit *msgInput;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QLabel *msgLabel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *clientTest)
    {
        if (clientTest->objectName().isEmpty())
            clientTest->setObjectName(QStringLiteral("clientTest"));
        clientTest->resize(466, 227);
        centralWidget = new QWidget(clientTest);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(-1, 0, -1, 0);
        msgButton = new QPushButton(centralWidget);
        msgButton->setObjectName(QStringLiteral("msgButton"));

        gridLayout->addWidget(msgButton, 2, 1, 1, 1);

        msgInput = new QLineEdit(centralWidget);
        msgInput->setObjectName(QStringLiteral("msgInput"));

        gridLayout->addWidget(msgInput, 2, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 0, 1, 1);

        msgLabel = new QLabel(centralWidget);
        msgLabel->setObjectName(QStringLiteral("msgLabel"));

        gridLayout->addWidget(msgLabel, 1, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        clientTest->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(clientTest);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 466, 20));
        clientTest->setMenuBar(menuBar);
        mainToolBar = new QToolBar(clientTest);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        clientTest->addToolBar(Qt::TopToolBarArea, mainToolBar);

        retranslateUi(clientTest);

        QMetaObject::connectSlotsByName(clientTest);
    } // setupUi

    void retranslateUi(QMainWindow *clientTest)
    {
        clientTest->setWindowTitle(QApplication::translate("clientTest", "clientTest", 0));
        msgButton->setText(QApplication::translate("clientTest", "envoyer", 0));
        msgLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class clientTest: public Ui_clientTest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTTEST_H
