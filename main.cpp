#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDir>
#include "buttons.h"
#include <QDebug>
#include <QObject>
#include <string>
#include <QCheckBox>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    QWidget *mainWindow = new QWidget;
    mainWindow->setWindowTitle("WeMod Bypass Manager");
    mainWindow->setMinimumWidth(400);
    mainWindow->setMinimumHeight(400);
    QVBoxLayout* layout = new QVBoxLayout;
    buttons a(layout);
    mainWindow->setLayout(layout);
    mainWindow->show();
    return app.exec();

}
