#include <QCoreApplication>
#include <QThread>
#include <QSemaphore>

const int DataSize=20;//生产产品总量
const int BufferSize=5;//仓库大小
//仓库
int buffer[BufferSize];

//控制生产者信号量
QSemaphore freeSpace(BufferSize);
//控制消费者信号量
QSemaphore usedSpace(0);

class threadProducer:public QThread{
public:
    void run(void){
        for(int i=0;i<DataSize;i++){
            //P:-1 成功则生产者信号量-1，失败阻塞
            freeSpace.acquire();
            buffer[i%BufferSize]=i+1;
            qDebug("producer:%d",buffer[i%BufferSize]);
            //V:+1 控制消费者信号量+1
            usedSpace.release();
        }
    }
};

class threadConsumer:public QThread{
public:
    void run(void){
        for(int i=0;i<DataSize;i++){
        //P:-1 成功则消费者-1，失败阻塞
        usedSpace.acquire();
        qDebug("consuemr:%d",buffer[i%BufferSize]);
        //V:+1 控制生产者信号量+1
        freeSpace.release();
        msleep(500);
        }
    }
};


int main(int argc,char** argv){
    QCoreApplication app(argc,argv);

    threadProducer producer;
    threadConsumer consumer;

    producer.start();//生产开始
    consumer.start();//消费开始

    producer.wait();
    consumer.wait();

    //return app.exec();
    return 0;
}
