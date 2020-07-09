#include "widget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QDebug>

Widget::Widget(QWidget *parent): QWidget(parent){
    QHBoxLayout* inputLayout = new QHBoxLayout;
    inputLayout->addWidget(firstInput);
    inputLayout->addWidget(secondInput);
    QHBoxLayout* buttonLayout = new QHBoxLayout;
    QPushButton* plusButton = new QPushButton("+");
    QPushButton* minusButton = new QPushButton("-");
    QPushButton* multiplyButton = new QPushButton("*");
    QPushButton* divideButton = new QPushButton("/");
    buttonLayout->addWidget(plusButton);
    buttonLayout->addWidget(minusButton);
    buttonLayout->addWidget(multiplyButton);
    buttonLayout->addWidget(divideButton);
    QHBoxLayout* resultLayout = new QHBoxLayout;
    QLabel* resultLabel = new QLabel("Result:");
    resultLayout->addWidget(resultLabel);
    resultLayout->addWidget(resultEdit);
    QPushButton* clearButton = new QPushButton("Clear Results");
    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addLayout(inputLayout);
    mainLayout->addLayout(buttonLayout);
    mainLayout->addLayout(resultLayout);
    mainLayout->addWidget(resultList);
    mainLayout->addWidget(clearButton);
    this->setLayout(mainLayout);
    connect(plusButton,SIGNAL(clicked()),this,SLOT(onPlusButtonClicked()));
    connect(minusButton,SIGNAL(clicked()),this,SLOT(onMinusButtonClicked()));
    connect(multiplyButton,SIGNAL(clicked()),this,SLOT(onMultiplyButtonClicked()));
    connect(divideButton,SIGNAL(clicked()),this,SLOT(onDivideButtonClicked()));
    connect(clearButton,SIGNAL(clicked()),this,SLOT(onClearButtonClicked()));
}
Widget::~Widget(){

}
void Widget::onPlusButtonClicked(){
    qDebug()<<"Plus Button Clicked";
    double a = firstInput->text().toDouble();
    double b = secondInput->text().toDouble();
    QString result = QString::number(a+b);
    resultEdit->setText(result);
    resultList->addItem(result);
}
void Widget::onMinusButtonClicked(){
    qDebug()<<"Minus Button Clicked";
    double a = firstInput->text().toDouble();
    double b = secondInput->text().toDouble();
    QString result = QString::number(a-b);
    resultEdit->setText(result);
    resultList->addItem(result);
}
void Widget::onMultiplyButtonClicked(){
    qDebug()<<"Multiply Button Clicked";
    double a = firstInput->text().toDouble();
    double b = secondInput->text().toDouble();
    QString result = QString::number(a*b);
    resultEdit->setText(result);
    resultList->addItem(result);
}
void Widget::onDivideButtonClicked(){
    qDebug()<<"Divide Button Clicked";
    double a = firstInput->text().toDouble();
    double b = secondInput->text().toDouble();
    QString result = QString::number(a/b);
    resultEdit->setText(result);
    resultList->addItem(result);
}
void Widget::onClearButtonClicked(){
    qDebug()<<"Clear Button Clicked";
    resultList->clear();
}

