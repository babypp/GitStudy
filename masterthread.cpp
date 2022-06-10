#include "masterthread.h"
#include "mainwindow.h"
#include <QtSerialPort/QSerialPort>
#include <QSerialPortInfo>
#include <QTimer>

QT_USE_NAMESPACE

MasterThread::MasterThread(QObject *parent)
    :QThread(parent), quit(false)
{
}

MasterThread::~MasterThread()
{
    wait();
}

void MasterThread::startMaster()
{
    wait();
    if(!isRunning())
        start();
}

void MasterThread::run()
{
    QString requestData = "abcdefjhijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890-+=,.?/;:'!@#$%^&*()";
    QSerialPort serial;
    QByteArray responseData;
    QString testResult = "TestResult:\n";

    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts()){
        serial.setPortName(info.portName());
        serial.setBaudRate(QSerialPort::Baud115200);
        serial.setDataBits(QSerialPort::Data8);
        serial.setParity(QSerialPort::NoParity);
        serial.setStopBits(QSerialPort::OneStop);
        serial.setFlowControl(QSerialPort::NoFlowControl);
        if(serial.isOpen())
            serial.close();
        if(serial.open(QIODevice::ReadWrite)){

            // write request
            serial.write(requestData.toLocal8Bit());
            if(serial.waitForBytesWritten(1000)){

                // read response
                if(serial.waitForReadyRead(1000)){
                    responseData = serial.readAll();
                    while(serial.waitForReadyRead(500))
                        responseData += serial.readAll();
                    QString response(responseData);
                    if (requestData == response)
                        testResult +=QString(info.portName()) + " is OK.\n";
                    else
                        testResult +=QString(info.portName()) + " is Not OK.\n";
                } else
                    testResult +=QString(info.portName()) + " is Not Detected.\n";
            } else {
//                MainWindow::showStatusMessage(QString(info.portName())+" write error.");
            }
        } else {
//            MainWindow::showStatusMessage(QString(info.portName())+" open error");
        }
    }
    emit this->request(testResult);
}
