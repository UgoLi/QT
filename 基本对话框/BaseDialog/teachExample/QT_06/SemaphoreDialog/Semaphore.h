/*************************************************************************
	> File Name: SemaphoreDialog.h
	> Author:UgoLi 
	> Mail: 2653920896@qq.com
	> Created Time: 2017年09月18日 星期一 23时39分04秒
 ************************************************************************/

#ifndef _SEMAPHOREDIALOG_H
#define _SEMAPHOREDIALOG_H

#include <QThread>
#include <QSemaphore>
#include <QProgressBar>


class threadProducer:public QThread{
public:
    void run(void);
    static QProgressBar* wareProgressBar;
    static QProgressBar* productedProgressBar;
    static QProgressBar* needProductProgressBar;
    int productSpeed;
};

class threadConsumer:public QThread{
public:
    void run(void);
    static QProgressBar* wareProgressBar;
    static QProgressBar* consumedProgressBar;
    int consumSpeed;
};

#endif
