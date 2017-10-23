#include "rmultiple.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RMultiple w;
    w.show();

    return a.exec();
}
