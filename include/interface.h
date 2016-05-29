#ifndef INTERFACE_H
#define INTERFACE_H

#include "serial.h"


class Interface
{
public:
    void clearscreen();
    Interface();
    void setbaud(SerialPort*);
    void setparity(SerialPort*);
    void setstop(SerialPort*);
    void setdata(SerialPort*);
    void setport(SerialPort*);
    void setflow(SerialPort*);
    void showconnectionoptions(SerialPort*);
};

#endif // INTERFACE_H
