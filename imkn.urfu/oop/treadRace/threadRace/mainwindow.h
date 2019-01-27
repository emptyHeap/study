#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <thread>
#include <chrono>
#include <array>
#include <QTimer>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    const static int threadsAmount = 20;
    QTimer *timer;
    std::thread* racingThreads[threadsAmount];
    long unsigned racingVariables[threadsAmount];

    [[noreturn]] static void infiniteUpdate(long unsigned *i) {
        while(true)
        {
            if (*i%10000 == 0) {
                //std::this_thread::sleep_for(std::chrono::nanoseconds(10000));
            };
            *i += 1;
        }
    }

    void paintEvent(QPaintEvent *event);
};

#endif // MAINWINDOW_H
