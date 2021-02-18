#ifndef ROVER_H
#define ROVER_H

#include <QObject>

class Rover : public QObject
{
    Q_OBJECT

public:
    explicit Rover(QObject *parent = nullptr);

public slots:
    void goLeft();
    void goRight();
    void goForward();
    void goBackward();
    void stop();

private:
    bool isConnected;
    double controlLevel;


signals:

};

#endif // ROVER_H
