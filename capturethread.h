#ifndef CAPTURETHREAD_H
#define CAPTURETHREAD_H
#include "playingdialog.h"
#include <QThread>
#include <QElapsedTimer>
class CaptureThread : public QThread
{
    Q_OBJECT
public:
    explicit CaptureThread(QByteArray time, QObject *parent = 0);


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
   QElapsedTimer * timer;
   PlayingDialog * play;
   int fd_pipe_stdin[2];
   int fd_pipe_stdout[2];

   volatile int starttime;
   volatile int offset;

};

#endif // CAPTURETHREAD_H
