#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore/QtGlobal>
#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QTimer>
#include "masterthread.h"

QT_BEGIN_NAMESPACE

class QLabel;

namespace Ui {
class MainWindow;
}

QT_END_NAMESPACE

class Console;
class SettingsDialog;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void Delay_MSec_Suspend(unsigned int msec);
    void Delay_MSec(unsigned int msec);

private slots:
    void openSerialPort();
    void closeSerialPort();
    void manOpenSerialPort();
    void manCloseSerialPort();
    void about();
    void writeData(const QByteArray &data);
    void readData();

    void handleError(QSerialPort::SerialPortError error);

    void autoTest();
    void serialwigte();
    void setSlaveTime();
    void reFresh();
    void sentRoot();
    void playAudio();
    void enter();
    void HTUpdateTime();
    void HTCheckStoreTime();
    void setTestDevice(QString &device);

private:
    void initActionsConnections();

private:
    void showStatusMessage(const QString &message);
    void showRequest(const QString &s);

    Ui::MainWindow *ui;
    QLabel *status;
    Console *console;
    SettingsDialog *settings;
    QSerialPort *serial;
    QString testDevice;
    QTimer *autoRefreshTimer;

    MasterThread thread;
};

#endif // MAINWINDOW_H
