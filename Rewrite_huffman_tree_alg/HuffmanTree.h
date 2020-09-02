#pragma once
#include <memory>
#include <algorithm>
#include <vector>
#include <sstream>
#include <iostream>
#include <map>
#include "Node.h"

using namespace std;

typedef Node<char> Symbol;
typedef shared_ptr<Symbol> SymbolPtr;

class HuffmanTree
{
public:
    HuffmanTree(const string&);


private:
    void create_binary_tree(vector<SymbolPtr>&) const;
    vector<SymbolPtr> move_to_vector(map<char, SymbolPtr>&) const;


    SymbolPtr binary_tree;
    map<char, string> hash_table;

};