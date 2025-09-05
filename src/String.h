#pragma once

class String {
    private:
        static const int MAX_SIZE = 255;
        char data[MAX_SIZE];

        int length; // Not including \0
    public:
        String(const char* s);
        String(const char c);
        String(const String& other);
        String();
        
        int getLength() const { return length; }

        String operator+(const String& right) const;
        String operator+(const char& right) const;
        String& operator+=(const String& right);
        String& operator+=(const char& right);
        void append(char newChar);

        char operator[](int index) const {return data[index]; }
        
        void erase(int start, int end);
        void erase(int index);
        
        String substr(int startIndex, int length); 
        void print(bool waitForInput = false);
};
