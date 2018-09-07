#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"
#include <iostream>
using namespace std;

template <typename T>
class Iterator {
    protected:
        Node<T>* current;

    public:
        Iterator() : current(NULL) {};
        Iterator(Node<T>* current) : current(current) {};

        Iterator<T> operator=(Iterator<T> other);
        bool operator!=(Iterator<T> other);
        T operator*();
};

template<typename T> Iterator<T> Iterator<T>::operator=(Iterator<T> other)
{
    //sobrecargar de igual

    Iterator<T> temp;
    temp.current=other.current;

    return temp;
}


template<typename T> bool Iterator<T>::operator!=(Iterator<T> other)
{
    //sobrecarga

    if (current==other.current)
    {
        return false;

    }
    else{
        return true;
    }

}

template<typename T> T Iterator<T>::operator*()
{

    return current->data;
}

#endif
