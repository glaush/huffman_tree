#include "Node.h"


template<typename T>
inline Node<T>::Node(const T)
{
}

template<typename T>
inline Node<T>::Node(const T, const int)
{
}

template<typename T>
inline Node<T>::Node(const int)
{
}

template<typename T>
inline Node<T>::Node(const int, const shared_ptr<Node>&, const shared_ptr<Node>&)
{
}

template<typename T>
inline int Node<T>::get_count() const
{
    return count;
}

template<typename T>
inline T Node<T>::get_value() const
{
    return value;
}

template<typename T>
inline const shared_ptr<Node<T>>& Node<T>::get_left() const
{
    return left;
}

template<typename T>
inline const shared_ptr<Node<T>>& Node<T>::get_right() const
{
    return right;
}


template<typename T>
Node<T>& Node<T>::operator++()
{
    ++count;
    return *this;
}

template class Node<char>;