#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QSystemTrayIcon>
#include <QNetworkReply>
#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QList>
#include <QNetworkAccessManager>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    class record_pattern
    {
    public:
        int id;
        QString addr;
        QString name;
    };

public:
    QNetworkAccessManager* manager;
    void Onload_db();
    QList<record_pattern> sendrecord_list;
    QList<record_pattern> receiverecord_list;

    void createTable(QString);
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionExit_triggered();

    void showMessage();
    void iconActivated(QSystemTrayIcon::ActivationReason reason);
    void on_pushButton_2_clicked();

    void on_tosendbrt_clicked();

    void on_papergenera_clicked();

    void on_papersendbutton_clicked();

    void on_messagesignbtn_clicked();

    void on_messageverifybtn_clicked();

    void on_messagehashbtn_clicked();

    void on_addressadd_clicked();

    void on_addressremove_clicked();

    void on_addresssave_clicked();



public:
    void getTransactionCommand(std::string transaction_str);
    void getTransactionInputCommand(std::string transaction_str);
    void getTransactionOuputCommand(std::string transaction_str);
    void sendTransactionCommand(std::string transaction_str);

protected slots:
    void getTransactionFinish(QNetworkReply *rep);
    void sendTransactionFinish(QNetworkReply *rep);


private:
    Ui::MainWindow *ui;

        QSqlDatabase m_db;
};
#endif // MAINWINDOW_H
