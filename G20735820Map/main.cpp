#include <iostream>
#include "CMap.h"
#include <string>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

using namespace std;

int main() {

	cout << "G20735820 Map Class Assignment" << endl << endl << endl;

	//Map demonstrating int and float

	cout << "//////////////////////////////////////////////////////////////////////////////////" << endl;
	cout << "                         Demonstrating int and float Map                          " << endl;
	cout << "//////////////////////////////////////////////////////////////////////////////////" << endl;

	//creating a pointer then requesting memory to hold a CMap class with int float as types
	CMap<int, float>* ifMap = new CMap<int, float>();

	//demonstrating insert into map
	ifMap->insert(10, 1.1f);

	ifMap->display();

	//demonstrating map allows only unique keys
	ifMap->insert(10, 2.1f);

	ifMap->display();

	//demonstrating dynamic size of map (Map is initialised with size of 5 then map size is dynamic)
	ifMap->insert(20, 2.2f);
	ifMap->insert(30, 3.3f);
	ifMap->insert(40, 4.4f);
	ifMap->insert(50, 5.5f);
	ifMap->insert(60, 6.6f);
	ifMap->insert(70, 7.7f);
	ifMap->insert(80, 8.8f);
	ifMap->insert(90, 9.9f);

	ifMap->display();

	//demonstrating remove function
	ifMap->remove(60);
	//this remove function should not work as key 900 should not exist in the map
	ifMap->remove(900);
	ifMap->remove(30);

	ifMap->display();

	//demonstrating get function which displays the value held at this key 
	ifMap->get(70);

	//demonstrating size function, returns amount of elements in current map
	ifMap->size();

	//demonstrating get keys which will display all keys to console in current map
	ifMap->getkeys();

	//checks if map is empty then displays this to screen
	ifMap->isEmpty();

	delete ifMap;

	cout << "//////////////////////////////////////////////////////////////////////////////////" << endl << endl;

	//Map demonstrating string and char

	cout << "//////////////////////////////////////////////////////////////////////////////////" << endl;
	cout << "                         Demonstrating string and char Map                        " << endl;
	cout << "//////////////////////////////////////////////////////////////////////////////////" << endl;

	CMap<string, char>* scMap = new CMap<string, char>();

	scMap->insert("apple", 'a');

	scMap->display();

	scMap->insert("apple", 'b');

	scMap->display();

	scMap->insert("banana", 'b');
	scMap->insert("carrot", 'c');
	scMap->insert("dragonfruit", 'd');
	scMap->insert("elderberry", 'e');
	scMap->insert("Fennel", 'f');
	scMap->insert("grape", 'g');
	scMap->insert("honeydew", 'h');
	scMap->insert("iceberg", 'i');

	scMap->display();

	scMap->remove("dragonfruit");
	scMap->remove("garlic");
	scMap->remove("honeydew");

	scMap->display();

	scMap->get("elderberry");

	scMap->size();

	scMap->getkeys();

	scMap->isEmpty();

	delete scMap;

	cout << "//////////////////////////////////////////////////////////////////////////////////" << endl << endl;

	//map demonstrating float and string

	cout << "//////////////////////////////////////////////////////////////////////////////////" << endl;
	cout << "                         Demonstrating float and string Map                        " << endl;
	cout << "//////////////////////////////////////////////////////////////////////////////////" << endl;

	CMap<float, string>* fsMap = new CMap<float, string>();

	fsMap->insert(1.1f, "hello");

	fsMap->display();

	fsMap->insert(1.1f, "test");

	fsMap->display();

	fsMap->insert(2.3f, "yes");
	fsMap->insert(3.4f, "testing");
	fsMap->insert(4.3f, "could");
	fsMap->insert(5.4f, "should");
	fsMap->insert(6.5f, "would");
	fsMap->insert(7.6f, "always");
	fsMap->insert(8.1f, "never");
	fsMap->insert(9.5f, "very");

	fsMap->display();

	fsMap->remove(3.4f);
	fsMap->remove(35.2f);
	fsMap->remove(7.6f);

	fsMap->display();

	fsMap->get(6.5f);

	fsMap->size();

	fsMap->getkeys();

	fsMap->isEmpty();

	delete fsMap;

	cout << "//////////////////////////////////////////////////////////////////////////////////" << endl << endl;

	//map demonstrating char and int

	cout << "//////////////////////////////////////////////////////////////////////////////////" << endl;
	cout << "                         Demonstrating char and int Map                        " << endl;
	cout << "//////////////////////////////////////////////////////////////////////////////////" << endl;

	CMap<char, int>* ciMap = new CMap<char, int>();

	ciMap->insert('a', 1);

	ciMap->display();

	ciMap->insert('a', 2);

	ciMap->display();

	ciMap->insert('b', 3);
	ciMap->insert('c', 4);
	ciMap->insert('d', 5);
	ciMap->insert('e', 6);
	ciMap->insert('f', 7);
	ciMap->insert('g', 8);
	ciMap->insert('h', 9);
	ciMap->insert('i', 10);

	ciMap->display();

	ciMap->remove('d');
	ciMap->remove('q');
	ciMap->remove('h');

	ciMap->display();

	ciMap->get('f');

	ciMap->size();

	ciMap->getkeys();

	ciMap->isEmpty();

	delete ciMap;

	cout << "//////////////////////////////////////////////////////////////////////////////////" << endl << endl;

	cout << "Memory Leaks: " << _CrtDumpMemoryLeaks() << endl << endl;

	system("pause");
}