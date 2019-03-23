#include "WorkerThread.h"


WorkerThread::WorkerThread()
{

}

QListWidget* WorkerThread::listWidget;
void WorkerThread:: run(void)
{
    unsigned long threadId=
            (unsigned long)currentThreadId();
    int i=0;
    while(1){
        QString str;
        str.sprintf("ID=%lu,i=%d",threadId,i++);
        //qDebug()<<str;
        msleep(500);
        listWidget->addItem(str);
        msleep(200);
        listWidget->setCurrentRow(listWidget->count()-1);
    }
}

