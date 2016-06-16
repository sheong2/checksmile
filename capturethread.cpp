#include "capturethread.h"
#include <stdio.h>

CaptureThread::CaptureThread(QByteArray start_time, QObject *parent) :
    QThread(parent)
{
    timer = new QElapsedTimer;
    starttime=start_time.mid(0, 2).toInt()*60 + start_time.mid(3, 2).toInt();

    pid_t pid_temp;
    if(pipe(fd_pipe_stdin) == -1) exit(-1);
    if(pipe(fd_pipe_stdout) == -1) exit(-1);

    pid_temp = fork();
    if(pid_temp == -1) exit(-1);

    else if (pid_temp == 0)
    {
        ::close(0);
        dup(fd_pipe_stdin[0]);
        ::close(fd_pipe_stdin[0]);
        ::close(fd_pipe_stdin[1]);
        ::close(1);
        dup(fd_pipe_stdout[1]);
        ::close(fd_pipe_stdout[1]);
        ::close(fd_pipe_stdout[0]);

        execlp("./v4l2test","v4l2test","-d","/dev/video1","-c","700000","-a","1",NULL);
    }
    else
    {
        timer->start();
        ::close(fd_pipe_stdin[0]);
        ::close(fd_pipe_stdout[1]);
    }
}

void CaptureThread::autocapture()
{
    sleep(3);
    qint64 count;
    count = timer->elapsed()/1000 + starttime +offset;
    offset=0;
    char str[15]="c ./cam/0000\n";
    str[11]=count%10+'0';
    if (count>9) str[10]=(count/10)%10+'0';
    if(count>99) str[9]=(count/100)%10+'0';
    if(count>999) str[8]=count/1000+'0';

    fflush(stdout);
    write(fd_pipe_stdin[1], str, strlen(str));
    fflush(stdout);
    sleep(1);
}
void CaptureThread::stopcapture()
{
    write(fd_pipe_stdin[1],"e\n",2);
    delete timer;
}
void CaptureThread::pausecapture()
{
    timer->invalidate();
}
void CaptureThread::resumecapture()
{
    timer->restart();
}
void CaptureThread::ffpressed()
{
    offset += 5;
    if(!(timer->isValid())) timer->restart();
}
void CaptureThread::rwpressed()
{
    offset += -5;
}
