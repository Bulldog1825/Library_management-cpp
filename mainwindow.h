// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onPushButtonPushClicked();
    void onPushButtonPopClicked();
    void onPushButtonPeekClicked();
    void onPushButtonEnqueueClicked();
    void onPushButtonDequeueClicked();
    void onPushButtonPeekReservationClicked();
    void onPushButtonStateClicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
