#ifndef SLIST_H
#define SLIST_H
#include<iostream>
#include "iterator.h"
using namespace std;

template <class T>
class SListIterator : public Iterator<T> {
    public:
        SListIterator() : Iterator<T>() {};
        SListIterator(Node<T> *current) : Iterator<T>(current) {};
        SListIterator<T> operator++(){

            Iterator<T>::current=Iterator<T>::current->next;
            return *this;
        };
};



template <typename Tr>
class SList {
    public:
        typedef typename Tr::T T;
        typedef typename Tr::Operation Operation;
        typedef SListIterator<T> iterator;

    private:
        Node<T>* head;
        Operation cmp;

    public:
        SList() {
            head = nullptr;


        };

        bool find(T search, Node<T> **&pointer) {
            // TODO

            pointer=&head;

            if(head!=nullptr)
            {
                do
                {



                    if(search!=(*pointer)->data)
                    {

                        if(cmp(search,(*pointer)->data))
                        {

                            pointer=&((*pointer)->next);
                        }
                        else{
                            return false;
                        }
                    }
                    else{
                        return true;
                    }

                }while((*pointer)!=nullptr);
                return false;

            }else{
                return false;
            }


        }

        bool insert(T data) {
            // TODO
            Node<T>** ggbk;


            if(!find(data,ggbk))
            {

                Node<T>* temp=(*ggbk);
                *ggbk=new Node<T>(data);
                (*ggbk)->next=temp;

            }else{
                cout <<"El valor ya existe"<<endl;
            }




        }

        bool remove(T item) {
            // TODO
            Node<T>** mario;
            if(find(item,mario))
            {
                Node<T>* temp=((*mario)->next);
                delete *mario;
                *mario=temp;
            }
            else{
                cout <<"La lista no contiene el valor"<<endl;
            }
        }

        iterator begin() {
            // TODO

            iterator temp(head);


            return temp;
        }

        iterator end() {
            // TODO

            Node<T>* temp=head;
            while(temp->next!=nullptr)
            {
                temp=temp->next;
            }

            SListIterator<T> temp1(temp);


            return temp1;

        }

        void dato()
        {
            cout<< head->data<<endl;
            cout<< head->next->data<<endl;
            cout<< head->next->next->data<<endl;
            cout<< head->next->next->next->data<<endl;
            cout<< head->next->next->next->next->data<<endl;

        }

        ~SList() {
            if (head) {
                head->killSelf();
            }
        }
};

#endif
