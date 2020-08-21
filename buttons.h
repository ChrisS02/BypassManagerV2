#ifndef BUTTONS_H
#define BUTTONS_H
#include <QVBoxLayout>
#include <QTreeView>
#include <QFileSystemModel>
#include <QDialog>
#include <QByteArray>

class buttons
{
private:
    QStringList games = {"Ghost Recon Wildlands", "Ghost Recond BreakPoint", "Sword Art Online Fatal Bullet", "Outlaws of the Old West", "Sword Art Online Alicization",
                         "One Punch Man", "Dragon Ball Fighter Z", "Dragon Ball Xenoverse 2", "Sniper Ghost Warrior Contracts" };
    QStringList thumbs = {":/new/thumbails/Thumbnails/GRW.jpg", ":/new/thumbails/Thumbnails/GRB.jpg", ":/new/thumbails/Thumbnails/SAOFB.jpg", ":/new/thumbails/Thumbnails/OOTOW.jpg", ":/new/thumbails/Thumbnails/SAOA.jpg",
                         ":/new/thumbails/Thumbnails/OPM.jpg", ":/new/thumbails/Thumbnails/DBFZ.jpg", ":/new/thumbails/Thumbnails/DBX2.jpg", ":/new/thumbails/Thumbnails/SGWC.jpg"};
    bool fileDoesExists(QString&, QByteArray&, QString);
    QString GRW = "C:/Program Files (x86)/Ubisoft/Ubisoft Game Launcher/games/Ghost Recon Breakpoint/GRB_BE.exe";
    QString GRB = "C:/Program Files (x86)/Steam/steamapps/common/games/Tom Clancy's Ghost Recon Wildlands/EasyAntiCheat/EasyAntiCheat_x64.dll";
    QString SAOFB = "C:/Program Files (x86)/Steam/steamapps/common/SWORD ART ONLINE FATAL BULLET/SAOFB_Launcher.exe"; //C:/Program Files (x86)/Steam/steamapps/common/
    QString Outlaws = "C:/Program Files (x86)/Steam/steamapps/common/Outlaws of the Old West/Outlaws/Binaries/Win64/Outlaws-Win64-Shipping_BE.exe";
    QString SAOA = "C:/Program Files (x86)/Steam/steamapps/common/SWORD ART ONLINE Alicization Lycoris/Launch_Game.exe";
    QString OPM = "C:/Program Files (x86)/Steam/steamapps/common/ONE PUNCH MAN A HERO NOBODY KNOWS/ONE PUNCH MAN A HERO NOBODY KNOWS.exe";
    QString DBZ = "C:/Program Files (x86)/Steam/steamapps/common/DRAGON BALL FighterZ/DBFighterZ.exe";
    QString DBX = "C:/Program Files (x86)/Steam/steamapps/common/DB Xenoverse 2/start.exe";
    QString SGWC = "C:/Program Files (x86)/Steam/steamapps/common/Sniper Ghost Warrior Contracts/Launch_Game.exe";
    QByteArray GRBSHA = "33B3F29838D6CF028A9B6F96761A1C878E04E860FFF7BEA0798BB1328DB5CDFF";
    QByteArray GRWSHA = "A39290DB691AD93BC75B36DD4A2C32DE314B415FEADC21F0389B441F13FDFBAC";
    QByteArray SAOFBSHA = "F345F050EDE8F6B0891B3E1317A6A9E57C0D64FBFB9594BD42CCFA9B932F37F6";
    QByteArray SAOASHA = "AEAABC7230D60CCBBDEBCCAFC45E72921BB5E24EB13A1457B497E2ABAD66C75B";
    QByteArray OutlawsSHA = "584CDE4E61219E445D818D1324A06A5D2DDB4E5E3015ABE6764CA1FE1F64BBEE";
    QByteArray OPMSHA = "1ED437CB075DB040B145F29A57666DAF5AE4B1C30A061170D56285D58E4123DA";
    QByteArray DBZSHA = "2E4EFE2AD5342E19A7C42F0164CBA3D8DA15C001197B8365353E556884A75033";
    QByteArray DBXSHA = "B4A58E99C4E9CE9DFF373FF81C4A4BC2B27BB9D81C72E22110AF674BB916367B";
    QByteArray SGWCSHA = "91971C898AE356E14BD4D8226F59352402FDD1BE1AE273CBD6F7EE865AFA0D6C";

public:
    buttons(QVBoxLayout*);

public slots:
    bool bypass(int);
    void select(QTreeView*,QFileSystemModel*, QDialog*, QString&);

};

#endif // BUTTONS_H
