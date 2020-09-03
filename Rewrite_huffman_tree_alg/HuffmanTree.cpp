#include "HuffmanTree.h"

HuffmanTree::HuffmanTree(const string& data)
{
    init(data);
}

void HuffmanTree::init(const string& data)
{
    auto symbols_dictionary = create_dictionary(data);
}

void HuffmanTree::create_binary_tree(vector<SymbolPtr>&)
{
}

map<char, SymbolPtr> HuffmanTree::create_dictionary(const string& data) const
{
    map<char, SymbolPtr> symbols_dict;

    for (const auto& c: data)
    {
        auto pos = symbols_dict.find(c);
        if (pos != symbols_dict.end())
        {
            ++(*pos->second);
            continue;
        }
        symbols_dict.insert(make_pair(c, static_pointer_cast<Symbol>(make_shared<Symbol>(c))));
    }
    return symbols_dict;
}

vector<SymbolPtr> HuffmanTree::move_to_vector(map<char, SymbolPtr>&) const
{
    return vector<SymbolPtr>();
}
