#ifndef BUFFER_H
#define BUFFER_H

/*!
* \file
* \brief Definicja klasy Buffer
*
* Plik zawiera definicję klasy Buffer, która
* odpowiada za obsługę bufora odbieranych danych
*/

#include <iostream>
using namespace std;


class Buffer{

public:

    unsigned char * data;
    char terminator;
    int size;
    Buffer(int, char);
    ~Buffer();
    unsigned char* fill();
    void flush();
    string show(int);
};

#endif // BUFFER_H
