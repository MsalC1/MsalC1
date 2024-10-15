#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H
#include <ostream>

template<class T>
class ArrayList;

template<class T>
class resize;

template<class T>
class resize{
    resize();
public:
    resize(capacity){
        T* temp = new T(capacity)

        for (int i = 0; i < count; i++){
            temp[i] = data[i]
        }

        T* old = data;
        data = temp;
        delete[] old;
    }
};

template<class T>
class ArrayList{
protected:
    T* data;
    int count;
    int capacity;
    
    // Used to replace a current list with a list twice its capacity:
    void inflate(){
        capacity *= 2;
        resize(capacity);
    }
    // Used to replace a current list with a list half its capacity or maintain its capacity:
    void deflate(){
        if (capacity <= 1 || count == 0){
            return;
        }
        capacity = std::max(capacity/2, count)
        resize(capacity);
    }

public:
    ArrayList(){
        count = 0;
        capacity = 1;
        data = new T[capacity];
    }

    // Copy Constructor
    ArrayList(const ArrayList& other){
        count = other.count;
        capacity = other.capacity;
        data = new T[capacity];
        for (int i = 0; i < count; i++){
            data[i] = other.data[i];
        }
    }

    // Overloaded assignmnent operator
    ArrayList& operator=(const ArrayList& other){
        if (capacity == other.capacity){
            count = other.count;
            for (int i = 0; i < count; i++){
                data[i] = other.data[i];
            }
        }
        else{
            delete[] data;
            count = other.count;
            capacity = other.capacity;
            data = new T[capacity];
            for (int i = 0; i < count; i++){
                data[i] = other.data[i];
            }
        }

        return *this;
    }

    void append(T value){
        data[count] = value;
        count++;
        if (count == capacity){
            inflate();
        }
    }

    void prepend(){

    }

    void remove(){

    }

    int getCount(){
        return 0;
    }
};

template <class T>
std::ostream& operator<<(std::ostream& os, const ArrayList<T>& list){
    os << "[";
    for (int i = 0; i < list.count; i++){
        
        os << list.data[i];
        if (i < list.count - 1){
            os << ", ";
        }
    }
    os << "]";
    return os;
}




#endif