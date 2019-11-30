#include <iostream>
#include "CMap.h"
#include <string>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

using namespace std;

int main() {

	cout << "G20735820 Map Class Assignment" << endl << endl << endl;

	/*CMap<int, float>* i = new CMap<int, float>();
	i->insert(1, 1);
	i->insert(2, 2);
	i->insert(3, 3);
	i->insert(20, 6);
	i->insert(8, 19);
	i->insert(135, 20);
	i->insert(27, 8);
	i->insert(270, 19);
	i->insert(271, 19);
	i->insert(500, 2.0f);
	i->insert(100, 1);
	i->insert(200, 2);
	i->insert(300, 3);
	i->insert(400, 6);
	i->insert(600, 19);
	i->insert(700, 20);
	i->insert(800, 8);
	i->insert(900, 19);
	i->insert(1000, 19);
	i->insert(1100, 2.0f);

	for (int c = 0; c < 150; c++) {
		i->insert(c, 3);
	}





	i->remove(1100);

	i->getkeys();

	for (int c = 0; c < 300; c++) {
		i->remove(c);
	}

	i->insert(1, 1);
	i->insert(2, 2);
	i->insert(3, 3);
	i->insert(20, 6);
	i->insert(8, 19);
	i->insert(135, 20);
	i->insert(27, 8);
	i->insert(270, 19);
	i->insert(271, 19);
	i->insert(500, 2.0f);
	i->insert(100, 1);
	i->insert(200, 2);
	i->insert(300, 3);
	i->insert(400, 6);
	i->insert(600, 19);
	i->insert(700, 20);
	i->insert(800, 8);
	i->insert(900, 19);
	i->insert(1000, 19);
	i->insert(1100, 2.0f);

	cout << "size is" << endl;
	i->size();

	i->display();

	i->display();
	
	i->size();
	
	i->get(555324237);

	delete i;

	CMap<float, string>* a = new CMap<float, string>();
	
	a->insert(1.25, "hello");
	a->insert(2.25, "hello");
	a->insert(3.25, "hello");
	a->insert(4.25, "hello");
	a->insert(5.25, "hello");
	a->insert(6.25, "hello");
	a->insert(7.25, "hello");
	a->insert(8.25, "hello");
	a->insert(9.25, "hello");
	a->insert(10.25, "hello");
	a->insert(15.25, "hello");
	a->insert(92.25, "hello");
	a->insert(101.25, "hello");
	
	a->remove(1.25);
	a->remove(2.25);
	a->remove(3.25);
	a->remove(4.25);
	a->remove(5.25);
	a->remove(6.25);
	a->remove(7.25);
	a->remove(8.25);
	a->remove(9.25);
	a->remove(10.25);


	a->insert(1.25, "hello");
	a->insert(2.25, "hello");
	a->insert(3.25, "hello");
	a->insert(4.25, "hello");
	a->insert(5.25, "hello");
	a->insert(6.25, "hello");
	a->insert(7.25, "hello");
	a->insert(8.25, "hello");
	a->insert(9.25, "hello");
	a->insert(10.25, "hello");

	a->remove(1.25);
	a->remove(2.25);
	a->remove(3.25);
	a->remove(4.25);
	a->remove(5.25);
	a->remove(6.25);
	a->remove(7.25);
	a->remove(8.25);
	a->remove(9.25);
	a->remove(10.25);

	a->insert(1.25, "hello");
	a->insert(2.25, "hello");
	a->insert(3.25, "hello");
	a->insert(4.25, "hello");
	a->insert(5.25, "hello");
	a->insert(6.25, "hello");
	a->insert(7.25, "hello");
	a->insert(8.25, "hello");
	a->insert(9.25, "hello");
	a->insert(10.25, "hello");

	a->remove(6.25);
	a->remove(7.25);
	a->remove(8.25);
	a->remove(9.25);
	a->remove(10.25);

	//a->insert(3, "yes");
	a->get(10.25);
	a->insert(1, "yeah");
	a->get(1);	
	a->size();
	a->display();


	delete a;
	*/

	CMap<char, float>* q = new CMap<char, float>();

	q->remove('c');

	q->insert('c', 2.5f);

	q->remove('c');

	q->insert('a', 1.0f);
	q->insert('b', 1.0f);
	q->insert('c', 1.0f);
	q->insert('d', 1.0f);
	q->insert('e', 1.0f);
	q->insert('f', 1.0f);
	q->insert('g', 1.0f);
	q->insert('h', 1.0f);
	q->insert('i', 1.0f);
	q->insert('j', 1.0f);

	q->size();

	q->display();

	delete q;

	cout << "memory leak " << _CrtDumpMemoryLeaks();

	system("pause");
}