#pragma once 
#include <initializer_list>

template <class ItemClass>
class vector{   
    private:
        ItemClass* data; 
        
        int numberOfItems = 0; 
        int itemsAlocated = 0;

        void allocateMemory(); 
    public:
        void push_back(ItemClass newItem); 

        ItemClass& operator[](int index) const;
        vector<ItemClass> operator+( const vector<ItemClass>& right) const;
        vector<ItemClass>& operator=(const vector<ItemClass>& right);

        void erase(int index); 
        void insert(int index, ItemClass item);


        int size() const;
        vector();
        vector(std::initializer_list<ItemClass> list);
        vector(const vector<ItemClass> &other); 

        ~vector();
}; 