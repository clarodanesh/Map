#pragma once
template <typename I>
class CMap {
	//insert
	//delete
	//isKeyUnique
public:
	CMap();
	int arrIdx;
	struct MapElements {
		I key;
		I value;
	};
	MapElements mapElements[10];
	void insert(I key, I value);
	void get(I key);
};

template <typename I>
CMap<I>::CMap() {
	arrIdx = 0;
}

template <typename I>
void CMap<I>::insert(I key, I value) {
	for (int i = 0; i < sizeof(mapElements) / sizeof(mapElements[0]); i++) {
		if(mapElements[i].key == key){
			mapElements[i].value = value;
			return;
		}
	}
	mapElements[arrIdx].key = key;
	mapElements[arrIdx].value = value;
	arrIdx++;
}

template <typename I>
void CMap<I>::get(I key) {
	for (int i = 0; i<sizeof(mapElements) / sizeof(mapElements[0]); i++)
		if (mapElements[i].key == key)
			cout << mapElements[i].value;
}

