#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "shoppinglist.h"
#include "purchasehistory.h"
#include "expensestatistics.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void on_removeButton_clicked();
    void on_clearButton_clicked();
    void on_calculateButton_clicked();
    void on_historyButton_clicked();
    void on_recommendationsButton_clicked();

    void on_statisticsButton_clicked();

    void on_addButton_clicked();

private:
    Ui::MainWindow *ui;
    ShoppingList shoppingList;
    PurchaseHistory purchaseHistory;
    void updateProductList();

    ////////////////////JSON///////
    const QString HISTORY_FILE = "purchase_history.json";
    void loadHistory();
    void saveHistory();
    bool checkHistoryFileIntegrity();

    void saveCategoriesToFile();
    void loadCategoriesFromFile();
    void loadCategories();
};

#endif // MAINWINDOW_H
