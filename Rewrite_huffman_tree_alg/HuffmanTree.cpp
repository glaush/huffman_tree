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
    create_hash_table(symbols_dictionary);
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

void HuffmanTree::create_hash_table(map<char, SymbolPtr> dictionary)
{
    for (const auto& sym : dictionary)
    {
        auto exists = false;
        auto path = find_path(*binary_tree, sym.first, exists);

        if (!exists) throw exception("Exception: Invalid dictionary for given data.");

        hash_table.insert(pair<char, string>(sym.first, path));
    }
}

string HuffmanTree::find_path(Symbol& node, const char& c, bool& flag, string path)
{
    if (flag) return path;

    auto result(path);

    /*This string of code use to get some logs
    cout << "Current node:" << node.get_count() << endl;*/
    if (node.has_left())
    {
        result = find_path(*node.get_left(), c, flag, path + "0");
    }

    if (node.has_right() && !flag)
    {
        result = find_path(*node.get_right(), c, flag, path + "1");
    }

    if (!node.get_left() && !node.get_right() && node.get_value() == c)
    {
        flag = true;
    }

    return result;
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


