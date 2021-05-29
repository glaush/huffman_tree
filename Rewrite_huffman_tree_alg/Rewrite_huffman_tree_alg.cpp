#include <iostream>
#include <fstream>
#include "HuffmanTree.h"
#include "BinaryFileHelper.h"
#include "TransformUtils.h"

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
        const auto encoded = huffman_tree.encode(file_content);
        const auto bytes = TransformUtils::transform_string_to_bytes(encoded);

        BinaryFileHelper::write(output, bytes);
        const auto after_size = BinaryFileHelper::get_file_size(output);
        const auto delta = file_size - after_size;

        cout << "After compression: " << delta << " bytes" << endl;
        const auto output_data = BinaryFileHelper::read(output);
        huffman_tree.decode(output_data);
        return 0;
    }
    catch (const std::exception& e)
    {
        cin.get();
        return -1;
    }
}
