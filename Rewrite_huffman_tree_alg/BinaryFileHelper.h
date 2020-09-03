#pragma once
#include <fstream>

using namespace std;

class BinaryFileHelper
{
public:
    static streampos get_file_size(const string&);
private:
    BinaryFileHelper();

};
