#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"

#include "api.hpp"
    Wrapper *wr=new Wrapper();

    Factory *test=new Factory(wr,"testo");

QSystemTrayIcon *trayIcon;
QMenu *trayIconMenu;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap oPixmap(32,32);
    oPixmap.load ( "smoking.png");

    QIcon oIcon( oPixmap );

    trayIcon = new QSystemTrayIcon(oIcon);

    QAction *quit_action = new QAction( "Exit", trayIcon );
    connect( quit_action, SIGNAL(triggered()), this, SLOT(on_exit()) );

    trayIconMenu = new QMenu(this);
    trayIconMenu->addAction( quit_action );

    trayIcon->setContextMenu( trayIconMenu);
    trayIcon->setVisible(true);
    //trayIcon->showMessage("Test Message", "Text", QSystemTrayIcon::Information, 1000);
    //trayIcon->show();



 Keypair testkeypair;

   testkeypair= test->CreatePair();
   qDebug() << testkeypair.privateKey.c_str()  << testkeypair.publicKey.c_str();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionExit_triggered()
{
    QApplication::exit();
}

void MainWindow::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason)
    {
     case QSystemTrayIcon::Trigger:
         this->show();
         break;
     case QSystemTrayIcon::DoubleClick:
         this->show();
         break;
     case QSystemTrayIcon::MiddleClick:
      //  showMessage();
        break;

     default:
         ;
    }
}
void MainWindow::showMessage()
{
    QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::MessageIcon();
    trayIcon->showMessage(tr("QSatisfy"), tr("Will you smoke now..."), icon, 100);
}

void MainWindow::on_pushButton_2_clicked()
{
   // VerifyMessage
 //   VerifyMessage(std::string& publicKey, std::string& msgHash, std::string& signature);
       //    test->CreatePair();
   // test->privateKey = "123123123";
 //   test->PublicKey();

}
//	std::string HashMessage(std::string& msg);
//std::string SignMessage(std::string& msgHash);



//std::string Factory::CreateRawTransaction(
//	std::string& nonce,
//	std::string& gasPrice,
//	std::string& gasLimit,
//	std::string& to,
//	std::string& value,
//	std::string& data
//)
