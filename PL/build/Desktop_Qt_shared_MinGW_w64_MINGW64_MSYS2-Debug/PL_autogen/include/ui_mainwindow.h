/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *nameEdit;
    QLabel *label_2;
    QLineEdit *categoryEdit;
    QLabel *label_3;
    QLineEdit *priceEdit;
    QPushButton *addButton;
    QListWidget *productList;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *removeButton;
    QPushButton *clearButton;
    QPushButton *calculateButton;
    QLabel *countLabel;
    QLabel *totalLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(655, 400);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        nameEdit = new QLineEdit(centralwidget);
        nameEdit->setObjectName("nameEdit");

        horizontalLayout->addWidget(nameEdit);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        categoryEdit = new QLineEdit(centralwidget);
        categoryEdit->setObjectName("categoryEdit");

        horizontalLayout->addWidget(categoryEdit);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");

        horizontalLayout->addWidget(label_3);

        priceEdit = new QLineEdit(centralwidget);
        priceEdit->setObjectName("priceEdit");

        horizontalLayout->addWidget(priceEdit);

        addButton = new QPushButton(centralwidget);
        addButton->setObjectName("addButton");

        horizontalLayout->addWidget(addButton);


        verticalLayout->addLayout(horizontalLayout);

        productList = new QListWidget(centralwidget);
        productList->setObjectName("productList");

        verticalLayout->addWidget(productList);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        removeButton = new QPushButton(centralwidget);
        removeButton->setObjectName("removeButton");

        horizontalLayout_2->addWidget(removeButton);

        clearButton = new QPushButton(centralwidget);
        clearButton->setObjectName("clearButton");

        horizontalLayout_2->addWidget(clearButton);

        calculateButton = new QPushButton(centralwidget);
        calculateButton->setObjectName("calculateButton");

        horizontalLayout_2->addWidget(calculateButton);

        countLabel = new QLabel(centralwidget);
        countLabel->setObjectName("countLabel");

        horizontalLayout_2->addWidget(countLabel);

        totalLabel = new QLabel(centralwidget);
        totalLabel->setObjectName("totalLabel");

        horizontalLayout_2->addWidget(totalLabel);


        verticalLayout->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 655, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\241\320\277\320\270\321\201\320\276\320\272 \320\277\320\276\320\272\321\203\320\277\320\276\320\272", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\232\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\217:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\246\320\265\320\275\320\260:", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        removeButton->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        calculateButton->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        countLabel->setText(QCoreApplication::translate("MainWindow", "\320\242\320\276\320\262\320\260\321\200\320\276\320\262: 0", nullptr));
        totalLabel->setText(QCoreApplication::translate("MainWindow", "\320\230\321\202\320\276\320\263\320\276: 0 \321\200\321\203\320\261.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
