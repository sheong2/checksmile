#ifndef RCVTHREAD_H
#define RCVTHREAD_H

#include <QThread>
#include <QUdpSocket>
#include <QTimer>

class rcvThread : public QThread
{
    Q_OBJECT
public:
    explicit rcvThread(QObject *parent = 0);
    
signals:
   void login_result(bool);
   void dup_id_result(bool);
   void readydata(QByteArray datagram);
   void set_tab(int maxpage);
   void auto_capture();


public slots:
    void read_data();
    void send_data(QByteArray datagram);

private:
    QUdpSocket * socket;
};

#endif // RCVTHREAD_H
