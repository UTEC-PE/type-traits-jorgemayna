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

            this->current=this->current->next;
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

        bool insert(T data) { // No estás retornando nada, el return debería ser un boolean
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

        bool remove(T item) { // No estás retornando nada, el return debería ser un boolean
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

            SListIterator<T> temp1(temp->next); // Podrías retornar directamente un iterador a nullptr


            return temp1;

        }



        ~SList() {
            if (head) {
                head->killSelf();
            }
        }
};

#endif
