#include "Worker.h"
#include "mylib.h"
#include <QThread>

Worker::Worker(int a, int b) : m_a(a), m_b(b) {
    setAutoDelete(true);
}

void Worker::run() {
    for (int i = 1; i <= 3; ++i) {
        QThread::sleep(1);
        emit progress(i, QString("Step %1 completed").arg(i));
    }

    if (m_a < 0 || m_b < 0) {
        emit error("Negative values are not allowed!");
        return;
    }

    int result = add_numbers(m_a, m_b);
    emit finished(result);
}
