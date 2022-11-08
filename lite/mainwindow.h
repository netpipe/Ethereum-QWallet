#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QSystemTrayIcon>

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

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

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
