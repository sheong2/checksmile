#include "rcvthread.h"
#include "mainwindow.h"
#define SERVER_IP_ADDR "192.168.10.1"
#define PORT_ADDR 25000
#include <QTimer>

rcvThread::rcvThread(QObject *parent) :
    QThread(parent)
{
    socket = new QUdpSocket(this);
    socket->bind(PORT_ADDR);
    printf("bound\n");
    connect(socket, SIGNAL(readyRead()),this, SLOT(read_data()));
}

void rcvThread::read_data()
{
    printf("get\n");
    while (socket->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(socket->pendingDatagramSize());
        QHostAddress sender;
        quint16 senderPort;

        socket->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);

        char *temp = datagram.data();

        switch(temp[0])
        {
        case('L') : emit login_result(temp[1]=='T'); break;
        case('D') : emit dup_id_result(temp[1]=='T'); break;
        case('I') : emit readydata(datagram); break;
        case('w') :
        case('h') :
        case('a') :
        case('s') : emit set_tab(datagram.mid(1,3).toInt()); break;
        default : printf("wrong\n");
        }
    }
}

void rcvThread::send_data(QByteArray datagram)
{
    socket->writeDatagram(datagram,QHostAddress(SERVER_IP_ADDR), PORT_ADDR);
}
