#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QScrollArea>
#include "thread.h"
#include <QThread>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void handleWorkFinished(int res);
    void on_pushButton_clicked();


private:
    Ui::MainWindow *ui;
    SampleThread _sample;
    QThread _thread;
    QScrollArea *scrollArea;
    QVBoxLayout *scrollLayout;
    QPushButton *loadButton;
    int startIndex;
    int batchSize;
};

#endif // MAINWINDOW_H
