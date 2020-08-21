#include <Qt>
#include "buttons.h"
#include <QDir>
#include <QPushButton>
#include <QDebug>
#include <QObject>
#include <QDir>
#include <QFile>
#include <QByteArray>
#include <QCryptographicHash>
#include <QHBoxLayout>
#include <QModelIndex>
#include <QGridLayout>
#include <QFileInfo>
#include <QLabel>
#include <QPixmap>

buttons::buttons(QVBoxLayout* layout)
{
   for(int i = 0; i < games.size(); i++)
   {
       QPushButton* button = new QPushButton(games.at(i));
       button->setIcon(QIcon(thumbs.at(i)));
       button->setIconSize(QSize(65,85));
       layout->addWidget(button);
       QObject::connect(button, &QPushButton::clicked, [this,i]{bypass(i);});
   }
}

bool buttons::bypass(int s)
{
    switch (s)
    {
    case 0:
        fileDoesExists(GRW, GRWSHA, ":/new/bypass/Bypasses/EasyAntiCheat_x64.dll");
        break;
    case 1:
        fileDoesExists(GRB, GRBSHA, ":/new/bypass/Bypasses/GRB_BE.exe");
        break;
    case 2:
        fileDoesExists(SAOFB, SAOFBSHA, ":/new/bypass/Bypasses/SAOFB_Launcher.exe");
        break;
    case 3:
        fileDoesExists(Outlaws, OutlawsSHA, ":/new/bypass/Bypasses/Outlaws-Win64-Shipping_BE (1).exe");
        break;
    case 4:
        fileDoesExists(SAOA, SAOASHA, ":/new/bypass/Bypasses/SAOA.exe");
        break;
    case 5:
        fileDoesExists(OPM, OPMSHA, ":/new/bypass/Bypasses/ONE PUNCH MAN A HERO NOBODY KNOWS (1).exe");
        break;
    case 6:
        fileDoesExists(DBZ, DBZSHA, ":/new/bypass/Bypasses/DBFighterZ.exe");
        break;
    case 7:
        fileDoesExists(DBX, DBXSHA,":/new/bypass/Bypasses/start.exe");
        break;
    case 8:
        fileDoesExists(SGWC, SGWCSHA, "::/new/bypass/Bypasses/SGWC.exe");
        break;
    default:
        break;
    }
    return true;
}

bool buttons::fileDoesExists(QString &filepath, QByteArray &byteArray, QString fileUrl)
{
    QFile file(filepath);
    QByteArray hashArray;
    QLabel* label = new QLabel();
    label->setMinimumSize(150,100);
    label->setMargin(20);
    //qDebug() << filepath << fileInfo.fileName();
    if(file.exists())
    {
        file.setPermissions(QFile::ReadOther | QFile::WriteOther);
        file.open(QFile::ReadWrite);
        QCryptographicHash fileHash(QCryptographicHash::Sha256);
        fileHash.addData(&file);
        hashArray = fileHash.result().toHex().toUpper();
        if(hashArray == byteArray)
        {
            if(file.rename(filepath + ".bak"))
            {
               if (QFile::copy(fileUrl, filepath))
               {
                   label->setText("Success! Bypass added.");
                   label->show();
               }
            }
            else
            {
                label->setText("Unable to replace rename file");
                label->show();
            }
        }
        else if (file.remove())
        {
            if(QFile::rename(filepath + ".bak", filepath))
            {
            label->setText("Orignal File Restored");
            label->show();
            }
        }

    }
    else
    {
        QDialog* fileWindow = new QDialog();
        QFileSystemModel* fileExplorer = new QFileSystemModel();
        QPushButton* select = new QPushButton("Select");
        QPushButton* cancel = new QPushButton("Cancel");
        fileExplorer->setRootPath("C:/");
        QTreeView* tree = new QTreeView();
        tree->setModel(fileExplorer);
        tree->setMinimumSize(600, 340);
        tree->setColumnWidth(0,200);
        tree->hideColumn(3);
        QGridLayout* layout = new QGridLayout();
        layout->addWidget(tree, 0, 0, 10, 20, Qt::AlignHCenter);
        layout->addWidget(select, 11, 17, Qt::AlignRight);
        layout->addWidget(cancel, 11, 19, Qt::AlignRight);
        fileWindow->setLayout(layout);
        fileWindow->setWindowTitle("File Explorer");
        fileWindow->setMinimumSize(600,400);
        fileWindow->setModal(true);
        fileWindow->show();
        QObject::connect(select, &QPushButton::clicked, [this, tree, fileExplorer, &filepath, fileWindow]() mutable {buttons::select(tree, fileExplorer, fileWindow, filepath);});
        QObject::connect(cancel, &QPushButton::clicked, [fileWindow]{fileWindow->close();});

    }
    file.close();
    return true;
}

void buttons::select(QTreeView* tree,QFileSystemModel* fileSystem, QDialog* dialog, QString &filePath)
{

    filePath = fileSystem->fileInfo(tree->currentIndex()).absoluteFilePath();
    qDebug() << filePath;
    dialog->close();
}
