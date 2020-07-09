#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QListWidget>

class Widget : public QWidget{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    QLineEdit* firstInput = new QLineEdit;
    QLineEdit* secondInput = new QLineEdit;
    QLineEdit* resultEdit = new QLineEdit;
    QListWidget* resultList = new QListWidget;

public slots:
    void onPlusButtonClicked();
    void onMinusButtonClicked();
    void onMultiplyButtonClicked();
    void onDivideButtonClicked();
    void onClearButtonClicked();

};
#endif // WIDGET_H
