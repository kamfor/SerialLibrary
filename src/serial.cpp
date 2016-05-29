#include <iostream>
#include "../include/serial.h"
#include "../include/rs232.h"

using namespace std;


const string Element::getstring(){ 
	
	return current->first;
}

int Element::getint(){
	
	return current->second;
}

int Status::set(const string input){

    current = value.find(input);
    if(current == value.end())return 1;

    return 0;
}


int Parity::set(const string input){

    current = value.find(input);
    if(current == value.end())return 1;

    return 0;
}

void Parity::showoptions(){

    for(current=value.begin(); current!=value.end(); ++current){

        cout<<current->first<<endl;
    }
    cout<<endl;
}

int BaudRate::set(const string input){

    current=value.find(input);
    if(current == value.end())return 1;

    return 0;

}

void BaudRate::showoptions(){

    for(current=value.begin(); current!=value.end(); ++current){

        cout<<current->first<<endl;
    }
    cout<<endl;
}

int StopBits::set(const string input){
	
     current=value.find(input);
     if(current==value.end())return 1;

     return 0;
}

void StopBits::showoptions(){

    for(current=value.begin(); current!=value.end(); ++current){

        cout<<current->first<<endl;
    }
    cout<<endl;
}

int DataBits::set(const string input){
	
    current=value.find(input);
    if(current==value.end())return 1;

    return 0;
}

void DataBits::showoptions(){

    for(current=value.begin(); current!=value.end(); ++current){

        cout<<current->first<<endl;
    }
    cout<<endl;
}

int FlowControl::set(const string input){
    
    current=value.find(input);
    if(current==value.end())return 1;

    return 0;
}

void FlowControl::showoptions(){

    for(current=value.begin(); current!=value.end(); ++current){

        cout<<current->first<<endl;
    }
    cout<<endl;
}

int PortName::set(const string input){
    
    current=value.find(input);
    if(current==value.end())return 1;

    return 0;
}

void PortName::showoptions(){

    for(current=value.begin(); current!=value.end(); ++current){

        cout<<current->first<<endl;
    }
    cout<<endl;
}

SerialPort::SerialPort(const string baud, const string par, const string stop, const string data, const string port, const string flow){
	
    baudrate.set(baud);
    parity.set(par);
    stopbits.set(stop);
    databits.set(data);
    portname.set(port);
    flowcontrol.set(flow);
    status.set("Disconnected");

}

SerialPort::~SerialPort(){

    this->disconnect();
}

Status SerialPort::connect(){ //functions from rs232.c

    if(RS232_OpenComport(portname.getint(), baudrate.getint(), databits.getint(), parity.getint(), stopbits.getint(), flowcontrol.getint())){

        status.set("Error");
    }
    else{
        status.set("Commected");
    }

    return status;
}

Status SerialPort::disconnect(){

    RS232_CloseComport(portname.getint());

    status.set("Disconnected");

    return status;
}

int SerialPort::receive(unsigned char * buffer){

    int n = RS232_PollComport(portname.getint(),buffer, 37);

    return n;
}

void SerialPort::flush(){

    RS232_flushRX(portname.getint());
}

