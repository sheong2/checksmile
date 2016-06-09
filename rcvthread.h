#ifndef RCVTHREAD_H
#define RCVTHREAD_H

#include <QThread>
#include <QUdpSocket>

class rcvThread : public QThread
{
    Q_OBJECT
public:
    explicit rcvThread(QObject *parent = 0);
    
signals:
   void login_result(bool);
   void dup_id_result(bool);

public slots:
    void read_data();

private:
    QUdpSocket * socket;

};

#endif // RCVTHREAD_H
