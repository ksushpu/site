#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFont font("Nunito Sans");
    font.setStyleHint(QFont::SansSerif);
    QApplication::setFont(font);
    MainWindow w;
    w.show();
    return a.exec();
}
