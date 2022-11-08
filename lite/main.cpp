#include "mainwindow.h"

#include <QApplication>
#include <QCommandLineParser>
#include <qdebug.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;

    //    QCommandLineParser parser;

    //    parser.setApplicationDescription("Application");
    //    parser.addVersionOption();
    //    QCommandLineOption test("test", QCoreApplication::translate("testFunction", "Show progress during copy"));
    //    parser.addOption(test);
    //     parser.process(a);
    //      //  const bool screen = parser.isSet(test);
    // qDebug() << parser.isSet(QStringLiteral("test"));
        QString string = argv[1];
        string.split('&');
       // QRegExp rx("[& ]");// match a comma or a space
    //QStringList list = string.split(rx, QString::SkipEmptyParts);
    //  qDebug() << list[1] << endl;
        QRegExp regex;
        regex.setPattern("tx=([^\\\\]+)");

        QString hexvalue = "";
        int pos = regex.indexIn(string, 0);
        if (pos >= 0)
        {
            QString strName = regex.cap(0);
            hexvalue = strName.mid(7);
            pos += hexvalue.length();
        }

         qDebug() << hexvalue;

    w.show();

      qDebug() << string[0] << endl;

    return a.exec();
}
