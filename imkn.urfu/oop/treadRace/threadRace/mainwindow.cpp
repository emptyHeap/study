#include "mainwindow.h"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    for (unsigned long i = 0; i < threadsAmount; i++)
    {
        racingVariables[i] = 0;
        std::thread* newThread = new std::thread(this->infiniteUpdate, &racingVariables[i]);
        racingThreads[i] = newThread;
    }

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000/60);
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter qp(this);

    for (unsigned long i = 0; i < threadsAmount; i++) {
        int bColor = i * 255 / threadsAmount;
        int rColor = i * i * 255 / threadsAmount / threadsAmount;
        int gColor = i * i * i * 255 / threadsAmount / threadsAmount / threadsAmount;
        QPen pen(QColor(rColor,gColor,bColor,100), 2, Qt::SolidLine);
        qp.setPen(pen);
        unsigned long len = racingVariables[i] / 1000000;
        int lineNo = len / this->width();
        for (int j = 0; j < lineNo; j++) {
            int lineNo = len / this->width();
            qp.drawLine(0, (i + 1) * 20 + j*2, this->width(), (i + 1) * 20 + j*2);
            len -= this->width();
        }
        qp.drawLine(0, (i + 1) * 20 + lineNo*2, len, (i + 1) * 20 + lineNo*2);
    }
}

MainWindow::~MainWindow()
{
    for (unsigned long i = 0; i < threadsAmount; i++)
    {
        delete racingThreads[i];
    }
}
