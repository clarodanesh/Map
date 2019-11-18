#include <iostream>
#include "CMap.h"

using namespace std;


int main() {

	CMap<int, char>* i = new CMap<int, char>();
	i->insert(2, 'C');

	system("pause");
}