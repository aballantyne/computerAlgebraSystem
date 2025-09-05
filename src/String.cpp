#include "String.h"
#include <ti/screen.h>
#include <ti/getcsc.h>
#include <stdlib.h>
void String::append(char newChar){
    if (length >= MAX_SIZE -1){
        os_ClrHome();

        os_PutStrFull("Over max string size D:");
        exit(1); 
    }
    data[length] = newChar;
    data[length+1] = '\0';

    length++;
}

void String::print(){
    os_ClrHome();

    os_PutStrFull(data);
}

String::String(char *s){
    length = 0; 
    data[0] = '\0';

    int i = 0;
    while(s[i] != '\0'){
        append(s[i]);
        i++;
    }
}
String::String(const String &other){
    length = 0; 
    data[0] = '\0';

    int i = 0;
    while(other[i] != '\0'){
        append(other[i]);
        i++;
    }
}
String::String(){
    length = 0; 
    data[0] = '\0';
}
String String::operator+(const String &right) const {
    String output = *this;
    
    for(int i = 0; i < right.getLength(); i++){
        output += right[i];
    }
    return output; 
    
}
String String::operator+(const char &right) const
{
    String output = *this;
    output += right;

    return output;  
}
String& String::operator+=(const String &right) 
{
    for(int i = 0; i < right.getLength(); i++){
        append(right[i]); 
    }
    return *this; 
}
String& String::operator+=(const char &right)
{
    append(right);
    return *this;  
}
String::String(char c)
{
    length = 0; 
    append(c);
}
