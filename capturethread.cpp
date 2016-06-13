#include "capturethread.h"
#include <QTimer>
#include <stdio.h>

CaptureThread::CaptureThread(QObject *parent) :
    QThread(parent)
{
    time = new QTimer;
    connect(time,SIGNAL(timeout()),this,SLOT(autocapture()));

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

        execlp("./v4l2test","v4l2test","-d","/dev/video1","-c","700000", "-a","1",NULL);

    }
    else
    {
        time->start(500);
        count=0;
        ::close(fd_pipe_stdin[0]);
        ::close(fd_pipe_stdout[1]);
    }
}

void CaptureThread::autocapture()
{
    char str[15]="c ./cam/0000\n";
    str[11]=count%10+'0';
    if (count>9) str[10]=(count/10)%10+'0';
    if(count>99) str[9]=(count/100)%10+'0';
    if(count>999) str[8]=count/1000+'0';
    //printf("count:%d\n",count);
    count++;
    fflush(stdout);
    write(fd_pipe_stdin[1], str, strlen(str));
    fflush(stdout);
    sleep(1);
}
void CaptureThread::stopcapture()
{
    time->stop();
    write(fd_pipe_stdin[1],"e\n",2);
}
void CaptureThread::pausecapture()
{
    time->stop();
}
void CaptureThread::resumecapture()
{
    time->start(500);
}
void CaptureThread::ffpressed()
{
    count+=5;
    time->start(500);
}
void CaptureThread::rwpressed()
{
    count-=5;
    time->start(500);
}
