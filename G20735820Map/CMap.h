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
	~CMap();
};

template <typename I, typename C>
CMap<I, C>::CMap() {
	arrIdx = 0;
	mapElements = new MapElements[10];
	for (int i = 0; i < 10; i++) {
		mapElements[i].key = NULL;
		mapElements[i].value = NULL;
	}
	sizeOfArrayAndNull = 10;
	sizeOfArray = 0;
	//arrayBuilder(mapElements, 10, 10);
	cout << "Constructing Map of Size 10 with Null elements" << endl;
}

template<typename I, typename C>
CMap<I, C>::~CMap() {
	delete[]mapElements;
}

template <typename I, typename C>
void CMap<I, C>::arrayBuilder(MapElements *arr, int size, int newSize) {
	tmp = new MapElements[newSize];

	for (int i = 0; i < newSize; i++)
	{
		if (i < size)
		{
			tmp[i].key = arr[i].key;
			tmp[i].value = arr[i].value;
		}
		else // if(i >= size && i < newSize) //Wait a sec, this "if" is superfluous. It's conditions are enforced the the first if and the loop condition.
		{
			tmp[i].key = NULL;
			tmp[i].value = NULL;
		}
	}
	sizeOfArrayAndNull = newSize;
	mapElements = tmp;


	//THIS ONE LINE FIXES THE MEMORY LEAK ISSUE
	delete[] arr;
}

template <typename I, typename C>
void CMap<I, C>::arraySmaller(MapElements *arr, int size, int newSize, I key) {
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
		arrayBuilder(mapElements, sizeOfArray, sizeOfArray + 10);
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

//WHEN DOING THE REMOVE, NOT ADDING NULL ELEMENTS BACK INTO THE ARRAY, NEED TO ADD NULL ELEMENTS BACK IN SO WE CAN DO NULL CHECKS FOR WHEN FULL  

//ARRAY WHEN REMOVING FROM FIRST TIME IS LEAVING A BROKEN ELEMENT INSIDE THE ARRAY, NEED TO REMOVE THAT ELEMENT TO HAVE A CHANCE
template <typename I, typename A>
void CMap<I, A>::remove(I key) {
	if (!isEmpty()) {
		if (keyExists(key)) {
			//check if the key exists before trying to remove
			arraySmaller(mapElements, sizeOfArray, sizeOfArray - 1, key);

			//AFTER DarECREMENTING THE SIZE OF THE ARRAY AND NULL VALUES
			//THE REST OF THE ARRAY NEEDS TO BE FILLED WITH NULL VALUES
			//DO THIS ONLY IF THE SIZE OF ARRAY AND NULL VALUES VARIABLE IS LESS THAN THE SIZE OF THE SIZE OF THE ARRAY VARIABLE
			//AS ONLY WANT TO ADD NULL VALUES IF THE SIZE OF THE ARRAY IS NOT FULL
			sizeOfArrayAndNull = sizeOfArrayAndNull - 1;
			sizeOfArray = sizeOfArray - 1;
			arrIdx = arrIdx - 1;
			//mapElements = tmp;
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
			if (mapElements[i].key == NULL) {
				return false;
			}
		}
		return true;
	}
	else {
		//cout << "hit outer false";
		return false;
	}
	//cout << "dont hit this";
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
		//cout << "hit outer false";
		return false;
	}
	//cout << "dont hit this";
}

template<typename I, typename C>
int CMap<I, C>::size() {
	cout << "current size of the Map is " << sizeOfArray << endl << endl;
	return sizeOfArray;
}