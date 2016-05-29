#include<cstdio>
#include<iostream>
#include "../include/interface.h"

using namespace std;

Interface::Interface()
{
    cout<<"SerialReceiverConsole\n"<<endl;
    cout<<"Chose connection parameters\n"<<endl;
}

void Interface::clearscreen(){

    printf("\033[2J");
    printf("\033[0;0f");
}

void Interface::setbaud(SerialPort* any){

    string i;
    cout<<"Type baudrate name from list below\n"<<endl;
    any->baudrate.showoptions();
    do{
         cin>>i;
    } while(any->baudrate.set(i));
}

void Interface::setparity(SerialPort* any){

    string i;
    cout<<"Type parity type name from list below\n"<<endl;
    any->parity.showoptions();
    do {
        cin>>i;
    }while(any->parity.set(i));
}

void Interface::setstop(SerialPort* any){

    string i;
    cout<<"Type stop bits name from list below\n"<<endl;
    any->stopbits.showoptions();
    do{
        cin>>i;
    }while(any->stopbits.set(i));
}

void Interface::setdata(SerialPort* any){

    string i;
    cout<<"Type data bits name from list below\n"<<endl;
    any->databits.showoptions();
    do{
        cin>>i;
    }while(any->databits.set(i));
}

void Interface::setport(SerialPort* any){

    string i;
    cout<<"Type port name from list below\n"<<endl;
    any->portname.showoptions();
    do{
        cin>>i;
    }while(any->portname.set(i));
}

void Interface::setflow(SerialPort* any){

    string i;
    cout<<"Type flow control type from list below\n"<<endl;
    any->flowcontrol.showoptions();
    do{
        cin>>i;
    }while(any->flowcontrol.set(i));
}

void Interface::showconnectionoptions(SerialPort* any){

    cout<<"Chosen connection parameters:"<<endl;
    cout<<"Baud rate:"<<any->baudrate.current->first<<endl;
    cout<<"Parity:"<<any->parity.current->first<<endl;
    cout<<"Stop bits:"<<any->stopbits.current->first<<endl;
    cout<<"Data bits:"<<any->databits.current->first<<endl;
    cout<<"Port name:"<<any->portname.current->first<<endl;
    cout<<"Flow control:"<<any->flowcontrol.current->first<<endl;
}



