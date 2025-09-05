#include "vector.h"
#include "string.h"
#include <assert.h>

// -------------------- Size --------------------
template <class ItemClass>
int vector<ItemClass>::size() const { 
    return numberOfItems; 
}

// -------------------- Memory management --------------------
template <class ItemClass>
void vector<ItemClass>::allocateMemory() {
    itemsAlocated = (itemsAlocated == 0) ? 1 : itemsAlocated * 2;

    ItemClass* newData = new ItemClass[itemsAlocated]; 
    for (int i = 0; i < numberOfItems; i++) {
        newData[i] = data[i];
    }
    if (data) delete[] data;
    data = newData; 
}

// -------------------- Element access --------------------
template <class ItemClass>
ItemClass& vector<ItemClass>::operator[](int index) const {
    assert(index >= 0 && index < numberOfItems);
    return data[index];
}

// -------------------- Modifiers --------------------
template <class ItemClass>
void vector<ItemClass>::push_back(ItemClass newItem) {
    if (numberOfItems == itemsAlocated) {
        allocateMemory();
    }
    data[numberOfItems++] = newItem;
}

template <class ItemClass>
void vector<ItemClass>::erase(int index) {
    assert(index >= 0 && index < numberOfItems);
    for (int i = index + 1; i < numberOfItems; i++) {
        data[i - 1] = data[i]; 
    }
    numberOfItems--;
}

template <class ItemClass>
void vector<ItemClass>::insert(int index, ItemClass item) {
    assert(index >= 0 && index <= numberOfItems);
    if (numberOfItems == itemsAlocated) {
        allocateMemory();
    } 
    for (int i = numberOfItems - 1; i >= index; i--) {
        data[i + 1] = data[i];
    }
    data[index] = item;
    numberOfItems++;
}

// -------------------- Operators --------------------
template <class ItemClass>
vector<ItemClass> vector<ItemClass>::operator+(const vector<ItemClass>& right) const {
    vector<ItemClass> newVector = *this;
    for (int i = 0; i < right.size(); i++) {
        newVector.push_back(right[i]);
    }
    return newVector; 
}

template <class ItemClass>
vector<ItemClass>& vector<ItemClass>::operator=(const vector<ItemClass>& right) {
    if (this == &right) return *this; // self-assignment guard

    if (data) delete[] data;

    numberOfItems = right.numberOfItems;
    itemsAlocated = right.itemsAlocated;
    data = new ItemClass[itemsAlocated];
    for (int i = 0; i < numberOfItems; i++) {
        data[i] = right.data[i];
    }

    return *this;
}

// -------------------- Constructors --------------------
template <class ItemClass>
vector<ItemClass>::vector() : data(nullptr), numberOfItems(0), itemsAlocated(0) {}

template <class ItemClass>
vector<ItemClass>::vector(std::initializer_list<ItemClass> list) : data(nullptr), numberOfItems(0), itemsAlocated(0) {
    for (const auto& item : list) {
        push_back(item);
    }
}

template <class ItemClass>
vector<ItemClass>::vector(const vector<ItemClass>& other) {
    numberOfItems = other.numberOfItems;
    itemsAlocated = other.itemsAlocated;
    data = new ItemClass[itemsAlocated];
    for (int i = 0; i < numberOfItems; i++) {
        data[i] = other.data[i];
    }
}

// -------------------- Destructor --------------------
template <class ItemClass>
vector<ItemClass>::~vector() {
    if (data) delete[] data;
}

// -------------------- Explicit template instantiation --------------------
template class vector<char>;
template class vector<int>;
template class vector<string>;