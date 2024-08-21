#include <iostream>

class MyString {
    private:
    char* string_content;
    int string_length;
    int memory_capacity;

    public:
    MyString();
    explicit MyString(int size);
    MyString(char c);
    MyString(const char *str);
    MyString(const MyString& str);
    ~MyString();

    void reserve(int size);

    int capacity() const;
    int length() const;

    void print() const;
    void println() const;

    MyString& assign(const MyString& str);
    MyString& assign(const char *str);
    
    char at(int i) const;

    MyString& insert(int loc, const MyString& str);
    MyString& insert(int loc, const char *str);
    MyString& insert(int loc, char c);
    MyString& erase(int loc, int num);
    int find(int st, const MyString& str) const;
    int find(int st, const char *str) const;
    int find(int st, char c) const;
    int compare(const MyString& str) const;

    bool operator==(MyString& str) const;
    char& operator[](const int index)const;
};

MyString::MyString() :string_length(10), memory_capacity(10) {
    string_content = new char[memory_capacity];
}

MyString::MyString(int size) {
    if(size < 1) size = 1;

    string_length = 0;
    memory_capacity = size;
    string_content = new char[memory_capacity];
}

MyString::MyString(char c) : string_length(1), memory_capacity(1) {
    string_content = new char[1];
    string_content[0] = c;
}

MyString::MyString(const char *str) {
    int len = 0;
    while(true) {
        if(str[len] == 0) break;
        len++;
    }

    string_length = len;
    memory_capacity = string_length;
    string_content = new char[memory_capacity];

    for(int i = 0; i < len; i++) {
        string_content[i] = str[i];
    }
}

MyString::MyString(const MyString& str) : string_length(str.string_length), memory_capacity(str.memory_capacity) {
    string_content = new char[memory_capacity];

    for(int i = 0; i < string_length; i++) {
        string_content[i] = str.string_content[i];
    }
}

MyString::~MyString() {
    delete[] string_content;
}

void MyString::reserve(int size) {
    if(size > memory_capacity || size > string_length/*down sizing*/) {
        char *temp = string_content;
        string_content = new char[size];
        memory_capacity = size;

        for(int i = 0; i < string_length; i++) {
            string_content[i] = temp[i];
        }
        delete[] temp;
    }
}

int MyString::capacity() const {
    return memory_capacity;
}

int MyString::length() const {
    return string_length;
}

void MyString::print() const {
    for(int i = 0; i < string_length; i++) {
        std::cout << string_content[i];
    }
}

void MyString::println() const {
    for(int i = 0; i < string_length; i++) {
        std::cout << string_content[i];
    }
    std::cout << std::endl;
}

MyString& MyString::assign(const MyString& str) {
    if(str.string_length > memory_capacity) {
        delete[] string_content;
        memory_capacity = str.string_length;
        string_content = new char[string_length];
    }
    string_length = str.string_length;

    for(int i = 0; i < str.string_length; i++) {
        string_content[i] = str.string_content[i];
    }

    return *this;
}

MyString& MyString::assign(const char *str) {
    int len = 0;
    while(true) {
        if(str[len] == 0) break;
        len++;
    }

    if(len > memory_capacity) {
        delete[] string_content;
        memory_capacity = len;
        string_content = new char[string_length];
    }
    string_length = len;

    for(int i = 0; i < len; i++) {
        string_content[i] = str[i];
    }

    return *this;
}

char MyString::at(int i) const {
    if(i >= string_length || i < 0) {
        return 0;
    } else {
        return string_content[i];
    }
}

MyString& MyString::insert(int loc, const MyString& str) {
    if(loc < 0 || loc > string_length) return *this;

    if(string_length + str.string_length > memory_capacity) {
        if(memory_capacity * 2 > string_length + str.string_length) {
            memory_capacity *= 2;
        } else {
            memory_capacity = string_length + str.string_length;
        }

        char *temp = string_content;
        string_content = new char[memory_capacity];

        int i = 0;
        for(; i < loc; i++) {
            string_content[i] = temp[i];
        }

        for(int j = 0; j < str.string_length;j++) {
            string_content[i + j] = str.string_content[j];
        }

        for(; i < string_length; i++) {
            string_content[str.string_length + i] = temp[i];
        }

        delete[] temp;
        string_length = string_length + str.string_length;
        
        return *this;
    }

    for(int i = string_length - 1; i >= loc; i++) {
        string_content[i + str.string_length] = string_content[i];
    }

    for(int i = 0; i < str.string_length; i++) {
        string_content[i + loc] = str.string_content[i];
    }
    string_length = string_length + str.string_length;

    return *this;
}

MyString& MyString::insert(int loc, const char* str) {
    MyString temp(str);
    return insert(loc, temp);
}

MyString& MyString::insert(int loc, char c) {
    MyString temp(c);
    return insert(loc, temp);
}

MyString& MyString::erase(int loc, int num) {
    if(loc > string_length || loc < 0 || num < 0) return *this;
    for(int i = loc + num; i < string_length; i++) {
        string_content[i - num] = string_content[i];
    }
    string_length -= num;

    return *this;
}

int MyString::find(int st, const MyString& str) const {
    if(str.string_length > string_length - st || str.string_length == 0 || st >= string_length || st < 0) return -1;

    int ans = -1;

    int *failure;
    failure = new int[str.string_length];
    failure[0] = 0;
    int j = 0;
    for(int i = 1; i < str.string_length; i++) {
        while(j > 0 && str.string_content[i] != str.string_content[j]) j = failure[j - 1];
        if(str.string_content[i] == str.string_content[j]) failure[i] = ++j;
    }

    j = 0;
    for(int i = st; i < string_length; i++) {
        while(j > 0 && string_content[i] != str.string_content[j]) j = failure[j - 1];

        if(string_content[i] == str.string_content[j]) j++;
        
        if(j == str.string_length) {
            ans = i - j + 1;
            j = failure[j - 1];
            break;
        }
    }

    delete[] failure;
    return ans;
}

int MyString::find(int find_from, const char* str) const {
    MyString temp(str);
    return find(find_from, temp);
}
int MyString::find(int find_from, char c) const {
    MyString temp(c);
    return find(find_from, temp);
}

int MyString::compare(const MyString& str) const {
    //(*this)와 비교해 1: (*this)가 사전적으로 뒤, 0: 서로 같음, -1: (*this)가 사전적으로 앞
    for(int i = 0; i < std::min(string_length, str.string_length); i++) {
        if(string_content[i] > str.string_content[i]) return 1;
        else if(string_content[i] > str.string_content[i]) return -1;
    }

    if(string_length == str.string_length) return 0;
    else if(string_length > str.string_length) return 1;

    return -1;
}

bool MyString::operator==(MyString& str) const {
    return !compare(str);
}

char& MyString::operator[](const int index) const {
    return string_content[index];
} 

int main() {
    MyString str1("very long string");
    MyString str2("<some string inserted between>");
    str1.reserve(30);

    std::cout << "Capacity : " << str1.capacity() << std::endl;
    std::cout << "String length : " << str1.length() << std::endl;
    str1.println();

    str1.insert(5, str2);
    str1.println();

    std::cout << "Capacity : " << str1.capacity() << std::endl;
    std::cout << "String length : " << str1.length() << std::endl;
    str1.println();

    MyString str3("this is a very very long string");
    std::cout << "Location of first <very> in the string : " << str3.find(0, "very") << std::endl;
    std::cout << "Location of second <very> in the string : " << str3.find(str3.find(0, "very") + 1, "very") << std::endl;

    return 0;
}