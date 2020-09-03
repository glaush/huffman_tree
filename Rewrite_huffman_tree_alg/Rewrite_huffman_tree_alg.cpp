#include <iostream>
#include <fstream>
#include "HuffmanTree.h"
#include "BinaryFileHelper.h"


int main()
{
				try
				{
								const auto input = "sampleinputtxtfile.txt";
								const auto output = "sampleoutputtxtfile.bin";

								ifstream file("sampleinputtxtfile.txt");
								if (!file.is_open()) throw std::runtime_error("Exception: Unable to open file.");

								stringstream stream;
								stream << file.rdbuf();
								file.close();

								const auto file_content = stream.str();
								const auto file_size = BinaryFileHelper::get_file_size(input);

								cout << "Before compression: " << file_size << " bytes" << endl;

								HuffmanTree huffman_tree(file_content);

								return 0;
				}
				catch (const std::exception&)
				{

				}
    


}
