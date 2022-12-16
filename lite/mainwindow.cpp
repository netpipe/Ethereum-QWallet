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

//'3'			=> array('rpc'=> 'https://rpc.ankr.com/eth_ropsten',	'name'=> 'Ropsten test network'),
//'4'			=> array('rpc'=> 'https://rpc.ankr.com/eth_rinkeby',	'name'=> 'Rinkeby test network'),
//'5'			=> array('rpc'=> 'https://rpc.ankr.com/eth_goerli',		'name'=> 'Goerli test network'),
//'11155111'	=> array('rpc'=> 'https://nunki.htznr.fault.dev/rpc', 	'name'=> 'Sepolia test network'),
//'97'		=> array('rpc'=> 'https://nunki.htznr.fault.dev/rpc',	'name'=> 'Binance Smart Chain Testnet '),
//'31337'		=> array('rpc'=> 'http://localhost:8545', 'name'=> 'Localhost:8545'),
//'1337'		=> array('rpc'=> 'http://localhost:8545', 'name'=> 'Localhost:8545'),
//'2000'      => array('rpc'=> 'https://rpc-us.dogechain.dog', 'name'=> 'Dogechain Mainnet')


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

        m_db = QSqlDatabase::addDatabase("QSQLITE");
        createTable("./address_book.db");



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
void MainWindow::Onload_db()
{
    while(ui->send_tb->rowCount()){
        ui->send_tb->removeRow(0);
    }
    while(ui->receive_tb->rowCount())
    {
        ui->receive_tb->removeRow(0);
    }
    sendrecord_list.clear();
    receiverecord_list.clear();
    QSqlQuery query_send("SELECT * FROM Send_tb;");
    int cnt = 0;
    while (query_send.next())
    {
        int tb_id = query_send.value(0).toInt();
        QString tb_addr = query_send.value(1).toString();
        QString tb_name = query_send.value(2).toString();
        QTableWidgetItem *item_addr = new QTableWidgetItem(tb_addr);
        QTableWidgetItem *item_name = new QTableWidgetItem(tb_name);
        ui->send_tb->insertRow(cnt);
        ui->send_tb->setItem(cnt, 0, item_addr);
        ui->send_tb->setItem(cnt, 1, item_name);
        record_pattern record;
        record.id = tb_id;
        record.addr = tb_addr;
        record.name = tb_name;
        sendrecord_list.append(record);
        cnt++;
    }
    QSqlQuery query_receive("SELECT * FROM Receive_tb;");
    cnt = 0;
    while (query_receive.next())
    {
        int tb_id = query_receive.value(0).toInt();
        QString tb_addr = query_receive.value(1).toString();
        QString tb_name = query_receive.value(2).toString();
        QTableWidgetItem *item_addr = new QTableWidgetItem(tb_addr);
        QTableWidgetItem *item_name = new QTableWidgetItem(tb_name);
        ui->receive_tb->insertRow(cnt);
        ui->receive_tb->setItem(cnt, 0, item_addr);
        ui->receive_tb->setItem(cnt, 1, item_name);
        record_pattern record;
        record.id = tb_id;
        record.addr = tb_addr;
        record.name = tb_name;
        receiverecord_list.append(record);
        cnt++;
    }

}




void MainWindow::on_addressadd_clicked()
{
    QString Addr_str = ui->addr_add->text();
    QString Name_str = ui->name_add->text();
    QString query_str = QString("INSERT INTO '%1'(Address, Name) VALUES ('%2', '%3');");
    if(ui->tabWidget_2->currentWidget()==ui->send_tab)
    {
       query_str= query_str.arg("Send_tb").arg(Addr_str).arg(Name_str);
        QSqlQuery query_add(query_str);
    }
    if(ui->tabWidget_2->currentWidget()==ui->receive_tab)
    {
        query_str=query_str.arg("Receive_tb").arg(Addr_str).arg(Name_str);
        QSqlQuery query_add(query_str);
    }
    Onload_db();
}

void MainWindow::on_addressremove_clicked()
{
    QString query_str = QString("DELETE FROM '%1' WHERE id = %2;");
    if(ui->tabWidget_2->currentWidget()==ui->send_tab)
    {
        int row_cnt = ui->send_tb->currentRow();
        int id = sendrecord_list.at(row_cnt).id;
        query_str= query_str.arg("Send_tb").arg(id);
        QSqlQuery query_add(query_str);
    }
    if(ui->tabWidget_2->currentWidget()==ui->receive_tab)
    {
        int row_cnt = ui->receive_tb->currentRow();
        int id = sendrecord_list.at(row_cnt).id;
        query_str= query_str.arg("Receive_tb").arg(id);
        QSqlQuery query_add(query_str);
    }
    Onload_db();
}

void MainWindow::on_addresssave_clicked()
{
    QString query_str = QString("UPDATE '%1' SET Address = '%2', Name = '%3' WHERE id = %4;");
    if(ui->tabWidget_2->currentWidget()==ui->send_tab)
    {
        int row_cnt = ui->send_tb->currentItem()->row();
        int id = sendrecord_list.at(row_cnt).id;

        QString Addr_str_tab = ui->send_tb->item(row_cnt,0)->text();
        QString Name_str_tab = ui->send_tb->item(row_cnt,1)->text();

        QString addr_str_txt = ui->addr_add->text();
        QString name_str_txt = ui->name_add->text();
        if(Addr_str_tab != sendrecord_list.at(row_cnt).addr | Name_str_tab != sendrecord_list.at(row_cnt).name)
        {
            query_str= query_str.arg("Send_tb").arg(Addr_str_tab).arg(Name_str_tab).arg(id);
        }
        if(addr_str_txt != sendrecord_list.at(row_cnt).addr | name_str_txt != sendrecord_list.at(row_cnt).name)
        {
            query_str= query_str.arg("Send_tb").arg(addr_str_txt).arg(name_str_txt).arg(id);
        }
        QSqlQuery query_add(query_str);
    }
    if(ui->tabWidget_2->currentWidget()==ui->receive_tab)
    {
        int row_cnt = ui->receive_tb->currentItem()->row();
        int id = receiverecord_list.at(row_cnt).id;

        QString Addr_str_tab = ui->receive_tb->item(row_cnt,0)->text();
        QString Name_str_tab = ui->receive_tb->item(row_cnt,1)->text();

        QString addr_str_txt = ui->addr_add->text();
        QString name_str_txt = ui->name_add->text();
        if(Addr_str_tab != receiverecord_list.at(row_cnt).addr | Name_str_tab != receiverecord_list.at(row_cnt).name)
        {
            query_str= query_str.arg("Receive_tb").arg(Addr_str_tab).arg(Name_str_tab).arg(id);
        }
        if(addr_str_txt != receiverecord_list.at(row_cnt).addr | name_str_txt != receiverecord_list.at(row_cnt).name)
        {
            query_str= query_str.arg("Receive_tb").arg(addr_str_txt).arg(name_str_txt).arg(id);
        }
        QSqlQuery query_add(query_str);
    }
    Onload_db();
}
void MainWindow::createTable(QString DBname)
{
    m_db.setDatabaseName(DBname.toLatin1());

    if(m_db.open())
    {
        qDebug()<<"Successful coin database connection";
    }
    else
    {
        qDebug()<<"Error: failed database connection";
    }

    QString query;
    query.append("CREATE TABLE IF NOT EXISTS Send_tb("
                 "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                 "Address VARCHAR(50),""Name VARCHAR(50));");
    query.append("CREATE TABLE IF NOT EXISTS Receive_tb("
                 "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                 "Address VARCHAR(50),""Name VARCHAR(50));");
    QSqlQuery create;

    create.prepare(query);

    if (create.exec())
    {
        qDebug()<<"Table exists or has been created";
    }
    else
    {
        qDebug()<<"Table not exists or has not been created";
        //qDebug()<<"ERROR! "<< create.lastError();
    }

    query.clear();
 //   db.close();

}
