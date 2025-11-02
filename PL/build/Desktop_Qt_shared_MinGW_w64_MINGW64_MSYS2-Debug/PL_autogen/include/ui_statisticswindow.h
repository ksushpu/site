/********************************************************************************
** Form generated from reading UI file 'statisticswindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATISTICSWINDOW_H
#define UI_STATISTICSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_StatisticsWindow
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDateEdit *period1Start;
    QLabel *label_2;
    QDateEdit *period1End;
    QPushButton *calculateButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QDateEdit *period2Start;
    QLabel *label_4;
    QDateEdit *period2End;
    QPushButton *compareButton;
    QLabel *totalLabel;
    QTableWidget *tableWidget;

    void setupUi(QDialog *StatisticsWindow)
    {
        if (StatisticsWindow->objectName().isEmpty())
            StatisticsWindow->setObjectName("StatisticsWindow");
        StatisticsWindow->resize(600, 500);
        verticalLayout = new QVBoxLayout(StatisticsWindow);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(StatisticsWindow);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        period1Start = new QDateEdit(StatisticsWindow);
        period1Start->setObjectName("period1Start");

        horizontalLayout->addWidget(period1Start);

        label_2 = new QLabel(StatisticsWindow);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        period1End = new QDateEdit(StatisticsWindow);
        period1End->setObjectName("period1End");

        horizontalLayout->addWidget(period1End);

        calculateButton = new QPushButton(StatisticsWindow);
        calculateButton->setObjectName("calculateButton");

        horizontalLayout->addWidget(calculateButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_3 = new QLabel(StatisticsWindow);
        label_3->setObjectName("label_3");

        horizontalLayout_2->addWidget(label_3);

        period2Start = new QDateEdit(StatisticsWindow);
        period2Start->setObjectName("period2Start");

        horizontalLayout_2->addWidget(period2Start);

        label_4 = new QLabel(StatisticsWindow);
        label_4->setObjectName("label_4");

        horizontalLayout_2->addWidget(label_4);

        period2End = new QDateEdit(StatisticsWindow);
        period2End->setObjectName("period2End");

        horizontalLayout_2->addWidget(period2End);

        compareButton = new QPushButton(StatisticsWindow);
        compareButton->setObjectName("compareButton");

        horizontalLayout_2->addWidget(compareButton);


        verticalLayout->addLayout(horizontalLayout_2);

        totalLabel = new QLabel(StatisticsWindow);
        totalLabel->setObjectName("totalLabel");

        verticalLayout->addWidget(totalLabel);

        tableWidget = new QTableWidget(StatisticsWindow);
        tableWidget->setObjectName("tableWidget");

        verticalLayout->addWidget(tableWidget);


        retranslateUi(StatisticsWindow);

        QMetaObject::connectSlotsByName(StatisticsWindow);
    } // setupUi

    void retranslateUi(QDialog *StatisticsWindow)
    {
        StatisticsWindow->setWindowTitle(QCoreApplication::translate("StatisticsWindow", "\320\241\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\320\260 \321\200\320\260\321\201\321\205\320\276\320\264\320\276\320\262", nullptr));
        label->setText(QCoreApplication::translate("StatisticsWindow", "\320\237\320\265\321\200\320\270\320\276\320\264 1:", nullptr));
        label_2->setText(QCoreApplication::translate("StatisticsWindow", "\320\277\320\276", nullptr));
        calculateButton->setText(QCoreApplication::translate("StatisticsWindow", "\320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        label_3->setText(QCoreApplication::translate("StatisticsWindow", "\320\237\320\265\321\200\320\270\320\276\320\264 2:", nullptr));
        label_4->setText(QCoreApplication::translate("StatisticsWindow", "\320\277\320\276", nullptr));
        compareButton->setText(QCoreApplication::translate("StatisticsWindow", "\320\241\321\200\320\260\320\262\320\275\320\270\321\202\321\214", nullptr));
        totalLabel->setText(QCoreApplication::translate("StatisticsWindow", "\320\230\321\202\320\276\320\263\320\276: 0 \321\200\321\203\320\261.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StatisticsWindow: public Ui_StatisticsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTICSWINDOW_H
