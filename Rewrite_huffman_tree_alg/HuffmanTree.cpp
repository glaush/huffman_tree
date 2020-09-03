#include "HuffmanTree.h"

HuffmanTree::HuffmanTree(const string& data)
{
    init(data);
}

void HuffmanTree::init(const string& data)
{
    auto symbols_dictionary = create_dictionary(data);
    auto symbols_vect = move_to_vector(symbols_dictionary);

    create_binary_tree(symbols_vect);

}

void HuffmanTree::create_binary_tree(vector<SymbolPtr>& vec)
{
    auto symbol_comparator = [](const SymbolPtr a, const SymbolPtr b)
    {
        return a->get_count() < b->get_count();
    };

    while (vec.size() > 1)
    {
        std::sort(vec.begin(), vec.end(), symbol_comparator);

        auto left = vec.front();
        auto right = (*++vec.begin());
        auto node = new Node<char>(left->get_count() + right->get_count(), left, right);
    
        vec.erase(vec.begin(), vec.begin() + 2);
        vec.push_back(SymbolPtr(node));
    }
    binary_tree = vec.front();
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

vector<SymbolPtr> HuffmanTree::move_to_vector(map<char, SymbolPtr>& dictionary) const
{
    vector<SymbolPtr> symbols;
    symbols.reserve(dictionary.size());
    for_each(dictionary.begin(), dictionary.end(), [&symbols](pair<const char, SymbolPtr>& symbol)
    {
        symbols.push_back(move(symbol.second));
    });
    return symbols;
}
