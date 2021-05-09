//Rayan Ayouaz
//000429095
//LANGAGE 2
// 2019
// :Vecteur creux




#include <iostream>
template <typename T>
class Node{
	Node<T>* _left = nullptr;
	Node<T>* _right = nullptr;
	T _value;
	public:
	Node();
	//getters
	Node<T>* getLeft() const;
	Node<T>* getRight() const;
	T getValue() const;
	//setters
	void setLeft(Node<T>*);
	void setRight(Node<T>*);
	void setValue(T);
	~Node();
};



template <typename T>
Node<T>::Node() : _value(0), _left(nullptr), _right(nullptr){}

template <typename T>
Node<T>* Node<T>::getLeft() const{
	return _left;	
}

template <typename T>
Node<T>* Node<T>::getRight() const{
	return _right;
}

template <typename T>
T Node<T>::getValue() const{
	return _value;
}

template <typename T>
void Node<T>::setLeft(Node<T>* nodeptr){
	_left = nodeptr;
}

template <typename T>
void Node<T>::setRight(Node<T>* nodeptr){
	_right = nodeptr;
}

template <typename T>
void Node<T>::setValue(T val){
	_value = val;
}

template <typename T>
Node<T>::~Node(){
	if (_left != nullptr){
		delete this->_left;
	};
	if (this->_right != nullptr){
		delete this->_right;
	};
}
