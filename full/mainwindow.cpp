#include "mainwindow.h"
#include "ui_mainwindow.h"

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


void MainWindow::playsound(QString test){
#ifdef SOUND
    // player->setMedia(QUrl("qrc:/sounds/ec1_mono.ogg"));
    // player->setMedia(QUrl::fromLocalFile("./paddle_hit.wav"));
     //or play from memory
      QFile file(test.toLatin1());
      file.open(QIODevice::ReadOnly);
      QByteArray* arr = new QByteArray(file.readAll());
      file.close();
      QBuffer* buffer = new QBuffer(arr);
      buffer->open(QIODevice::ReadOnly);
      buffer->seek(0);
//qDebug() << "Media supported state -> " << QMediaPlayer::hasSupport("video/mp4"); // this gives a "1"
      player->setVolume(10);
 //    media->setMedia("sound.mp3");
     player->setMedia(QMediaContent(), buffer);
     player->play();
#endif
}

void MainWindow::AddRemoveTab(QWidget *tab,QString name,int tabindex){

    // QWidget * test= ui->app->widget(2);
    if (tab->isEnabled()) {
       // QWidget * test= ui->app->widget(2);
        ui->app->removeTab(tabindex);
        tab->setEnabled(false);
    } else {
        tab->setEnabled(true);
        QWidget * test= ui->app->widget(tabindex);
       // ui->app->removeTab(2);
//        if (tab->isVisible()){
            ui->app->insertTab(tabindex,removedTab,name.toLatin1());
//        }
    }
}


void MainWindow::on_usergenerateQr_clicked()
{
    QString qrstring =  ui->adduserEmail->text().toLatin1()+"::"+
                        ui->addusername->text().toLatin1()+"::"+
                        ui->lineEditPhone->text().toLatin1()+"::"+
                        ui->createuserdatetime->text().toLatin1()+"::"+
                        ui->createextra->text().toLatin1()+"::"+
                        ui->createclass->text().toLatin1();

    GenerateQRCode(qrstring,ui->adduserQRview);

}

void MainWindow::on_ftpserver_clicked()
{
#ifdef FTP
    if (adminftp==0){
    ftpgui = new FTPGUI;
    adminftp=1;
    }
    if (adminftp) { ftpgui->show();}
#endif
}

void MainWindow::on_ftpserver_clicked()
{
#ifdef FTP
    if (adminftp==0){
    ftpgui = new FTPGUI;
    adminftp=1;
    }
    if (adminftp) { ftpgui->show();}
#endif
}
