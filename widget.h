#ifndef WIDGET_H
#define WIDGET_H

#include <QApplication>
#include <QWidget>
#include <QFile>
#include <QPushButton>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QLabel>
#include <QTextStream>
#include <QScrollBar>
#include <QTextCursor>
#include <QDebug>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);

    QGridLayout *grid = new QGridLayout();
    QHBoxLayout *hbox = new QHBoxLayout();
    QHBoxLayout *hbox2 = new QHBoxLayout();

    QPushButton *btn1 = new QPushButton("🔍+");
    QPushButton *btn2 = new QPushButton("🔍-");
    QPushButton *btn3 = new QPushButton("Next");
    QPushButton *btn4 = new QPushButton("Previous");

    QPushButton *btn5 = new QPushButton("🌘 Night Mode");
    QPushButton *btn6 = new QPushButton("Quit");
    QLabel *pageno = new QLabel("Page no. 1/852");

    QTextEdit *read = new QTextEdit();
    ~Widget();
};

#endif // WIDGET_H
