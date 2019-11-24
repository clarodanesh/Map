#include <iostream>
#include "CMap.h"

using namespace std;

template<class I, class O>
O check(I firster, I laster, O resulter)
{
	while (firster != laster) {
		*resulter = *firster;
		++resulter; ++firster;
	}
	return resulter;
}

template <typename j>
struct mapEl{
	j key;
	j val;
};

template<typename ft, typename st>
class aElement {
public:
	ft key;
	st value;

	aElement(ft aKey, st aValue) {
		key = aKey;
		value = aValue;
		cout << key;
		cout << value;
	}
};

void hello() {
	cout << "hello" << endl;
}


int main() {
	/*CMap<string>* i = new CMap<string>();
	i->insert("danesh", "iqbal");
	i->insert("optic", "fibre");
	i->get("optic");
	i->insert("optic", "yes");
	i->get("optic");*/

	/*int newsize = 10;
	int *myints = new int[1];

	myints[0] = 2;

	int *newarray = new int[newsize];
	check(myints, myints + 1, newarray);
	delete[] myints;
	myints = newarray;

	for (int i = 0; i < 12; i++) {
		myints[i] = i;
		int p = *(myints + i);
	}

	for (int i = 0; i < 12; i++) {
		int c = *(myints + i);
			cout << c << ", ";
	}*/
	//cout << *myints;

	//Element<key<int>, value<char>> * newEl;

	/*CArray<Element<int, char>> * arr;

	auto * check = new Element<int, int>(10, 10);

	cout << endl << endl;
	cout << check->key;*/

	/*CMap<int>* i = new CMap<int>();
	i->insert(1, 1);
	i->insert(2, 2);
	i->get(1);
	i->insert(3, 3);

	for (int a = 0; a < 10; a++) {
		i->insert(a, 15);
	}*/

	/*CMap<string>* i = new CMap<string>();
	i->insert("danesh", "iqbal");
	i->insert("toby", "maguire");
	i->get("toby");
	i->insert("cristiano", "ronaldo");*/

	/*CMap<char>* i = new CMap<char>();
	i->insert('a', 'b');
	i->insert('c', 'd');
	i->get('a');
	i->insert('e', 'f');*/

	/*CMap<float>* i = new CMap<float>();
	i->insert(1.0f, 1.5f);
	i->insert(2.0f, 2.5f);
	i->get(1.0f);
	i->insert(3.0f, 3.5f);*/
	
	/*CMap<bool>* i = new CMap<bool>();
	i->insert(true, false);
	i->get(true);*/

	/*CMap<double>* i = new CMap<double>();
	i->insert(1.0f, 1.5f);
	i->insert(2.0f, 2.5f);
	i->get(1.0f);
	i->insert(3.0f, 3.5f);*/
	
	CMap<int, float>* i = new CMap<int, float>();
	i->insert(1, 1);
	i->insert(3, 4);
	//i->get("toby");
	i->insert(5, 6);
	//i->get(3);

	//i->demo();

	i->display();

	i->remove(3);

	i->display();

	i->remove(1);

	i->display();

	i->insert(20, 6);

	i->insert(8, 19);

	i->display();

	i->insert(135, 20);

	i->insert(27, 8);

	i->insert(270, 19);

	i->insert(271, 19);

	i->display();

	i->remove(135);

	i->insert(500, 2.0f);

	i->remove(270);

	i->display();

	i->insert(500, 500);

	i->display();

	delete i;

	CMap<int, char>* a = new CMap<int, char>();

	a->display();

	a->insert(500, 'y');

	a->display();

	/*i = new CMap<char, int>();

	CMap<char, int>* a = new CMap<char, int>();
	a->insert(2, 3);
	a->get(2);*/

	/*for (int a = 0; a < 10; a++) {
		i->insert(a, 15);
	}*/
	

	//create a array class 
		//this class handles everything to do with the array
		//access by arr.arr[0]
		//create that as template and its data type is the element we pass into it

	system("pause");
}