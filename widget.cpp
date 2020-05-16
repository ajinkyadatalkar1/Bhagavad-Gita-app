#include "widget.h"
#include <QColor>
#include <QPalette>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QString>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setLayout(grid);

    QTextCursor cursor = read->textCursor();
    read->setReadOnly(true);

    hbox->addWidget(btn4);
    hbox->addWidget(btn1);
    hbox->addWidget(btn2);
    hbox->addWidget(btn3);
    grid->addLayout(hbox,0,0);

    static int page_no = 1;
    static QString page_val = ":/";
    static int size=18;
    static bool night = true;

    grid->addWidget(read);
    read->setFontPointSize(size);

    read->setAlignment(Qt::AlignJustify);
    read->setAcceptRichText(true);

    hbox2->addWidget(btn5);
    hbox2->addWidget(pageno);
    hbox2->addWidget(btn6);
    grid->addLayout(hbox2,2,0);

    QScrollBar *scroll = read->verticalScrollBar();

    scroll->setStyleSheet(QString::fromUtf8("QScrollBar:vertical {"
        "    border: 1px solid #999999;"
        "    background:white;"
        "    width:75;    "
        "    margin: 0px 0px 0px 0px;"
        "}"
        "QScrollBar::handle:vertical {"
        "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
        "    stop: 0 rgb(32, 47, 130), stop: 0.5 rgb(32, 47, 130), stop:1 rgb(32, 47, 130));"
        "    min-height: 0px;"
        "}"
        "QScrollBar::add-line:vertical {"
        "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
        "    stop: 0 rgb(32, 47, 130), stop: 0.5 rgb(32, 47, 130),  stop:1 rgb(32, 47, 130));"
        "    height: 0px;"
        "    subcontrol-position: bottom;"
        "    subcontrol-origin: margin;"
        "}"
        "QScrollBar::sub-line:vertical {"
        "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
        "    stop: 0  rgb(32, 47, 130), stop: 0.5 rgb(32, 47, 130),  stop:1 rgb(32, 47, 130));"
        "    height: 0 px;"
        "    subcontrol-position: top;"
        "    subcontrol-origin: margin;"
        "}"
        ));

    static QPalette p;// = read->setPalette();

    QFile file(":/1.txt");
    file.open(QFile::ReadOnly | QFile::Text);
    QString htm = file.readAll();
    read->setHtml(htm);
/*    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        read->append(line);
    }*/

    connect(btn1,&QPushButton::clicked,[=](){
        read->selectAll();
        read->setFontPointSize(size++);
        read->setTextCursor(cursor);
        scroll->setValue(0);
    });

    connect(btn2,&QPushButton::clicked,[=](){
        read->selectAll();
        read->setFontPointSize(size--);
        read->setTextCursor(cursor);
        scroll->setValue(0);
    });

    connect(btn3,&QPushButton::clicked,[=](){
        read->clear();
        page_val.append(QString::number(++page_no));
        page_val.append(".txt");
        QFile file(page_val);
        file.open(QFile::ReadOnly | QFile::Text);
        read->setHtml(file.readAll());
/*      QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            read->append(line);
        }*/

        scroll->setValue(0);
        page_val =":/";
        pageno->setText("Page No. " + QString::number(page_no) + "/852");
    });

    connect(btn4,&QPushButton::clicked,[=](){
        if(page_no >=1){
        read->clear();
        page_val.append(QString::number(--page_no));
        page_val.append(".txt");
        QFile file(page_val);
        file.open(QFile::ReadOnly | QFile::Text);
        read->setHtml(file.readAll());

/*      QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            read->append(line);
        }*/
        scroll->setValue(0);
        qDebug() << page_val;
        page_val =":/";
        pageno->setText("Page No. " + QString::number(page_no) + "/852");
        }
    });

    connect(btn5,&QPushButton::clicked,[=](){
        if(night){
        read->setStyleSheet("Background-color: #00061a");
        p.setColor(QPalette::Text, Qt::gray);
        read->setPalette(p);
        night = false;
        qDebug() <<"true";
        }
        else{
        read->setStyleSheet("Background-color: #ffffff");
        p.setColor(QPalette::Text, Qt::black);
        read->setPalette(p);
        night = true;
        qDebug() <<"false";
        }
    });

    connect(btn6,&QPushButton::clicked,qApp,&QApplication::exit);

}

Widget::~Widget()
{

}
