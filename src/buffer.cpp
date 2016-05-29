#include <iostream>
#include "../include/buffer.h"
#include "../include/rs232.h"
#include "../include/serial.h"

using namespace std;

Buffer::Buffer(int nofbytes, char ter){

    size = nofbytes;
    data = new unsigned char[nofbytes];
    terminator = ter;
}

Buffer::~Buffer(){

    free(data);
}

unsigned char* Buffer::fill(){

    return data;
}

void Buffer::flush(){

    data[0] = 0;// to change
}

string Buffer::show(int lenght){

    string line;

    for(int i=0; i<lenght-1; i++){
      line+=data[i];
    }
    line+="\n";

    return line;
}
