#include "WorkerThread.h"

WorkerThread::WorkerThread()
{

}

void WorkerThread:: run(void)
{
    unsigned long threadId=
            (unsigned long)currentThreadId();
    int i=0;
    while(1){
        qDebug("id=%lu,i=%d",threadId,i++);
        msleep(200);
    }
}
