#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QWidget>
#include <QThreadPool>
#include "Worker.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Qt6 ThreadPool with Signals");

    QVBoxLayout *layout = new QVBoxLayout(&window);

    QLabel *label = new QLabel("Click button to compute 5 + 7...");
    QPushButton *button = new QPushButton("Start Worker");

    layout->addWidget(label);
    layout->addWidget(button);

    QObject::connect(button, &QPushButton::clicked, [&]() {
        Worker *worker = new Worker(5, 7);

        QObject::connect(worker, &Worker::progress, &window, [=](int step, QString msg) {
            label->setText(QString("Progress: %1 (%2)").arg(step).arg(msg));
        });

        QObject::connect(worker, &Worker::finished, &window, [=](int result) {
            label->setText(QString("Result: %1").arg(result));
        });

        QObject::connect(worker, &Worker::error, &window, [=](QString msg) {
            label->setText(QString("Error: %1").arg(msg));
        });

        QThreadPool::globalInstance()->start(worker);
    });

    window.resize(350, 200);
    window.show();

    return app.exec();
}
