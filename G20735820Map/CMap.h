#pragma once
//Map class implemented as a template class to allow multiple types
//KT means key type
//VT means value type
template <typename KT, typename VT>
class CMap {
public:
	//constructor for map class
	CMap();
	//arrayIndex holds the value of the index when inserting or removing
	int arrayIndex;
	//the size of the mapElements array measured in amount of elements
	int arraySizeInElements;
	//the size of the mapElements array in total capacity
	int arrayCapacity;
	//struct which makes up the key value pair
	struct MapElements {
		KT key;
		VT value;
	};
	//need an array of key value pairs which essentially makes the map
	MapElements *mapElements;
	//need a temporary array to perform manipulations such as increase and decrease size
	MapElements *tempArray;
	//insert key value pair
	void insert(KT key, VT value);
	//get value held with key passed as parameter
	void get(KT key);
	//check if key already exists
	bool keyExists(KT key);
	//increase the size of the map
	void IncreaseMapSize(MapElements *currArr, int size, int newSize);
	//decrease the size of the map
	void DecreaseMapSize(MapElements *currArr, int size, int newSize, KT key);
	//remove a key value pair from the map using key passed as parameter
	void remove(KT key);
	//check if the map is full
	bool isFull();
	//return the size of the map in elements
	int size();
	//check if the map is empty
	bool isEmpty();
	//display all key value pairs held in the map
	void display();
	//get all the keys held in the map
	void getkeys();
	//destructor for map class
	~CMap();
};

//constructor will initialise the array which will hold the key value pairs
template <typename KT, typename VT>
CMap<KT, VT>::CMap() {
	//array index should be 0 as we start from the 1st element of array
	arrayIndex = 0;
	//start with 5 empty elements
	mapElements = new MapElements[5];
	//set the total capacity to 5
	arrayCapacity = 5;
	//array holds nothing so set element size to 0
	arraySizeInElements = 0;

	cout << "Constructing Map of Size 5" << endl;
}

//destructor will clean up memory for map class when called
template<typename KT, typename VT>
CMap<KT, VT>::~CMap() {
	//need to delete the mapElements array
	delete[]mapElements;
}

//function used to increase the size of the map using the old array, old size and a new size
template <typename KT, typename VT>
void CMap<KT, VT>::IncreaseMapSize(MapElements *currArr, int size, int newSize) {
	//if the total capacity is 1 then the newSize needs to be reduced by 1
	if (arrayCapacity == 1) {
		newSize = newSize - 1;
	}

	//temporary array should be initialised with the newSize
	tempArray = new MapElements[newSize];

	//need to enter the previous arrays elements into the new array
	for (int i = 0; i < newSize; i++)
	{
		if (i < size)
		{
			tempArray[i].key = currArr[i].key;
			tempArray[i].value = currArr[i].value;
		}
	}

	//set the total capacity of the array to what the newsize is
	arrayCapacity = newSize;

	//need to set the mapElements array to the tempArray so that we can use this class wide
	mapElements = tempArray;

	//wont need the current array until the next time I increase the map size so should delete it to stop memory leaks
	delete[] currArr;
}

//function used to decrease the size of the map using the old array, old size and a new size, and a key
template <typename KT, typename VT>
void CMap<KT, VT>::DecreaseMapSize(MapElements *currArr, int size, int newSize, KT key) {
	//newSize should never be negative however Im checking jsut in case
	//the array should always have a capacity to hold atleast 1 element and so if the capacity (newSize goes to 0) then need to make sure its atleast 1
	if (newSize <= 0) {
		newSize = newSize + 1;
	}

	//set temp array to newSize value by requesting some memory
	tempArray = new MapElements[newSize];

	//position variable used to map elements in array at 1 lower value than the previous array as elements are being removed
	int pos = 0;

	for (int i = 0; i < size; i++)
	{
		//if the key is not equal to the key to remove then shift the element and add it to temp array
		//else skip the value that is this key and decrease the position
		if (key != currArr[i].key)
		{
			tempArray[pos].key = currArr[i].key;
			tempArray[pos].value = currArr[i].value;
			pos++;
		}
		else {
			pos++;
			pos = pos - 1;
		}
	}

	//set the mapElements array to the newly constructed array so that it can be used class wide
	mapElements = tempArray;

	//Cleaning up the memory for the current array which wont be used again until map size is decreased again
	delete[] currArr;
}


//function used to insert key value pair into the map
template <typename KT, typename VT>
void CMap<KT, VT>::insert(KT key, VT value) {
	
	//right from the start need to check if the key already exists in the map, if so then just replace it and return out of the function
	for (int i = 0; i < arraySizeInElements; i++) {
		if (mapElements[i].key == key) {
			cout << "Key: " << key << " already exists, replacing the Value with " << value << endl << endl;
			mapElements[i].value = value;
			return;
		}
	}

	//everytime insert is called need to check if map is full, if it is then need to increase the map size
	if (isFull()) {
		IncreaseMapSize(mapElements, arraySizeInElements, arrayCapacity + 5);
	}

	//now since something is inserted need to increase map element size counter by 1
	arraySizeInElements = arraySizeInElements + 1;
	//insert the key and value into the elements array
	mapElements[arrayIndex].key = key;
	mapElements[arrayIndex].value = value;

	//need to increase the index by 1 as next time insert is called the key value pair should be inserted into the next element
	arrayIndex++;
}

//function which gets the value held with the key passed as a parameter
template <typename KT, typename VT>
void CMap<KT, VT>::get(KT key) {
	//before inserting should check if the key exists in the map as if it doesnt then no point looping over the array
	if (keyExists(key)) {
		for (int i = 0; i < arraySizeInElements; i++) {
			//if the key is found then output that it is found
			if (mapElements[i].key == key) {
				cout << "Key: " << key << " obtained Value: " << mapElements[i].value << endl << endl;
			}
		}
	}
}

//function which removes the key and value pair held with the key passed as a parameter
template <typename KT, typename VT>
void CMap<KT, VT>::remove(KT key) {
	//should check if the map is empty before attempting remove as cant remove something from an empty map
	if (!isEmpty()) {
		//if the map wasnt empty now need to check if the key even exists in the map as cant remove a key which doesnt exist
		if (keyExists(key)) {

			//if map wasnt empty and key did exist then decrease the size of the array and remove the key value pair with the key passed here
			DecreaseMapSize(mapElements, arraySizeInElements, arrayCapacity - 1, key);

			cout << "removing key value pair held with Key: " << key << endl << endl;

			//array capacity should now be reduced
			arrayCapacity = arrayCapacity - 1;

			//elements should be reduced
			arraySizeInElements = arraySizeInElements - 1;

			//the index of the value should be reduced as there is 1 less element now
			arrayIndex = arrayIndex - 1;
		}
		else {
			cout << "Key " << key << " does not exist in the Map" << endl << endl;
		}
	}
	else {
		cout << "since the map is empty remove cannot be performed" << endl << endl;
	}
}

//display function will output the entire map of key value pairs to the console
template<typename KT, typename VT>
void CMap<KT, VT>::display() {
	cout << "List of all the Key AND Values in the map" << endl;
	for (int i = 0; i < arraySizeInElements; i++) {
		cout << mapElements[i].key << "  ";
		cout << mapElements[i].value;
		cout << endl << endl;
	}
}

//function to check whether the map is full or not
template<typename KT, typename VT>
bool CMap<KT, VT>::isFull() {
	//if there is 1 or more elements in the array then check if the map is full otherwise by definition if there is 0 then it cant be full
	if (arraySizeInElements > 0) {
		for (int i = 0; i < arrayCapacity; i++) {
			//if the amount of elements are less than the entire capacity of the array then it cant be full so return false
			if (arraySizeInElements < arrayCapacity) {
				return false;
			}
		}
		return true;
	}
	else {
		return false;
	}
}

//this function will check if the map is empty and return true or false accordingly
template<typename KT, typename VT>
bool CMap<KT, VT>::isEmpty() {
	//if the map is size 0 in elements then it is empty otherwise its not
	if (arraySizeInElements == 0) {
		cout << "map empty" << endl << endl;
		return true;
	}
	else {
		cout << "map not empty" << endl << endl;
		return false;
	}
}

//this function will check if the key exists in the map 
template<typename KT, typename VT>
bool CMap<KT, VT>::keyExists(KT key) {
	//key can only exist if map has 1 or more elements so only do check if that is satisfied
	if (arraySizeInElements > 0) {
		for (int i = 0; i < arraySizeInElements; i++) {
			//if the key has been found in the map then return true
			if (mapElements[i].key == key) {
				cout << "key: " << key << " exists" << endl << endl;
				return true;
			}
		}
		cout << "key does not exist" << endl << endl;
		return false;
	}
	else {
		return false;
	}
}

//this function will get the size of the array, the size will be how many elements are in the map
template<typename KT, typename VT>
int CMap<KT, VT>::size() {
	cout << "The current size of the Map is " << arraySizeInElements << endl << endl;
	return arraySizeInElements;
}

//this function will display all of the keys that are in the map
template<typename KT, typename VT>
void CMap<KT, VT>::getkeys() {
	cout << "List of keys in the map:" << endl;
	for (int i = 0; i < arraySizeInElements; i++) {
		cout << mapElements[i].key << endl << endl;
	}
}