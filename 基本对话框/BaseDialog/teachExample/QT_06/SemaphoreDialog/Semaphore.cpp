
#include "SemaphoreDialog.h"

int DataSize=20;//生产产品总量
const int BufferSize=5;//仓库大小
//仓库
int buffer[BufferSize];

//控制生产者信号量
QSemaphore freeSpace(BufferSize);
//控制消费者信号量
QSemaphore usedSpace(0);

QProgressBar* threadProducer::wareProgressBar;
QProgressBar* threadConsumer::wareProgressBar;
QProgressBar* threadProducer::productedProgressBar;
QProgressBar* threadConsumer::consumedProgressBar;
QProgressBar* threadProducer::needProductProgressBar;

void threadProducer::run(void){
    for(int i=0;i<DataSize;i++){
        //P:-1 成功则生产者信号量-1，失败阻塞
        freeSpace.acquire();//仓库空间减1
        buffer[i%BufferSize]=i+1;
        //qDebug("producer:%d",buffer[i%BufferSize]);
        //V:+1 控制消费者信号量+1
        usedSpace.release();
        wareProgressBar->setValue(usedSpace.available());
        msleep(productSpeed*2/5);
        needProductProgressBar->setValue(DataSize-i-1);
        msleep(productSpeed*2/5);
        productedProgressBar->setValue(i+1);
        msleep(productSpeed/5);
    }
}


void threadConsumer::run(void){
    for(int i=0;i<DataSize;i++){
        //P:-1 成功则消费者-1，失败阻塞
        usedSpace.acquire();//仓库空间加1
        //qDebug("consuemr:%d",buffer[i%BufferSize]);
        //V:+1 控制生产者信号量+1
        freeSpace.release();
        wareProgressBar->setValue(usedSpace.available());
        msleep(consumSpeed/2);
        consumedProgressBar->setValue(i+1);
        msleep(consumSpeed/2);
    }
}

