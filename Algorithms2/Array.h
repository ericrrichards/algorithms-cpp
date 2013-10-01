#pragma once

#include "Algorithms2.h"

template <class T>
class  Array {
public:
	int Size() const{
		return _size;
	}
	Array(){
		_size = 0;
		_capacity = 100;
		_array = new T[_capacity];
	}
	~Array(){
		if ( _array != NULL ){
			delete[] _array;
		}
	}
    T& operator[](int i ) {
        if ( i > 0 && i >= _size ){
            throw "out-of-range exception";
        }
        return _array[i];
    }
    const T& operator[](int i )  const {
        if ( i > 0 && i >= _size ){
            throw "out-of-range exception";
        }
        return _array[i];
    }
    void Add(T value ){
        if ( _size + 1 >= _capacity ){
            T* newArray = new T[_capacity * 2];
            for (int i = 0; i < _size; i++){
                newArray[i] = _array[i];
            }
            delete[] _array;
            _array = newArray;
        }
        _array[_size++] = value;
        
    }


private:
	int _size;
	int _capacity;
	T* _array;
};