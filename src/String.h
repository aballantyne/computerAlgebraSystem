#pragma once

class String {
    private:
        static const int MAX_SIZE = 100;
        char data[MAX_SIZE];

        int length; // Not including \0
    public:
        String(const char* s);
        String(const char c);
        String(int i);
        String(const String& other);
        String& operator=(const String& right); 
        String();
        
        int getLength() const { return length; }

        String operator+(const String& right) const;
        String operator+(const char& right) const;
        String& operator+=(const String& right);
        String& operator+=(const char& right);
        void append(char newChar);
        void insert(int index, char newChar); 

        char operator[](int index) const {return data[index]; }
        bool operator==(const String& right) const; 
        bool operator==(const char* s) const { return (*this) == String(s); }
        bool operator!=(const String& right) const { return !((*this) == right); }
        bool operator!=(const char* s) const { return !((*this) == s); }

        void erase(int start, int end);
        void erase(int index);
        
        String substr(int startIndex, int length); 
        void print(bool waitForInput = false, bool newLine = true);
};
