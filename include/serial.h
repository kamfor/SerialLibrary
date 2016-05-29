#ifndef _SERIAL_H
#define _SERIAL_H

#include<iostream>
#include<map>
#include<string>
#include "rs232.h"

using namespace std;

class Element{

public:

    map<string, const int>::const_iterator current;
    const string getstring();
    int getint();
};

class Status : public Element{

public:

    const map<string,const int> value = {
        {"Connected", 0},
        {"Disconnected" , 1},
        {"Error", 2},
        {"DeviceNotFound", 3},
        {"PermissionError", 4},
        {"OpenError", 5},
        {"IllegalPortNumber", 6},
        {"InvalidBaudrate", 7},
        {"InvalidMode", 8},
        {"InvalidDataBits", 9},
        {"InvalidParity", 10},
        {"InvalidStopBits", 11},
        {"UnableToGetPortStatus", 12},
        {"InvalidStatus", 13}
    };

    int set(const string);
    void showoptions();
};

class Parity : public Element{

public:

    const map<string,const int> value = {
        {"NoParity", 0},
        {"EvenParity", 1},
        {"OddParity", 2}
    };

    int set(const string);
    void showoptions();
};

class BaudRate : public Element{

public:

    const map<string,const int> value = {
        {"Baud1200", 1200},
        {"Baud1800", 1800},
        {"Baud2400", 2400},
        {"Baud4800", 4800},
        {"Baud9600", 9600},
        {"Baud19200", 19200},
        {"Baud38400", 38400},
        {"Baud57600", 57600},
        {"Baud115200", 115200},
        {"Baud230400", 230400},
        {"Baud460800", 460800},
        {"Baud500000", 500000},
        {"Baud576000", 576000},
        {"Baud921600", 921600},
        {"Baud1000000", 1000000},
        {"Baud1152000", 1152000},
        {"Baud1500000", 1500000},
        {"Baud2000000", 2000000},
        {"Baud2500000", 2500000},
        {"Baud3000000", 3000000},
        {"Baud3500000", 3500000},
        {"Baud4000000", 4000000}
    };

    int set(const string);
    void showoptions();
};

class StopBits : public Element{

public:

    const map<string,const int> value = {
        {"OneStop", 0},
        {"TwoStop", 1}
    };

    int set(const string);
    void showoptions();
};

class DataBits : public Element{

public:

   const map<string,const int> value = {
        {"Data5", 5},
        {"Data6", 6},
        {"Data7", 7},
        {"Data8", 8}
    };

    int set(const string);
    void showoptions();
};

class FlowControl : public Element{

public:

    const map<string,const int> value = {
        {"NoFlowControl", 0},
        {"HardwareControl", 1},
        {"SoftwareControl", 2}
    };

    int set(const string);
    void showoptions();
};

class PortName : public Element{

public:

    #if defined(__linux__) || defined(__FreeBSD__)
    const map<string,const int> value= {
        {"ttyS0", 0},
        {"ttyS1", 1},
        {"ttyS2", 2},
        {"ttyS3", 3},
        {"ttyS4", 4},
        {"ttyS5", 5},
        {"ttyS6", 6},
        {"ttyS7", 7},
        {"ttyS8", 8},
        {"ttyS9", 9},
        {"ttyS10", 10},
        {"ttyS11", 11},
        {"ttyS12", 12},
        {"ttyS13", 13},
        {"ttyS14", 14},
        {"ttyS15", 15},
        {"ttyUSB0", 16},
        {"ttyUSB1", 17},
        {"ttyUSB2", 18},
        {"ttyUSB3", 19},
        {"ttyUSB4", 20},
        {"ttyUSB5", 21},
        {"ttyAMA0", 22},
        {"ttyAMA1", 23},
        {"ttyACM0", 24},
        {"ttyACM1", 25},
        {"rfcomm0", 26},
        {"rfcomm1", 27},
        {"ircomm0", 28},
        {"ircomm1", 29},
        {"cuau0", 30},
        {"cuau1", 31},
        {"cuau2", 32},
        {"cuau3", 33},
        {"cuaU0", 34},
        {"cuaU1", 35},
        {"cuaU2", 36},
        {"cuaU3", 37}
    };

    #else

    const map<string,const int> value= {,
        {"COM1", 39},
        {"COM2", 40},
        {"COM3", 41},
        {"COM4", 42},
        {"COM5", 43},
        {"COM6", 44},
        {"COM7", 45},
        {"COM8", 46},
        {"COM9", 47},
        {"COM10", 48},
        {"COM11", 49},
        {"COM12", 50},
        {"COM13", 51},
        {"COM14", 52}
    };

    #endif

    int set(const string);
    void showoptions();
};

class SerialPort{

public:

    Status status;
    Parity parity;
    BaudRate baudrate;
    StopBits stopbits;
    PortName portname;
    DataBits databits;
    FlowControl flowcontrol;

    SerialPort(const string, const string, const string, const string, const string, const string);
    ~SerialPort();
    Status connect();
    Status disconnect();
    int receive(unsigned char *);
    void flush();
};

#endif //_SERIAL_H
