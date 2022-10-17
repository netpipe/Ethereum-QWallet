QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
LIBS += -ljsonrpccpp-client -ljsoncpp -lcurl

SOURCES += \
    api.cpp \
    crypto/keccak256.c \
    crypto/uECC.c \
    extra/QRCode/QrCode.cpp \
    extra/dbus/main.cpp \
    extra/downloadmanager.cpp \
    extra/encryption/Qt-AES/qaesencryption.cpp \
    extra/encryption/rsa/Rsa.cpp \
    extra/encryption/simpleCrypt/simplecrypt.cpp \
    extra/ftp-server/dataconnection.cpp \
    extra/ftp-server/debuglogdialog.cpp \
    extra/ftp-server/ftpcommand.cpp \
    extra/ftp-server/ftpcontrolconnection.cpp \
    extra/ftp-server/ftpgui.cpp \
    extra/ftp-server/ftplistcommand.cpp \
    extra/ftp-server/ftpretrcommand.cpp \
    extra/ftp-server/ftpserver.cpp \
    extra/ftp-server/ftpstorcommand.cpp \
    extra/ftp-server/sslserver.cpp \
    extra/loadtheme.cpp \
    extra/qstylesheetmanager.cpp \
    extra/quazip/JlCompress.cpp \
    extra/quazip/qioapi.cpp \
    extra/quazip/quaadler32.cpp \
    extra/quazip/quacrc32.cpp \
    extra/quazip/quagzipfile.cpp \
    extra/quazip/quaziodevice.cpp \
    extra/quazip/quazip.cpp \
    extra/quazip/quazipdir.cpp \
    extra/quazip/quazipfile.cpp \
    extra/quazip/quazipfileinfo.cpp \
    extra/quazip/quazipnewinfo.cpp \
    extra/quazip/unzip.c \
    extra/quazip/zip.c \
    extra/smtp/emailaddress.cpp \
    extra/smtp/mimeattachment.cpp \
    extra/smtp/mimecontentformatter.cpp \
    extra/smtp/mimefile.cpp \
    extra/smtp/mimehtml.cpp \
    extra/smtp/mimeinlinefile.cpp \
    extra/smtp/mimemessage.cpp \
    extra/smtp/mimemultipart.cpp \
    extra/smtp/mimepart.cpp \
    extra/smtp/mimetext.cpp \
    extra/smtp/quotedprintable.cpp \
    extra/smtp/smtpclient.cpp \
    extra/zlib/adler32.c \
    extra/zlib/compress.c \
    extra/zlib/crc32.c \
    extra/zlib/deflate.c \
    extra/zlib/gzclose.c \
    extra/zlib/gzlib.c \
    extra/zlib/gzread.c \
    extra/zlib/gzwrite.c \
    extra/zlib/infback.c \
    extra/zlib/inffast.c \
    extra/zlib/inflate.c \
    extra/zlib/inftrees.c \
    extra/zlib/trees.c \
    extra/zlib/uncompr.c \
    extra/zlib/zutil.c \
    factory.cpp \
    main.cpp \
    mainwindow.cpp \
    rlp/RLP.c \
    rlp/tx.c \
    utils.c \
    wrapper.cpp

HEADERS += \
    api.hpp \
    crypto/cr_types.h \
    crypto/curve-specific.inc \
    crypto/keccak256.h \
    crypto/platform-specific.inc \
    crypto/uECC.h \
    crypto/uECC_vli.h \
    extra/Barcode/functii.h \
    extra/Barcode/quirc/lib/quirc.h \
    extra/Barcode/quirc/lib/quirc_internal.h \
    extra/Barcode/quirc/tests/dbgutil.h \
    extra/Barcode/quirc/tests/inspect.h \
    extra/Barcode/scanner.h \
    extra/QRCode/QrCode.hpp \
    extra/coinfunctions.h \
    extra/coingenerator.h \
    extra/dbus/dbushandler.h \
    extra/downloadmanager.h \
    extra/email.h \
    extra/encryption/Qt-AES/qaesencryption.h \
    extra/encryption/encryption.h \
    extra/encryption/rsa/Rsa.h \
    extra/encryption/simpleCrypt/simplecrypt.h \
    extra/ftp-server/dataconnection.h \
    extra/ftp-server/debuglogdialog.h \
    extra/ftp-server/ftpcommand.h \
    extra/ftp-server/ftpcontrolconnection.h \
    extra/ftp-server/ftpgui.h \
    extra/ftp-server/ftplistcommand.h \
    extra/ftp-server/ftpretrcommand.h \
    extra/ftp-server/ftpserver.h \
    extra/ftp-server/ftpstorcommand.h \
    extra/ftp-server/sslserver.h \
    extra/loadtheme.h \
    extra/qstylesheetmanager.h \
    extra/quazip/JlCompress.h \
    extra/quazip/crypt.h \
    extra/quazip/ioapi.h \
    extra/quazip/quaadler32.h \
    extra/quazip/quachecksum32.h \
    extra/quazip/quacrc32.h \
    extra/quazip/quagzipfile.h \
    extra/quazip/quaziodevice.h \
    extra/quazip/quazip.h \
    extra/quazip/quazip_global.h \
    extra/quazip/quazipdir.h \
    extra/quazip/quazipfile.h \
    extra/quazip/quazipfileinfo.h \
    extra/quazip/quazipnewinfo.h \
    extra/quazip/unzip.h \
    extra/quazip/zip.h \
    extra/smtp/SmtpMime \
    extra/smtp/emailaddress.h \
    extra/smtp/mimeattachment.h \
    extra/smtp/mimecontentformatter.h \
    extra/smtp/mimefile.h \
    extra/smtp/mimehtml.h \
    extra/smtp/mimeinlinefile.h \
    extra/smtp/mimemessage.h \
    extra/smtp/mimemultipart.h \
    extra/smtp/mimepart.h \
    extra/smtp/mimetext.h \
    extra/smtp/quotedprintable.h \
    extra/smtp/smtpclient.h \
    extra/smtp/smtpexports.h \
    extra/ssl.h \
    extra/zlib/crc32.h \
    extra/zlib/deflate.h \
    extra/zlib/gzguts.h \
    extra/zlib/inffast.h \
    extra/zlib/inffixed.h \
    extra/zlib/inflate.h \
    extra/zlib/inftrees.h \
    extra/zlib/trees.h \
    extra/zlib/zconf.h \
    extra/zlib/zlib.h \
    extra/zlib/zutil.h \
    factory.hpp \
    mainwindow.h \
    rlp/RLP.h \
    rlp/tx.h \
    types.hpp \
    utils.h \
    wrapper.hpp

FORMS += \
    extra/ftp-server/debuglogdialog.ui \
    extra/ftp-server/ftpgui.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
    extra/encryption/Qt-AES/qaesencryption.pro \
    extra/encryption/rsa/Rsa.pro

RESOURCES += \
    extra/encryption/Qt-AES/res.qrc

DISTFILES += \
    extra/encryption/Qt-AES/README.md \
    extra/encryption/simpleCrypt/use
