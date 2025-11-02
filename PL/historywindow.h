#ifndef HISTORYWINDOW_H
#define HISTORYWINDOW_H

#include <QDialog>
#include "purchasehistory.h"

namespace Ui {
class HistoryWindow;
}

class HistoryWindow : public QDialog
{
    Q_OBJECT

public:
    explicit HistoryWindow(const PurchaseHistory& history, QWidget *parent = nullptr);
    ~HistoryWindow();

private slots:
    void on_filterButton_clicked();
    void on_clearFilterButton_clicked();

private:
    Ui::HistoryWindow *ui;
    const PurchaseHistory& history;
    void updateHistoryList(const QList<PurchaseRecord>& records);
};

#endif // HISTORYWINDOW_H
