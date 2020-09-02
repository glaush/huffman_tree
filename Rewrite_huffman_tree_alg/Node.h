#pragma once
#include <memory>

using std::shared_ptr;

template<typename T>
class Node
{
    Node(const T);
    Node(const T, const int);
    Node(const int);
    Node(const int,
        const shared_ptr<Node<T>>, const shared_ptr<Node<T>>);

    int get_count();

private:
    shared_ptr<Node<T>> left;
    shared_ptr<Node<T>> right;

    int count;
    T value;
};