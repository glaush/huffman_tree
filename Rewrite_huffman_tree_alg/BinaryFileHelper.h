#pragma once
#include <fstream>
#include <vector>
#include <iterator>
#include <sstream>
#include <algorithm>
#include "TransformUtils.h"

using namespace std;

class BinaryFileHelper
{
public:
    static streampos get_file_size(const string&);

    static void write(const string& , const vector<unsigned char>& );
    static string read(const string&, const int = 1000);

private:
    BinaryFileHelper();

};
