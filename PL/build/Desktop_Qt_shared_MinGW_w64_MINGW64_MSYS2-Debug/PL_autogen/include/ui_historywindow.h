/********************************************************************************
** Form generated from reading UI file 'historywindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORYWINDOW_H
#define UI_HISTORYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_HistoryWindow
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QCheckBox *dateCheckBox;
    QDateEdit *dateEdit;
    QCheckBox *categoryCheckBox;
    QLineEdit *categoryEdit;
    QPushButton *filterButton;
    QPushButton *clearFilterButton;
    QListWidget *historyList;
    QLabel *countLabel;

    void setupUi(QDialog *HistoryWindow)
    {
        if (HistoryWindow->objectName().isEmpty())
            HistoryWindow->setObjectName("HistoryWindow");
        HistoryWindow->resize(600, 500);
        verticalLayout = new QVBoxLayout(HistoryWindow);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        dateCheckBox = new QCheckBox(HistoryWindow);
        dateCheckBox->setObjectName("dateCheckBox");

        horizontalLayout->addWidget(dateCheckBox);

        dateEdit = new QDateEdit(HistoryWindow);
        dateEdit->setObjectName("dateEdit");

        horizontalLayout->addWidget(dateEdit);

        categoryCheckBox = new QCheckBox(HistoryWindow);
        categoryCheckBox->setObjectName("categoryCheckBox");

        horizontalLayout->addWidget(categoryCheckBox);

        categoryEdit = new QLineEdit(HistoryWindow);
        categoryEdit->setObjectName("categoryEdit");

        horizontalLayout->addWidget(categoryEdit);

        filterButton = new QPushButton(HistoryWindow);
        filterButton->setObjectName("filterButton");

        horizontalLayout->addWidget(filterButton);

        clearFilterButton = new QPushButton(HistoryWindow);
        clearFilterButton->setObjectName("clearFilterButton");

        horizontalLayout->addWidget(clearFilterButton);


        verticalLayout->addLayout(horizontalLayout);

        historyList = new QListWidget(HistoryWindow);
        historyList->setObjectName("historyList");

        verticalLayout->addWidget(historyList);

        countLabel = new QLabel(HistoryWindow);
        countLabel->setObjectName("countLabel");

        verticalLayout->addWidget(countLabel);


        retranslateUi(HistoryWindow);

        QMetaObject::connectSlotsByName(HistoryWindow);
    } // setupUi

    void retranslateUi(QDialog *HistoryWindow)
    {
        HistoryWindow->setWindowTitle(QCoreApplication::translate("HistoryWindow", "\320\230\321\201\321\202\320\276\321\200\320\270\321\217 \320\277\320\276\320\272\321\203\320\277\320\276\320\272", nullptr));
        dateCheckBox->setText(QCoreApplication::translate("HistoryWindow", "\320\224\320\260\321\202\320\260:", nullptr));
        categoryCheckBox->setText(QCoreApplication::translate("HistoryWindow", "\320\232\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\217:", nullptr));
        filterButton->setText(QCoreApplication::translate("HistoryWindow", "\320\244\320\270\320\273\321\214\321\202\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        clearFilterButton->setText(QCoreApplication::translate("HistoryWindow", "\320\241\320\261\321\200\320\276\321\201\320\270\321\202\321\214", nullptr));
        countLabel->setText(QCoreApplication::translate("HistoryWindow", "\320\235\320\260\320\271\320\264\320\265\320\275\320\276 \320\267\320\260\320\277\320\270\321\201\320\265\320\271: 0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HistoryWindow: public Ui_HistoryWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORYWINDOW_H
