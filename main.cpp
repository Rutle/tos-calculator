#include "calc.hh"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Calc w;
    w.show();

    return a.exec();
}
