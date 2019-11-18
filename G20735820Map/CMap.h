#pragma once
template <typename AnyType, typename U>
class CMap {
	//insert
	//delete
	//isKeyUnique
public:
	void insert(AnyType key, U value);
};

template <typename AnyType, typename U>
void CMap<AnyType, U>::insert(AnyType key, U value) {
	cout << key << endl;
	cout << value << endl;
}