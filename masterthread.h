#ifndef MASTERTHREAD_H
#define MASTERTHREAD_H

#include <QThread>
#include <QWaitCondition>

class MasterThread : public QThread
{
    Q_OBJECT

public:
    MasterThread(QObject *parent=0);
    ~MasterThread();

    void startMaster();
    void run();

signals:
    void request(const QString &s);
    void error(const QString &s);
    void timeout(const QString &s);

private:
    bool quit;
    QWaitCondition cond;
};

#endif // MASTERTHREAD_H
