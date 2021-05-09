//Rayan Ayouaz
//000429095
//LANGAGE 2
// 2019
// :Vecteur creux


#include "Abr.hpp"
#include <stdexcept> //standart error
#include <iostream>
#include <cstddef>
#include <vector>

//EXPLICATIONS DES WARNINGS:
//TODO
//
//176::getIndex(): semantic reaches end of non-void function but more intelligent control is okay
//class Node and class Abr has pointer data member but it's a classic implementation of it
//
template<typename T>
struct VI{ //"VI" represent Val/Index
	int index; 
	T val;
	VI(int a, T b) : index(a), val(b) {};
	VI(int a) : index(a){};
	VI() : val(0) {};
	//operators for fitting in Abr methods
	bool operator==(VI const & rhs) const {return this->index == rhs.index;}
	bool operator!=(VI const & rhs) const {return this->index != rhs.index;}
	bool operator<(VI const & rhs) const {return this->index < rhs.index;}
	bool operator<=(VI const & rhs) const {return this->index <= rhs.index;}
	bool operator>(VI const & rhs) const {return this->index > rhs.index;}
	bool operator>=(VI const & rhs) const {return this->index >= rhs.index;}
};

template<typename T>
class Array: public Abr<VI<T>>{ 
	private:
	struct Proxy{
		//Proxy class used for multiple use of []
		int index;
		Array<T>& a;
		Proxy(int i, Array<T>& array) : index(i), a(array){};
		operator T(){ return a.getIndex(index);}; //getting by conversion
		Proxy& operator=(T); //setting 
	};
	int ind = 0;
	int _size = 0;
	protected:
	virtual void insert(VI<T> val) override;
	T getIndex(int val) const;
	void copyRecurs(Node<VI<T>>*, Node<VI<T>>*);
	T* infixeArray = nullptr;
	T* parcours();
	void infixe(std::vector<Node<VI<T>>*>&,Node<VI<T>>*);
	void prefixe(std::vector<Node<VI<T>>*>&,Node<VI<T>>*,int);
	void setSize(int);
	public:
	class Iterator{
		public:
		Iterator(Array<T>* array=nullptr, int index=-1);
		const T operator*() const;
		Iterator& operator++();
		bool operator!=(const Iterator& other) const;
		private:
		const Array<T>* m_array;
		int m_index = -1;
	};
	Array(int size); //size on init
	Array(const Array&); //copy 
	Array& operator=(Array&); //move
	virtual int getSize() const override; 
	int getAbrSize() const;
	Node<VI<T>>* empty();
	Proxy operator[](int index);
	Iterator begin();
	Iterator end();
	void count();
	virtual ~Array();
};

template <typename T>
void  Array<T>::setSize(int size){
	_size = size;
}
template <typename T>
typename Array<T>::Iterator Array<T>::begin(){
	if (infixeArray != nullptr){
		delete infixeArray; //erase previous iteration
	};
	infixeArray = parcours(); //explore one time the nodes and
	//get the result in class attribut
	return Array<T>::Iterator(this,0);
}

template <typename T>
typename Array<T>::Iterator Array<T>::end(){
	return Array<T>::Iterator(this, Abr<VI<T>>::_size);
}


template <typename T>
Array<T>::Iterator::Iterator(Array<T>* pArray, int pIndex)
: m_array(pArray), m_index(pIndex){} //pointer to motherclass for calling methods


template <typename T>
const T Array<T>::Iterator::operator*() const{
	if (m_array->infixeArray != nullptr){
		return m_array->infixeArray[m_index];
	}else{
		return static_cast<T>(false);
		//return false;
	}
}

template <typename T>
typename Array<T>::Iterator &Array<T>::Iterator::operator++(){
	++m_index;
	return *this;
}

template <typename T>
bool Array<T>::Iterator::operator!=(const Array<T>::Iterator &other) const{
	return m_index != other.m_index; //other is often construct with end method
}

template <typename T>
typename Array<T>::Proxy& Array<T>::Proxy::operator=(T val2){
	a.insert(VI<T>(index,val2));
	return *this;
}

template <typename T>
typename Array<T>::Proxy Array<T>::operator[](int index){ 
	if (index >= _size){
		throw std::out_of_range("Index out of range");
	}else{
		return Proxy(index,*this);	
	};
}


template <typename T>
Array<T>::Array(int size) : _size(size){}

template <typename T>
int Array<T>::getSize() const{
	return _size;
}

template <typename T>
int Array<T>::getAbrSize() const{
	return Abr<VI<T>>::_size;
}
	
template <typename T>
void Array<T>::copyRecurs(Node<VI<T>>* node_a, Node<VI<T>>* node){
	//quick copy following tree structure
	if (node_a != nullptr){
		Node<VI<T>>* new_node;
		new_node = new Node<VI<T>>();
		this->copyRecurs(node_a->getLeft(),new_node);
		if (new_node->getValue().val != 0){
			node->setLeft(new_node);
		};
		VI<T> adhoc;
		adhoc.val = node_a->getValue().val;
		adhoc.index = node_a->getValue().index;
		node->setValue(adhoc);
		Abr<VI<T>>::_size++;
		new_node = new Node<VI<T>>();
		this->copyRecurs(node_a->getRight(), new_node);
		if (new_node->getValue().val != 0){
			node->setRight(new_node);
		};
	};
}


template <typename T>
Array<T>::Array(const Array<T>& a) : _size(0){
	_size = a.getSize();
	Abr<VI<T>>::setRoot(new Node<VI<T>>());
	this->copyRecurs(a.getRoot(),Abr<VI<T>>::getRoot());
}

template <typename T>
T Array<T>::getIndex(int index) const{
    Node<VI<T>>* node = Abr<VI<T>>::getRoot();
    bool find = false;
    while (node != nullptr){
        if (index < node->getValue().index){
            node = node->getLeft();
        }else{
            if(index == node->getValue().index){
				//target node
                VI<T> vi = node->getValue();
				T res = vi.val;
                node = nullptr;
                find = true;  
				return res;
            }else{
                if(index > node->getValue().index){
                node = node->getRight();
                };
            };
        };
    };
	if (not find){
        //explicit conversion to false if null val
        T boolT = find; 
		T& res = boolT;
		return res;
    };
}



template <typename T>
T* Array<T>::parcours(){
	std::vector<Node<VI<T>>*> vect;
	this->infixe(vect,Abr<VI<T>>::getRoot());
	T* array2 = new T[Abr<VI<T>>::_size];
	int i = 0;
	for (typename std::vector<Node<VI<T>>*>::iterator it = vect.begin() ; it != vect.end(); ++it){
		Node<VI<T>>* node = *it;
		array2[i] = (node->getValue()).val;
		i++;
	};
	return array2;
}
template <typename T>
void Array<T>::count(){
	std::vector<Node<VI<T>>*> vect;
	prefixe(vect,Abr<VI<T>>::getRoot(),0);
}

template <typename T>
void Array<T>::prefixe(std::vector<Node<VI<T>>*>& inf, Node<VI<T>>* node, int a){
    if (node == nullptr){
        return;
    };
	std::cout << a << "; ";
	inf.push_back(node);
    prefixe(inf,node->getLeft(),a+1);
	prefixe(inf,node->getRight(),a+1); 
}



template <typename T>
void Array<T>::infixe(std::vector<Node<VI<T>>*>& inf, Node<VI<T>>* node ){
    if (node == nullptr){
        return;
    };
    infixe(inf,node->getLeft());
	inf.push_back(node);
    infixe(inf,node->getRight());
}



template <typename T>
void Array<T>::insert(VI<T> val){
	bool set = false;
	Node<VI<T>>* node = nullptr;
	Node<VI<T>>* father_node = nullptr;
	Node<VI<T>>* new_node;
	if (Abr<VI<T>>::getRoot() == nullptr){
		//if root is empty
		new_node = new Node<VI<T>>;
		new_node->setValue(val);
		Abr<VI<T>>::setRoot(new_node);
		Abr<VI<T>>::_size++;
	}else{
		node = Abr<VI<T>>::getRoot();
		while (node != nullptr and !set){
			father_node = node;
			if (node->getValue() > val){
				node = node->getLeft();
			}else{
				if(node->getValue() == val){
					node->setValue(val);
					set = true;
				}else{
					node = node->getRight();
				};
			};
		};
		if (not set){
			new_node = new Node<VI<T>>;
			new_node->setValue(val);
			//if not already set create new
			Abr<VI<T>>::_size++;
			if (father_node->getValue() >= val){
				father_node->setLeft(new_node);
			}else{
				father_node->setRight(new_node);
			};
		};
	};
}

template <typename T>
Array<T>& Array<T>::operator=(Array<T>& a){
	//transfering root from the other array
	//size is not adapted
	Abr<VI<T>>::_size = a.getAbrSize(); //Abr::size change for integrity
	Abr<VI<T>>::setRoot(a.empty());
	return *this;
}
template <typename T> 
Node<VI<T>>* Array<T>::empty(){
	Node<VI<T>>* res = this->getRoot();
	Abr<VI<T>>::setRoot(nullptr);
	_size = 0;
	Abr<VI<T>>::_size = 0;
	return res;
}

template <typename T>
Array<T>::~Array(){
	if (infixeArray != nullptr){
		delete infixeArray;
	};
}
