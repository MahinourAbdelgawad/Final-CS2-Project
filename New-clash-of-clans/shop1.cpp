#include "shop1.h"
#include "ui_shop1.h"
#include <QPixmap>
#include <QLabel>
#include <QMessageBox>
#include <QPushButton>
#include <QGraphicsPixmapItem>
#include <QString>
#include "playermoney.h"

Shop1::Shop1(QWidget *parent, int money1) : QDialog(parent), ui(new Ui::Shop1)
{
    ui->setupUi(this);
    setWindowTitle("Shop");
    QPixmap backgroundImage(":/images/shopbg.jpg");
    backgroundImage = backgroundImage.scaledToWidth(200);
    backgroundImage = backgroundImage.scaledToHeight(200);
    QLabel *backgroundLabel = new QLabel(this);
    backgroundLabel->setPixmap(backgroundImage);
    backgroundLabel->lower();
    backgroundLabel->setGeometry(0, 0, width(), height());
    QPixmap cannonImage(":/images/Cannon.png");
    QPixmap townhallImage(":/images/Castle.png");
    QPixmap fenceImage(":/images/Wall.png");
    townhallImage = townhallImage.scaledToWidth(50);
    townhallImage = townhallImage.scaledToHeight(50);

    QString backgroundImage1 = ":/images/Cannon.png";
    QString buttonStyle = "QPushButton {"
                          "    background-image: url(" + backgroundImage1 + ");"
                                               "    background-repeat: no-repeat;"
                                               "    background-position: center;"
                                               "}";

    ui->cannonbutton->setStyleSheet(buttonStyle);
    QSize buttonSize = ui->town->size();
    QPixmap scaledTownhallImage = townhallImage.scaled(buttonSize, Qt::KeepAspectRatio);
    QString backgroundImage2 =":/images/Castle.png";
    ":/images/Castle.png";
    scaledTownhallImage.save(backgroundImage2);

    QString buttonStyle2 = "QPushButton {"
                           "    background-image: url(" + backgroundImage2 + ");"
                                                "    background-repeat: no-repeat;"
                                                "    background-position: center;"
                                                "}";

    ui->town->setStyleSheet(buttonStyle2);

    QString backgroundImage3 = ":/images/Wall.png";
    QString buttonStyle3 = "QPushButton {"
                           "    background-image: url(" + backgroundImage3 + ");"
                                                "    background-repeat: no-repeat;"
                                                "    background-position: center;"
                                                "}";


    ui->fencebutton->setStyleSheet(buttonStyle3);

    money = new playerMoney();
    town = new Townhall();
    cannon = new Cannon();
    fence = new Fence1("");
    currentMoney = money->getCurrentMoney();;
}

Shop1::~Shop1()
{
    delete ui;
}

void Shop1::on_townHall_clicked()
{
    if (currentMoney >= 50) {
        newMoney = 50;
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Confirmation","Townhall upgrade cost: 50\nUpgrades: Townhall health increases by 50%\nWould you like to upgrade?", QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            money->setMoney(newMoney);
            type="Townhall";
            QPixmap newImage(":/images/Town_Hall9.png");
            newImage = newImage.scaledToWidth(50);
            newImage = newImage.scaledToHeight(50);
            int newHealth = 2000;
            // town->UpgradeButton();
            emit moneyChanged(newMoney);
            emit imagehealthChanges(type,newImage,newHealth);
        }
    } else {
        QMessageBox::critical(nullptr, "Insufficient Funds", "You do not have enough money for this upgrade.");
    }
}




void Shop1::onUpgradeApplied(const QPixmap& newImage, int newHealth)
{
    // Handle the upgrade applied signal from Cannon or Fence
    // Update the UI or perform any other necessary actions
}



int Shop1::sendMoney(){
    return newMoney;
}

void Shop1::on_fence_clicked()
{
    if (currentMoney >= 50) {
      newMoney = 50;

        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Confirmation", "Fence upgrade cost: 50\nUpgrades: Fence health increases by 50%\nWould you like to upgrade?", QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            money->setMoney(newMoney);
            type="Fence";
            QPixmap newImage(":/images/Wall3.png");
            newImage = newImage.scaledToWidth(50);
            newImage = newImage.scaledToHeight(50);

            int newHealth = 2000;
            //    fence->fenceHealth->setMaxHealth(newHealth);
            emit moneyChanged(newMoney);
            emit imagehealthChanges(type,newImage,newHealth);
        }

    } else {
        QMessageBox::critical(this, "Insufficient Funds", "You do not have enough money for this upgrade.");
    }
}


void Shop1::on_cannon_clicked()
{

    if (newMoney >= 0) {
         newMoney = 50;

        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Confirmation", "Cannon upgrade cost: 50\nUpgrades: Cannon health increases by 50%\nWould you like to upgrade?", QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            money->setMoney(newMoney);

            QPixmap newImage(":/images/Cannon10B.png");
            newImage = newImage.scaledToWidth(80);
            newImage = newImage.scaledToHeight(80);
            int newHealth = 2000;
            emit moneyChanged(newMoney);

            type="Cannon";
            emit imagehealthChanges(type,newImage,newHealth);
        }
    } else {
        QMessageBox::critical(nullptr, "Insufficient Funds", "You do not have enough money for this upgrade.");
    }
}

