#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QSystemTrayIcon>

#include <QMainWindow>
#ifdef PYTHON
#include <qtpython.h>
#endif

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


    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

signals:
void changeTextSignal();
        void settext();
        void qtPython();


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
