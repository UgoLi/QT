#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H
#include <QThread>
#include <QDebug>

class WorkerThread:public QThread//1）继承
{
public:
    WorkerThread();
    //2)重写run函数
    void run(void);
};

#endif // WORKERTHREAD_H
