#include <iostream>
#include <cstring>

using namespace std;

class String 
{
private:
    char* str;
    int size;

public:
    String() {
        size = 80;
        str = new char[size + 1];
        str[0] = '\0';
    }

    String(int length) {
        size = length;
        str = new char[size + 1];
        str[0] = '\0';
    }

    String(const char* input) {
        size = strlen(input);
        str = new char[size + 1];
        for (int i = 0; i <= size; ++i) {
            str[i] = input[i];
        }
    }

    String(const String& other) {
        size = other.size;
        str = new char[size + 1];
        for (int i = 0; i <= size; ++i) {
            str[i] = other.str[i];
        }
    }

    ~String() {
        delete[] str;
    }

    void assign(const String& other) {
        if (this == &other) return;
        delete[] str;
        size = other.size;
        str = new char[size + 1];
        for (int i = 0; i <= size; ++i) {
            str[i] = other.str[i];
        }
    }

    void input() {
        cout << "Enter string: ";
        cin.getline(this->str, size);
    }

    void output() const {
        cout << str << endl;
    }

    int length() const {
        return size;
    }

    bool empty() const {
        return size == 0 || str[0] == '\0';
    }

    String concatenate(const String& other) const {
        int newSize = this->size + other.size;
        char* newStr = new char[newSize + 1];
        for (int i = 0; i < this->size; ++i) {
            newStr[i] = this->str[i];
        }
        for (int i = 0; i <= other.size; ++i) {
            newStr[this->size + i] = other.str[i];
        }
        String result(newStr);
        delete[] newStr;
        return result;
    }
};


