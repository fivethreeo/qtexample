#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QRunnable>
#include <QString>

class Worker : public QObject, public QRunnable {
    Q_OBJECT
public:
    Worker(int a, int b);
    void run() override;

signals:
    void progress(int step, QString message);
    void finished(int result);
    void error(QString message);

private:
    int m_a;
    int m_b;
};

#endif // WORKER_H
