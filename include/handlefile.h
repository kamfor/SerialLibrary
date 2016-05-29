#ifndef HANDLEFILE_H
#define HANDLEFILE_H

#include <iostream>
#include <fstream>

using namespace std;


class HandleFile
{
    fstream file;
    string filename;

public:

    HandleFile(const string patch);
    ~HandleFile();
    void WriteToFile(string);
};

#endif // HANDLEFILE_H
