#include "ErnieDialog.h"
#include "ui_ErnieDialog.h"

ErnieDialog::ErnieDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ErnieDialog)
{
    ui->setupUi(this);
    //将./photos路径下所有图片加载到容器中
    loadPhotos("./photos");
    //初始化状态标记
    isStarted=false;
    //设置随机种子
    qsrand(QTime::currentTime().msec());
    //初始化图片索引
    m_idtPhoto=0;
}

ErnieDialog::~ErnieDialog()
{
    delete ui;
}

//开始,摇奖按钮对应的槽函数
void ErnieDialog::on_pushButton_clicked()
{
    if(isStarted==false){
        isStarted=true;
        //qDebug()<<"开始抽奖";
        ui->pushButton->setText("停止");
        //开启定时器,每隔50ms切换一次图片
        m_idtPhoto=startTimer((50));
    }else{
        isStarted=false;
        //qDebug()<<"结束抽奖";
        ui->pushButton->setText("开始");
        //关闭定时器
        killTimer(m_idtPhoto);
        ui->m_name->setText(m_vecName[m_index]);
    }

}

//定时器事件函数
void ErnieDialog::timerEvent(QTimerEvent* )
{
    //从容器中随机获取一个图片的索引
    m_index=qrand()%m_vecPhotos.size();
    //触发绘图事件，绘制该图片
    //update();
    repaint();
}

//绘图事件函数
void ErnieDialog::paintEvent(QPaintEvent* )
{
    //设置绘图器
    QPainter painter(this);
    //获取矩形区域
    QRect rcPhoto=ui->frame->frameRect();
    //平移坐标
    rcPhoto.translate(ui->frame->pos());
    //将随机得到的图片和名字显示到界面
    painter.drawImage(rcPhoto,m_vecPhotos[m_index]);

}


//加载path路径下的所有图片
void ErnieDialog::loadPhotos(const QString& path)
{
    //创建目录对象
    QDir dir(path);

    //遍历目录下普通文件
    foreach (QString file,dir.entryList(QDir::Files)) {
        //将图片名字保存到容器
        m_vecName<<file.section('.',0,0);

        //qDebug()<<file;
        QImage image(path+'/'+file);
        //将图片保存到容器中
        m_vecPhotos<<image;
    }
    //递归遍历子目录
    foreach (QString subDir,
             dir.entryList(QDir::Dirs|QDir::NoDotAndDotDot)) {
        loadPhotos(path+'/'+subDir);
    }
}
