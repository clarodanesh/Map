#pragma once
template <typename I, typename C>
class CMap {
public:
	CMap();
	int arrIdx;
	int sizeOfArray;
	int sizeOfArrayAndNull;
	struct MapElements {
		I key;
		C value;
	};
	MapElements *mapElements;
	MapElements *tmp;
	void insert(I key, C value);
	void get(I key);
	bool keyExists(I key);
	void arrayBuilder(MapElements *arr, int size, int newSize);
	void arraySmaller(MapElements *arr, int size, int newSize, I key);
	void remove(I key);
	bool isFull();
	int size();
	bool isEmpty();
	void display();
	void getkeys();
	~CMap();
};

template <typename I, typename C>
CMap<I, C>::CMap() {
	arrIdx = 0;
	mapElements = new MapElements[5];
	sizeOfArrayAndNull = 5;
	sizeOfArray = 0;
	cout << "Constructing Map of Size 5" << endl;
}

template<typename I, typename C>
CMap<I, C>::~CMap() {
	delete[]mapElements;
}

template <typename I, typename C>
void CMap<I, C>::arrayBuilder(MapElements *arr, int size, int newSize) {
	if (sizeOfArrayAndNull == 1) {
		newSize = newSize - 1;
	}
	tmp = new MapElements[newSize];

	for (int i = 0; i < newSize; i++)
	{
		if (i < size)
		{
			tmp[i].key = arr[i].key;
			tmp[i].value = arr[i].value;
		}
	}
	sizeOfArrayAndNull = newSize;
	mapElements = tmp;


	//THIS ONE LINE FIXES THE MEMORY LEAK ISSUE
	delete[] arr;
}

template <typename I, typename C>
void CMap<I, C>::arraySmaller(MapElements *arr, int size, int newSize, I key) {
	if (newSize <= 0) {
		newSize = newSize + 1;
	}
	tmp = new MapElements[newSize];
	int pos = 0;

	for (int i = 0; i < size; i++)
	{
		if (key != arr[i].key)
		{
			tmp[pos].key = arr[i].key;
			tmp[pos].value = arr[i].value;
			pos++;
		}
		else {
			//JUST ENTERED THIS AND CHECK IT
			cout << "removing (key: " << key << " with value " << arr[i].value << ")" << endl;
			pos++;
			pos = pos - 1;
		}
	}
	//sizeOfArrayAndNull = newSize;
	mapElements = tmp;


	//THIS ONE LINE FIXES THE MEMORY LEAK ISSUE
	delete[] arr;
}

template <typename I, typename C>
void CMap<I, C>::insert(I key, C value) {
	for (int i = 0; i < sizeOfArray; i++) {
		if (mapElements[i].key == key) {
			mapElements[i].value = value;
			cout << "Key " << key << " already exists, replacing the value with " << value << endl;
			return;
		}
	}
	if (isFull()) {
		arrayBuilder(mapElements, sizeOfArray, sizeOfArrayAndNull + 5);
		cout << "map is full" << endl;
	}
	sizeOfArray = sizeOfArray + 1;
	mapElements[arrIdx].key = key;
	mapElements[arrIdx].value = value;
	arrIdx++;
	cout << "inserting key " << key << " with value " << value << endl;
}

template <typename I, typename C>
void CMap<I, C>::get(I key) {
	if (keyExists(key)) {
		for (int i = 0; i < sizeOfArray; i++)
			if (mapElements[i].key == key)
				cout << "CALLED GET" << mapElements[i].value << endl;
	}
}

template <typename I, typename C>
void CMap<I, C>::remove(I key) {
	if (!isEmpty()) {
		if (keyExists(key)) {
			//check if the key exists before trying to remove
			arraySmaller(mapElements, sizeOfArray, sizeOfArrayAndNull - 1, key);

			//if (sizeOfArrayAndNull != 1) {
				sizeOfArrayAndNull = sizeOfArrayAndNull - 1;
			//}
			sizeOfArray = sizeOfArray - 1;
			arrIdx = arrIdx - 1;
		}
		else {
			cout << "Key " << key << " does not exist in the Map" << endl;
		}
	}
	else {
		cout << "map is empty cant remove any more" << endl;
	}
}

template<typename I, typename C>
void CMap<I, C>::display() {
	for (int i = 0; i < sizeOfArray; i++) {
		cout << mapElements[i].key << "  ";
		cout << mapElements[i].value;
		cout << endl << endl;
	}
	cout << "ended array" << endl << endl << endl;
}

template<typename I, typename C>
bool CMap<I, C>::isFull() {
	if (sizeOfArray > 0) {
		for (int i = 0; i < sizeOfArrayAndNull; i++) {
			if (sizeOfArray < sizeOfArrayAndNull) {
				cout << "is not full " << endl;
				return false;
			}
		}
		cout << "is full " << endl;
		return true;
	}
	else {
		return false;
	}
}

template<typename I, typename C>
bool CMap<I, C>::isEmpty() {
	if (sizeOfArray == 0) {
		return true;
	}
	else {
		return false;
	}
}

template<typename I, typename C>
bool CMap<I, C>::keyExists(I key) {
	if (sizeOfArray > 0) {
		for (int i = 0; i < sizeOfArray; i++) {
			if (mapElements[i].key == key) {
				return true;
			}
		}
		return false;
	}
	else {
		return false;
	}
}

template<typename I, typename C>
int CMap<I, C>::size() {
	cout << "The current size of the Map is " << sizeOfArray << endl << endl;
	return sizeOfArray;
}

template<typename I, typename C>
void CMap<I, C>::getkeys() {
	cout << "List of keys in the map:" << endl;
	for (int i = 0; i < sizeOfArray; i++) {
		cout << mapElements[i].key << endl;
	}
}