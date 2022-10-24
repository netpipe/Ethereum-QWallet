#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"

#include "src/ethereum/api.hpp"
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

//void MainWindow::on_pushButton_2_clicked()
//{
   // VerifyMessage
 //   VerifyMessage(std::string& publicKey, std::string& msgHash, std::string& signature);
       //    test->CreatePair();
   // test->privateKey = "123123123";
 //   test->PublicKey();

//    CreateRawTransaction(        std::string& nonce,
//        std::string& gasPrice,
//        std::string& gasLimit,
//        std::string& to,
//        std::string& value,
//        std::string& data
//    )

//CreateRawTransaction(  'nonce: "0x1e7"','gasPrice: "0x2e90edd000"', 'gasLimit: "0x30d40"','to: "0xbd064928cdd4fd67fb99880e6560978d7ca1"','value: "0xde0b6b3a7640000"',   'data: "0x"');

//            QString nonce= 'nonce: "' << ui->
//  CreateRawTransaction(



//            const transaction = {
//              nonce: '0x1e7',
//              gasPrice: '0x2e90edd000',
//              gasLimit: '0x30d40',
//              to: '0xbd064928cdd4fd67fb99917c880e6560978d7ca1',
//              value: '0xde0b6b3a7640000',
//              data: '0x'
//            };


//}
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

void MainWindow::on_pushButton_clicked()
{

}
//ui->edt_log->installEventFilter(this);
//ui->edt_log->setLineWrapMode(QTextEdit::WidgetWidth);

//m_process = new QProcess(this);
//m_process->setReadChannelMode(QProcess::MergedChannels);
//connect(m_process, SIGNAL(readyReadStandardOutput()), this, SLOT(showOutput()));

//QString program = "./myscript.sh";
//m_process->start("/bin/sh", QStringList() << program, QIODevice::ReadWrite);


//void Qonsole::execute()
//{
//    QString cmd_str = ui->edt_input->toPlainText();

//    ui->edt_input->clear();
//    ui->edt_log->append(cmd_str);

//    QByteArray bytes = cmd_str.toUtf8();
//    m_process->write(bytes);
//}

//void Qonsole::showOutput()
//{
//    QByteArray bytes = m_process->readAllStandardOutput();

//    QStringList lines = QString(bytes).split("\n");

//    foreach (QString line, lines) {
//        ui->edt_log->append(line);
//    }

//}

//bool Qonsole::eventFilter(QObject *watched, QEvent *event)
//{
//    if( event->type() == QEvent::KeyPress )
//    {
//        QKeyEvent* key_event = static_cast<QKeyEvent*>(event);
//        int key = key_event->key();
//        QString key_str = key_event->text();

//        ui->edt_input->insertPlainText(key_str);

//        if ( (key == Qt::Key_Return) || (key == Qt::Key_Enter) )
//        {
//            execute();
//            return true;
//        }
//        else
//        {
//            //ui->edt_log->insertPlainText(key_str);
//            return true;
//        }
//    }

//    return QMainWindow::eventFilter(watched, event);
//}



//void Qonsole::on_pushButton_clicked()
//{
//  //  ui->edt_input->insertPlainText("key_str");

//    execute();
// //   showOutput();
//}


void MainWindow::on_pushButton_2_clicked()
{

        qtPython();
        settext();



}
