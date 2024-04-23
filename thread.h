#ifndef THREAD_H
#define THREAD_H

#include <QObject>
#include <QDebug>
#include <QThread>

class SampleThread : public QThread
{
    Q_OBJECT
public:
    SampleThread();

    void work(int n = 10);

signals:
    void resultReady(int result); // Signal to notify the result

protected:
    void run();
};

#endif // THREAD_H
