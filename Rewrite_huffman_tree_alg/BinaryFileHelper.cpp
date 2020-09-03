#include "BinaryFileHelper.h"

streampos BinaryFileHelper::get_file_size(const string& filename)
{
    ifstream file(filename, ios::binary | ios::ate);
    return file.tellg();
}
