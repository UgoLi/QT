/*************************************************************************
	> File Name: CalculatorDialog.cpp
	> Author:UgoLi 
	> Mail: 2653920896@qq.com
	> Created Time: 2017年09月11日 星期一 16时16分11秒
 ************************************************************************/

#include"CalculatorDialog.h"

//构造函数
CalculatorDialog::CalculatorDialog(void){
    //设置窗口属性
    setWindowTitle("加法计算器");
    setCursor(Qt::WaitCursor);//光标形状



    //创建左操作数对象,this指向父窗口对象
    m_editx=new QLineEdit(this);
    //设置文本对齐方式：右对齐
    m_editx->setAlignment(Qt::AlignJustify);
    //设置验证器：只能输入数字
    m_editx->setValidator(new QDoubleValidator(this));

    //创建右操作数对象,this指向父窗口对象
    m_edity=new QLineEdit(this);
    //设置文本对齐方式：右对齐
    m_edity->setAlignment(Qt::AlignJustify);
    //设置验证器：只能输入数字
    m_edity->setValidator(new QDoubleValidator(this));
    
    //创建等号按钮
    m_btnCalc=new QPushButton("请输入合法参数",this);
    //设置使能（灰色背景）
    m_btnCalc->setEnabled(false);

    //创建结果对象,this指向父窗口对象
    m_editZ=new QLineEdit(this);
    //设置文本对齐方式：右对齐
    m_editZ->setAlignment(Qt::AlignJustify);
    //设置只读
    m_editZ->setReadOnly(true);
  
    //设置操作符
    m_symbol=new QComboBox(this);
    m_symbol->addItem("+");
    m_symbol->addItem("-");
    m_symbol->addItem("X");
    m_symbol->addItem("%");

    //创建水平布局器：自动调整每个组件的大小和位置
    QHBoxLayout* layout=new QHBoxLayout(this);
    //按照水平方向将每个组件一次添加到布局器
    layout->addWidget(m_editx);
    layout->addWidget(m_symbol);
    layout->addWidget(m_edity);
    layout->addWidget(m_btnCalc);
    layout->addWidget(m_editZ);
    //设置布局器
    setLayout(layout);

    //连接信号和槽
    //左右操作数输入文本改变时发送textChanged信号
    //如果连接的槽函数是自己定义的，接受就对象一定是this指针
    connect(m_edity,SIGNAL(textChanged(const QString&)),
            this,SLOT(enabeleCalcButton()));
    connect(m_edity,SIGNAL(textChanged(QString)),
            this,SLOT(enabeleCalcButton()));
    
    //
    connect(m_btnCalc,SIGNAL(clicked()),this,SLOT(calcClicked()));
}

//使能等号按钮,对应左右操作数的textChanged信号
void CalculatorDialog::enabeleCalcButton(void){
    bool bXOk=false;
    bool bYOk=false;
    //text()获取输入的文本(QString)
    //toDouble::QString->double,参数保存转换是否成功
    m_editx->text().toDouble(&bXOk);
    m_edity->text().toDouble(&bYOk);
    if(!(bXOk && bYOk))m_btnCalc->setText("false");
    else m_btnCalc->setText("=");
    m_btnCalc->setEnabled(bXOk && bYOk); 
}

//计算结果按钮
void CalculatorDialog::calcClicked(void){
    double res=0;
    QString opt=m_symbol->currentText();
    if(opt=="+")
            res=m_editx->text().toDouble()+m_edity->text().toDouble();
    if(opt=="-")
            res=m_editx->text().toDouble()-m_edity->text().toDouble();
    if(opt=="X")
            res=m_editx->text().toDouble()*m_edity->text().toDouble();
    if(opt=="%")
            res=m_editx->text().toDouble()/m_edity->text().toDouble();
    //number：实现将一个数字转换为字符串
    //setText：将一个字符串显示到界面上
    m_editZ->setText(
        QString::number(res,'g',15));
}



