//Rayan Ayouaz
//000429095
//LANGAGE 2
// 2019
// :Vecteur creux



#include <iostream>
#include "BalancedArray.hpp"
int main(){
	int size = 35;
	BalancedArray<int> container(size);
	//Array<int> container(size);
	std::cout<<"Insert A [29]->42, [25]->12, [20]->11, [17]->10, [14]->34, [11]->9, [33]->32, [7]->3, [5]->2";
	container[29] = 42;
	container[25] = 12;
	container[20] = 11;
	container[17] = 10;
	container[14] = 34;
	container[11] = 13;
	container[11] = 9;
	container[33] = 32;
	container[7] = 3;
	container[5] = 2;
	std::cout << "\nTableau A: \n";
	for (int i=0; i<container.getSize(); i++){
		std::cout << container[i] << "|";
	};
	//parcours de l'arbre
	std::cout << "\nArbre A: \n";
	BalancedArray<int>::Iterator it;
	for (it=container.begin(); it!=container.end(); ++it){
		std::cout << *it << "|";
	};
	//containerB est une copie de container A 
	BalancedArray<int> containerB(container);
	//On s'attend aux mêmes valeurs
	std::cout << "\nB est une copie de A \n";
	std::cout <<"Tableau B: \n";
	for (int  i=0; i<containerB.getSize(); i++){
		std::cout << containerB[i] << "|";
	};
	//parcours de l'arbrea
	std::cout << "\nArbre B: \n";
	for (it=containerB.begin(); it!=containerB.end(); ++it){
		std::cout << *it << "|";
	};
	//container C initialiser
	std::cout << "\nB transféré dans C (plus grand) \n";
	BalancedArray<int> containerC(40);
	containerC = containerB;
	//containerC contient tout les objets de containerB
	//containerB est vide et containerC à la taille de containerB
	//parcours du tableau pour C
	std::cout << "Tableau C: \n" << "|";
	for (int i=0; i<containerC.getSize(); i++){
		std::cout << containerC[i] << "|";
	};
	//parcours de l'arbre
	std::cout << "\nArbre C: \n";
	for (it=containerC.begin(); it!=containerC.end(); ++it){
		std::cout << *it << "|";
	};
	std::cout << "\nTableau B: \n";
	//parcours du tableau
	for (int i=0; i<containerB.getSize(); i++){
		std::cout << containerB[i] <<"|";
	};
	std::cout << "\n";
	//rebalancement
	containerC = containerC;
	std::cout << "Rebalancement: ";
	std::cout << "\nArbre C: \n";
	for (it=containerC.begin(); it!=containerC.end(); ++it){
		std::cout << *it << "|";
	};
	std::cout <<"\n";
	std::cout<<"\nDeepness of A (recursive prefix) by level: 7 left / 1 right\n";
	container.count();
	std::cout <<"\nDeepness of C (recursive) by level: 3 left / 3 right\n";
	containerC.count();
	std::cout << std::endl;
	std::cout << "\nTableau 2 avec float\n";
	BalancedArray<float> container2(size);
	//Array<int> container(size);
	std::cout<<"Insert 2 [29]->4.2, [25]->1.2, [20]->1.1, [17]->1.0, [14]->3.4, [11]->0.9, [33]->3.2, [7]->0.3, [5]->0.2";
	container2[29] = 4.2;
	container2[25] = 1.2;
	container2[20] = 1.1;
	container2[17] = 1.0;
	container2[14] = 3.4;
	container2[11] = 1.3;
	container2[11] = 0.9;
	container2[33] = 3.2;
	container2[7] = 0.3;
	container2[5] = 0.2;
	std::cout << "\nTableau 2: \n";
	for (int i=0; i<container2.getSize(); i++){
		std::cout << container2[i] << "|";
	};
	//parcours de l'arbre
	std::cout << "\nArbre 2: \n";
	BalancedArray<float>::Iterator it2;
	for (it2=container2.begin(); it2!=container2.end(); ++it2){
		std::cout << *it2 << "|";
	};
	std::cout << std::endl;
}
