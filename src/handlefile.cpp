#include "../include/handlefile.h"

HandleFile::HandleFile(const string patch){

    file.open(patch.c_str(),ios::app);
    if(!file.good())throw "Unable to open file";
}

HandleFile::~HandleFile(){

    file.close();
}

void HandleFile::WriteToFile(string data){

    file<<data;
}
