/*
 * Rayan Ayouaz
 * LDP 2/ULB 
 * Vecteur Creux Equilibré
 * 2019
 * 000429095
*/

#include "Array.hpp"

template <typename T> 
class BalancedArray : public Array<T>{
	private:	
	Node<VI<T>>* buildTree(std::vector<Node<VI<T>>*>&,int,int);
	public:
	BalancedArray(int size);
	BalancedArray<T>& operator=(BalancedArray&);
    BalancedArray(const BalancedArray&); //copy 
	virtual ~BalancedArray(){};
};

template <typename T>
BalancedArray<T>::BalancedArray(const BalancedArray<T>& a) : Array<T>(0){
	Array<T>::setSize(a.getSize());
	Array<T>::setRoot(new Node<VI<T>>());
	Array<T>::copyRecurs(a.getRoot(),Array<T>::getRoot());
}


template <typename T>
BalancedArray<T>::BalancedArray(int size) : Array<T>(size){}
template <typename T>
BalancedArray<T>& BalancedArray<T>::operator=(BalancedArray& a){
	if (&a != this){
		Array<T>::operator=(a);
	}else{
		std::vector<Node<VI<T>>*> vect;
		Array<T>::infixe(vect,Array<T>::getRoot());
		Node<VI<T>>* node = buildTree(vect,0,Array<T>::getAbrSize()-1);
		Array<T>::setRoot(node);
	}
}
template <typename T>
Node<VI<T>>* BalancedArray<T>::buildTree(std::vector<Node<VI<T>>*>& inf, int start, int end) 
{ 
    // base case 
	if (start > end) 
        return nullptr; 
  
    // Get the middle element and make it root 
    int mid = (start + end)/2; 
    Node<VI<T>>* node = inf[mid]; 
  
    // Using index in Inorder traversa
    node->setLeft(buildTree(inf, start, mid-1)); 
    node->setRight(buildTree(inf, mid+1, end)); 
  
    return node; 
} 
