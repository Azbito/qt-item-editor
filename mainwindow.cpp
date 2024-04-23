// mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connect the resultReady signal from the SampleThread to the handleWorkFinished slot in MainWindow
    connect(&_sample, &SampleThread::resultReady, this, &MainWindow::handleWorkFinished);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleWorkFinished(int result) {
    ui->label->setText(QString("Result: %1").arg(result));
}

void MainWindow::on_pushButton_clicked()
{
    // Start the thread when the button is clicked
    _sample.start();
}
