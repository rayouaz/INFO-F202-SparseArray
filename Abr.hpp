//Rayan Ayouaz
//000429095
//LANGAGE 2
// 2019
// :Vecteur creux




#include "Node.hpp"
#include <iostream>
template <typename T>
class Abr{
	Node<T>* _root;
	protected:
	int _size;
	Node<T>* getRoot() const;
	void setRoot(Node<T>*);
	//delete nodess
	public:
	virtual int getSize() const;
	virtual void insert(T val);
	Abr();
	virtual ~Abr(); 
};

template <typename T>
Abr<T>::Abr() :  _root(nullptr), _size(0){}

template <typename T>
Node<T>* Abr<T>::getRoot() const{
	return _root;
}

template <typename T>
void Abr<T>::setRoot(Node<T>* root){
	_root = root;
}

template <typename T>
int Abr<T>::getSize() const{
	return _size;
}


template <typename T>
void Abr<T>::insert(T val){
    _size++;
    Node<T>* father_node = nullptr;
    Node<T>* node = nullptr;
    Node<T>* root = this->getRoot();
    Node<T>* new_node = new Node<T>;
    new_node->setValue(val);
    //if first node
    if (root == nullptr){
        this->setRoot(new_node);
    }else{
        //else place it
        node = root;
        while (node != nullptr){
            father_node = node;
            if (val < node->getValue()){
                node = node->getLeft();
            }else{
                node = node->getRight();
            };
        };
        if (val <= father_node->getValue()){
            father_node->setLeft(new_node);
        }else{
            father_node->setRight(new_node);
        };
    };
}
   

template <typename T>
Abr<T>::~Abr(){	
	if (this->getRoot() != nullptr){
		delete (this->getRoot());//delete nodes
	};
} 




