#ifndef CAPTURETHREAD_H
#define CAPTURETHREAD_H
#include "playingdialog.h"
#include <QThread>
#include <QTimer>
class CaptureThread : public QThread
{
    Q_OBJECT
public:
    explicit CaptureThread(QObject *parent = 0);
    volatile int count;
    
signals:
    
public slots:

private slots:
    void autocapture();
    void stopcapture();
    void pausecapture();
    void resumecapture();
    void ffpressed();
    void rwpressed();

private:
   QTimer * time;
   PlayingDialog * play;
   int fd_pipe_stdin[2];
   int fd_pipe_stdout[2];


    
};

#endif // CAPTURETHREAD_H
