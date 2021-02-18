#include "rover.h"
#include <QDebug>

Rover::Rover(QObject *parent) :
    QObject(parent),
    isConnected(false),
    controlLevel(20.0)
{ }

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
