#include "rover.h"
#include <QDebug>
#include <QRandomGenerator>

Rover::Rover(QObject *parent) :
    QObject(parent),
    isConnected(false),
    controlLevel(20.0)
{
    timer = new QTimer(this);

    connect(timer, &QTimer::timeout,
            this, &Rover::onTimeout);
    timer->setInterval(QRandomGenerator::securelySeeded().bounded(100, 1000));
    timer->start();
}

void Rover::goLeft()
{
    qDebug() << "Ride left with sensitivity " << controlLevel;
}

void Rover::goRight()
{
    qDebug() << "Ride right with sensitivity " << controlLevel;
}

void Rover::goForward()
{
    qDebug() << "Ride forward with sensitivity " << controlLevel;
}

void Rover::goBackward()
{
    qDebug() << "Ride backward with sensitivity " << controlLevel;
}

void Rover::stop()
{
     qDebug() << "Stop";
}

void Rover::onTimeout()
{
    isConnected = !isConnected;
    emit isConnectedChanged(); //Emit signal when parametr is change

    if(isConnected)
        timer->setInterval(QRandomGenerator::securelySeeded().bounded(5000, 20000));
    else
        timer->setInterval(QRandomGenerator::securelySeeded().bounded(500, 4000));

    qDebug() << (isConnected ? "Connected" : "Disconnected") << "Interval" << timer->interval();

}
