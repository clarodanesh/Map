#include <iostream>
#include <string>
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

	CMap<int>* i = new CMap<int>();
	i->insert(1, 1);
	i->insert(2, 2);
	i->get(1);
	i->insert(3, 3);

	for (int a = 0; a < 10; a++) {
		i->insert(a, 15);
	}
	

	//create a array class 
		//this class handles everything to do with the array
		//access by arr.arr[0]
		//create that as template and its data type is the element we pass into it

	system("pause");
}