#ifndef TCP_H
#define TCP_H

#include <QObject>
#include <QtNetwork>

 class Tcp : public QObject
 {
     Q_OBJECT

 public:
     Tcp(QObject *parent = 0);

 public slots:
     void send(quint8 comando, QString s);

 private slots:
     void readyRead();
     void displayError(QAbstractSocket::SocketError socketError);
     void reconnect();

 signals:
     void newCommand(quint8 comando, QString s);

 private:
     QTcpSocket *tcpSocket;
     quint16 blockSize;

 };

 #endif
