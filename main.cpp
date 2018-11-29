#include "RuneEditMainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RuneEditMainWindow w;
    w.show();

    return a.exec();
}
