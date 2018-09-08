#ifndef DLIST_H
#define DLIST_H

#include "iterator.h"
#include<iostream>
using namespace std;

template <typename T>
class DListIterator : public Iterator<T> {
    public:
        DListIterator() : Iterator<T>() {};
        DListIterator(Node<T> *current) : Iterator<T>(current) {};
        DListIterator<T> operator++()
        {
            Iterator<T>::current=Iterator<T>::current->next;
            return *this;

        };
        DListIterator<T> operator--()
        {
            Iterator<T>::current=Iterator<T>::current->prev;
            return *this;
        };
};

template <typename Tr>
class DList {
    public:
        typedef typename Tr::T T;
        typedef DListIterator<T> iterator;

    private:
        Node<T>* head;
        Node<T>* tail;

    public:
        DList() {
            head = tail = nullptr;
        };

        void push_front(T data) {
            // TODO

        Node<T>* temp = new Node<T>(data);


        if (head==nullptr)
        {

            tail=temp;
            head=tail;



        }
        else{

            temp->prev=nullptr;
            temp->next=head;
            head->prev=temp;
            head=temp;
            temp=nullptr;
        }


        }

        void push_back(T data) {
            // TODO

        Node<T>* temp = new Node<T>(data);
        temp->next=nullptr;

        if (head==nullptr)
        {

            head=temp;
            head=tail;


        }
        else{

            tail->next=temp;

            temp->prev=tail;

            tail=temp;




        }


        }

        void pop_front() {
            // TODO
            if(head!=tail)
            {
                Node<T>* temp=head->next;
                delete head;
                temp->prev=nullptr;
                head=temp;

            }
            else{
                delete head;
                head=nullptr;
                tail=nullptr;

            }
        }


        void pop_back() {
            // TODO
            if(head!=tail)
            {
                Node<T>* temp=tail->prev;
                delete tail;
                temp->next=nullptr;
                tail=temp;

            }
            else{
                delete head;
                head=nullptr;
                tail=nullptr;

            }
        }

        void print()
        {
            cout<<head->data<<endl;

        }

        iterator begin() {

            // TODO
            DListIterator<T> temp(head);

            return temp;
        }

        iterator end() {
            // TODO
            DListIterator<T> temp(tail);


            return temp;
        }

        ~DList() {
            if (head) {
                head->killSelf();
            }
        }
};

#endif
