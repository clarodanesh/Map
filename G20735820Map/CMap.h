#pragma once
template <typename I, typename C>
class CMap {
	//insert
	//delete
	//isKeyUnique
public:
	CMap();
	int arrIdx;
	int sizeOfArray;
	struct MapElements {
		I key;
		I value;
	};
	MapElements *mapElements;
	void insert(I key, I value);
	void get(I key);
	void demo();
	void arrayBuilder(MapElements *arr, int size, int newSize);
	void remove(I key);
	void display();
};

template <typename I, typename C>
CMap<I, C>::CMap() {
	arrIdx = 0;
	mapElements = new MapElements[3];
	sizeOfArray = 0;
	//arrayBuilder(mapElements, 10, 10);
}

template <typename I, typename A>
void CMap<I, A>::arrayBuilder(MapElements *arr, int size, int newSize) {
	MapElements *tmp = new MapElements[newSize];

	for (int i = 0; i < newSize; i++)
	{
		if (i < size)
		{
			tmp[i].key = arr[i].key;
			tmp[i].value = arr[i].value;
		}
		else // if(i >= size && i < newSize) //Wait a sec, this "if" is superfluous. It's conditions are enforced the the first if and the loop condition.
		{
			tmp[i].key = 10;
			tmp[i].value = 2.0f;
		}
	}

	mapElements = tmp;
}

template <typename I, typename C>
void CMap<I, C>::insert(I key, I value) {
	for (int i = 0; i < sizeOfArray; i++) {
		if(mapElements[i].key == key){
			mapElements[i].value = value;
			return;
		}
	}
	mapElements[arrIdx].key = key;
	mapElements[arrIdx].value = value;
	sizeOfArray = sizeOfArray + 1;
	arrIdx++;
}

template <typename I, typename C>
void CMap<I, C>::get(I key) {
	for (int i = 0; i<sizeof(mapElements) / sizeof(mapElements[0]); i++)
		if (mapElements[i].key == key)
			cout << "CALLED GET" <<  mapElements[i].value << endl;
}

template <typename I, typename A>
void CMap<I, A>::remove(I key) {
	MapElements *tmp = new MapElements[sizeOfArray - 1];

	for (int i = 0; i < sizeOfArray; i++)
	{
		if (key != mapElements[i].key)
		{
			tmp[i].key = mapElements[i].key;
			tmp[i].value = mapElements[i].value;
		}
	}
	sizeOfArray = sizeOfArray - 1;
	mapElements = tmp;
}

template<typename I, typename C>
void CMap<I, C>::demo() {
	CMap<int, float>* i = new CMap<int, float>();
	i->insert(1, 1);
	i->insert(3, 4);
	//i->get("toby");
	//i->insert(5, 6);
	//i->get(3);

	arrayBuilder(mapElements, 3, 4);
}

template<typename I, typename C>
void CMap<I, C>::display() {
	for (int i = 0; i < sizeOfArray; i++) {
		cout << mapElements[i].key << "  ";
		cout << mapElements[i].value;
		cout << endl << endl;
	}
}



