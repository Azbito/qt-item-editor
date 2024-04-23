#include "thread.h"
#include <QThread>

SampleThread::SampleThread() {}

void SampleThread::work(int n) {
    int res = 0; // Initialize res outside the loop

    // Simulate some work
    for (int i = 0; i < n; ++i) {
        qDebug() << "I: " << i;
        msleep(200);

        res = i; // Store the last value of i
    }

    // Emit the result when the work is done
    emit resultReady(res);
}

void SampleThread::run() {
    work();
}
