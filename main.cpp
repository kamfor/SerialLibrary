#include <iostream>
#include "include/serial.h"
#include "include/interface.h"
#include "include/buffer.h"
#include "include/handlefile.h"
using namespace std;

int main()
{    
    SerialPort* connection = new SerialPort("Baud9600", "NoParity", "OneStop", "Data8", "ttyACM0", "NoFlowControl");
    Buffer buffer(1024,'\n');
    Interface console;
    HandleFile newfile("data.txt");
    int i,j =0;

    /*console.setbaud(connection);

    console.clearscreen();

    console.setparity(connection);

    console.clearscreen();

    console.setstop(connection);

    console.clearscreen();

    console.setdata(connection);

    console.clearscreen();

    console.setport(connection);

    console.clearscreen();

    console.setflow(connection);

    console.clearscreen();*/

    console.showconnectionoptions(connection);

    connection->connect();

    connection->flush();

    usleep(100000);

    while(1){

        i = connection->receive(buffer.data);
        cout<<buffer.show(i);
        newfile.WriteToFile(buffer.show(i));
        connection->flush();
        usleep(1000000);
        j++;
        if(j>20) break;
    }

    connection->disconnect();

    return 0;
}
