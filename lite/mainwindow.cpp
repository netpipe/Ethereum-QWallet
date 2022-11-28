#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"


#include "QJsonObject"
#include <QJsonDocument>
#include <QFile>
#include <QJsonObject>
#include <qstring.h>
#include <QTextStream>
#include <QStringListModel>

#include "api.hpp"
#include <QMessageBox>
#include <QUrlQuery>

    Wrapper *wr=new Wrapper();

    Factory *test=new Factory(wr,"testo");

     Keypair testkeypair;

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

    //   QJsonObject jsonObj ;
QJsonObject content;
        QJsonDocument document;
        document.setObject( content );
        QFile file( "test.test" );

        QString mName;





       if( file.open( QIODevice::ReadOnly ) )
       {
           QByteArray bytes = file.readAll();
           file.close();

           QJsonParseError jsonError;
           QJsonDocument document = QJsonDocument::fromJson( bytes, &jsonError );
           if( jsonError.error != QJsonParseError::NoError )
           {
               qDebug() << "fromJson failed: " ;//<< jsonError.errorString().toStdString() << endl;
               return ;
           }
           if( document.isObject() )
           {
               QJsonObject jsonObj = document.object();
               if (jsonObj.contains("FirstName") && jsonObj["FirstName"].isString())
                   mName = jsonObj["FirstName"].toString();

               qDebug() << mName.toLatin1() << "test";
           }
        }




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


}
//	std::string HashMessage(std::string& msg);
//std::string SignMessage(std::string& msgHash);

void MainWindow::on_tosendbrt_clicked()
{
//check if wallet loaded
    //verify address

            std::string snoonce = "nonce: ";
                   snoonce +=ui->confignonce->text().toLatin1().toStdString();
            std::string sgasPrice = "gasPrice: "; // check against limit
            sgasPrice +=ui->gasprice->text().toStdString();
            std::string sgasLimit = "gasLimit: ";
            sgasLimit+=ui->gaslimit->text().toStdString();
            std::string sto ="to: " ;
            sto+=ui->toaddress->text().toStdString(); // check if empty value
            std::string svalue =  "value: ";
            svalue+=ui->toammount->text().toStdString(); // check max ammount // check if higher than balance
            std::string sdata ="data: ";
                    sdata+=ui->configdata->text().toStdString();

//                    std::string snoonce = "nonce: '0x1e7'";
//                    std::string sgasPrice = "gasPrice: '0x2e90edd000'"; // check against limit
//                    std::string sgasLimit = "gasLimit: '0x30d40'";
//                    std::string sto ="to: '0xbd064928cdd4fd67fb99880e6560978d7ca1'" ;
//                    std::string svalue = "value: '0xde0b6b3a7640000'";
//                    std::string sdata ="data: '0x'";

                    Factory *test = new Factory(wr, "testo");
                    Keypair testPair = test->CreatePair();

                    std::string transaction_result = test->CreateRawTransaction(snoonce, sgasPrice, sgasLimit, sto, svalue, sdata, testPair.privateKey);

    qDebug() << test->CreateRawTransaction(snoonce,sgasPrice,sgasLimit,sto,svalue,sdata, testPair.privateKey).c_str();

    ui->toprivatekey->addItem(QString::fromStdString(test->CreateRawTransaction(snoonce,sgasPrice,sgasLimit,sto,svalue,sdata, testPair.privateKey).c_str()));


    Api api_test(wr);
  //  api_test.RawTransaction(transaction_result);

        getTransactionInputCommand("6f47f0b2e1ec762698a9b62fa23b98881b03d052c9d8cb1d16bb0b04eb3b7c5b");

    delete test;
    delete wr;

}


void MainWindow::on_papergenera_clicked()
{
    testkeypair= test->CreatePair();
    ui->paperprivatekey_2->setText(testkeypair.privateKey.c_str());
    ui->paperpublickey->setText(testkeypair.publicKey.c_str());

    qDebug() << testkeypair.privateKey.c_str()  << testkeypair.publicKey.c_str();
}


void MainWindow::on_papersendbutton_clicked()
{
    // if privatekey blank then try the keypair
    //check balance is enough before send.
}


void MainWindow::on_messagesignbtn_clicked()
{
         testkeypair= test->CreatePair();
    std::string test1 = ui->message->toPlainText().toStdString();
    test->SignMessage(test1);
}


void MainWindow::on_messageverifybtn_clicked()
{
      //       test->VerifyMessage()//VerifyMessage(std::string& publicKey, std::string& msgHash, std::string& signature)
}


void MainWindow::on_messagehashbtn_clicked()
{
    std::string test1 = ui->message->toPlainText().toStdString();

       ui->hash->setText( test->HashMessage(test1).c_str());
}



void MainWindow::getTransactionCommand(std::string transaction_str)
{
    QNetworkAccessManager * mgr = new QNetworkAccessManager(this);
    connect(mgr,SIGNAL(finished(QNetworkReply*)), this, SLOT(getTransactionFinish(QNetworkReply*)));

    QString url_path ="https://dogechain.info/api/v1/transaction/";
    url_path += QString::fromLatin1(transaction_str.c_str());

    QUrl url(url_path);
    QNetworkRequest request(url);

    mgr->get(request);
}

void MainWindow::getTransactionInputCommand(std::string transaction_str)
{
    QNetworkAccessManager * mgr = new QNetworkAccessManager(this);
    connect(mgr,SIGNAL(finished(QNetworkReply*)), this, SLOT(getTransactionFinish(QNetworkReply*)));

    QString url_path ="https://chain.so/api/v2/get_tx_inputs/DOGE/";
    url_path += QString::fromLatin1(transaction_str.c_str());

    QUrl url(url_path);
    QNetworkRequest request(url);


    QString filename = "Data.txt";
    QFile file2(filename);
    if (file2.open(QIODevice::ReadWrite)) {
        QTextStream stream(&file2);
        stream <<    mgr->get(request) << endl;
    }


    //   QJsonObject jsonObj ;
QJsonObject content;
        QJsonDocument document;
        document.setObject( content );
        QFile file( "Data.txt" );

        QString mName;





       if( file.open( QIODevice::ReadOnly ) )
       {
           QByteArray bytes = file.readAll();
           file.close();

           QJsonParseError jsonError;
           QJsonDocument document = QJsonDocument::fromJson( bytes, &jsonError );
           if( jsonError.error != QJsonParseError::NoError )
           {
               qDebug() << "fromJson failed: " ;//<< jsonError.errorString().toStdString() << endl;
               return ;
           }
           if( document.isObject() )
           {
               QJsonObject jsonObj = document.object();
               if (jsonObj.contains("FirstName") && jsonObj["FirstName"].isString())
                   mName = jsonObj["FirstName"].toString();

               qDebug() << mName.toLatin1() << "test";
           }
        }



}

void MainWindow::getTransactionOuputCommand(std::string transaction_str)
{
    QNetworkAccessManager * mgr = new QNetworkAccessManager(this);
    connect(mgr,SIGNAL(finished(QNetworkReply*)), this, SLOT(getTransactionFinish(QNetworkReply*)));

    QString url_path ="https://chain.so/api/v2/get_tx_outputs/DOGE/";
    url_path += QString::fromLatin1(transaction_str.c_str());

    QUrl url(url_path);
    QNetworkRequest request(url);

    mgr->get(request);
}

void MainWindow::sendTransactionCommand(std::string transaction_str)
{
//    QNetworkAccessManager * mgr = new QNetworkAccessManager(this);
//    connect(mgr,SIGNAL(finished(QNetworkReply*)), this, SLOT(sendTransactionFinish(QNetworkReply*)));

//    QString url_path ="https://chain.so/api/v2/send_tx/DOGE";

//    QUrl url(url_path);
//    QNetworkRequest request(url);

//    QUrlQuery params;
//    params.addQueryItem("tx_hex", transaction_str.c_str());

//    mgr->post(request, params.query().toUtf8());

    QNetworkAccessManager * mgr = new QNetworkAccessManager(this);
    connect(mgr,SIGNAL(finished(QNetworkReply*)), this, SLOT(sendTransactionFinish(QNetworkReply*)));

    QString url_path ="https://dogechain.info/api/v1/pushtx";

    QUrl url(url_path);
    QNetworkRequest request(url);

    QUrlQuery params;
    params.addQueryItem("tx_hash", transaction_str.c_str());

    mgr->post(request, params.query().toUtf8());
}

void MainWindow::getTransactionFinish(QNetworkReply *rep)
{
    QByteArray bts = rep->readAll();
    QString str(bts);
    QMessageBox::information(this, "Get Transcation", str, "ok");
}

void MainWindow::sendTransactionFinish(QNetworkReply *rep)
{
    QByteArray bts = rep->readAll();
    QString str(bts);
    QMessageBox::information(this, "Send Transcation", str, "ok");
}
