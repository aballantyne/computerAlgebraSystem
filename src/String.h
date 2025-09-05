#pragma once

class String {
    private:
        static const int MAX_SIZE = 255;
        char data[MAX_SIZE];

        int length; // Not including \0
    public:
        String(char* s);
        String(char c);
        String(const String& other);
        String();
        
        int getLength() const { return length; }

        String operator+(const String& right) const;
        String operator+(const char& right) const;
        String& operator+=(const String& right);
        String& operator+=(const char& right);
        void append(char newChar);

        char operator[](int index) const {return data[index]; }

        void print();
};
