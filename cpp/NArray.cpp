#include <iostream>

class Array;
class Int;

class Array {
    private:
    const int dim;
    int *size; //배열의 크기 정보 size[3] = {2, 3, 4}면 Array[2][3][4]

    struct Address {
        int level;
        void* next; //level이 dim - 1이면 자료를 가리키고 그 전에는 다음 Address 배열을 가리킴
    };
    Address* top;

    friend Int;

    public:
    Array() = delete;
    Array(int dim, int *array_size);
    Array(const Array& arr);
    ~Array();

    void initialize_address(Address *current);
    void delete_address(Address *current);
    void copy_address(Address *dst, Address *src);

    Int operator[](const int index);
};

Array::Array(int dim, int *array_size) : dim(dim) {
    size = new int[dim];
    for(int i = 0; i < dim; i++) size[i] = array_size[i];
    
    top = new Address;
    top->level = 0;
    initialize_address(top);
}

Array::Array(const Array& arr) : dim(arr.dim) {
    size = new int[dim];
    for(int i = 0; i < dim; i++) size[i] = arr.size[i];

    top = new Address;
    top->level = 0;

    initialize_address(top);
    copy_address(top, arr.top);
}

Array::~Array() {
    delete_address(top);
    delete[] size;
}

void Array::initialize_address(Address *current) {
    if (!current) return;

    if (current->level == dim - 1) { //끝에 도달해서 데이터를 가리킴
        current->next = new int[size[current->level]];
        return;
    }

    current->next = new Address[size[current->level]];
    for (int i = 0; i != size[current->level]; i++) {
        (static_cast<Address*>(current->next) + i)->level = current->level + 1;
        initialize_address(static_cast<Address*>(current->next) + i);
    }
}

void Array::delete_address(Address *current) {
    if (!current) return;

    for (int i = 0; current->level < dim - 1 && i < size[current->level]; i++) {
        delete_address(static_cast<Address*>(current->next) + i);
    }

    if (current->level == dim - 1) {
        delete[] static_cast<int*>(current->next);
    }

    delete[] static_cast<Address*>(current->next);
}

void Array::copy_address(Address *dst, Address *src) {
    if(dst->level == dim - 1) {
        for (int i = 0; i < size[dst->level]; ++i) {
            static_cast<int*>(dst->next)[i] = static_cast<int*>(src->next)[i];
        }
        return;
  }
    for (int i = 0; i != size[dst->level]; i++) {
        Address *new_dst = static_cast<Address*>(dst->next) + i;
        Address *new_src = static_cast<Address*>(src->next) + i;
        copy_address(new_dst, new_src);
    }
}

class Int {
    void *data;
    int level;
    Array *array;

    public:
    Int(int index, int _level = 0, void *_data = nullptr, Array *_array = nullptr);
    Int(const Int& i);

    operator int();
    Int& operator=(const int& i);
    Int operator[](const int index);
};

Int::Int(int index, int _level, void *_data, Array *_array) : level(_level), data(_data), array(_array) {
    if(_level < 1 || index >= array->size[_level - 1]) {
        data = nullptr;
        return;
    }

    if(level == array->dim) {
        data = static_cast<void*>((static_cast<int*>(static_cast<Array::Address*>(data)->next) + index));
    } else {
        data = static_cast<void*>((static_cast<Array::Address*>(static_cast<Array::Address*>(data)->next) + index));
    }
}

Int::Int(const Int& i) : level(i.level), data(i.data), array(i.array) {}

Int::operator int() {
    if(data) return *static_cast<int*>(data);
    return 0;
}

Int& Int::operator=(const int& i) {
    if(data) *static_cast<int*>(data) = i;
    return *this;
}

Int Int::operator[](const int index) {
    if(!data) return 0;
    return Int(index, level + 1, data, array);
}

Int Array::operator[](const int index) {
  return Int(index, 1, static_cast<void*>(top), this);
}

int main() {




    return 0;
}