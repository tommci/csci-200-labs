/* CSCI 200: Assignment L6A: Escape Room
 *
 * Author: Thomas McInnes
 * Resources used: Lecture Notes
 * 
 *
 * Creating two different types of lists via classes, and running them through a test suite
 */
#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "List.hpp"

#include <exception>
#include <iostream>
#include <string>

template<typename T>
class Array final : public IList<T> {
public:
    Array();
    ~Array();

    int size() const override;
    T get(const int POS) const override;
    void set(const int POS, const T VALUE) override;
    void insert(const int POS, const T VALUE) override;
    void remove(const int POS) override;
    T min() const override;
    T max() const override;
    int find(const T VALUE) const override;

    void sort() override;
    int search(const T VALUE) const override;

private:
    unsigned int _size; // why on EARTH was this a regular int by default?????????
    T* _pArray;
};

//---------------------------------------------------------

template<typename T>
Array<T>::Array() {
    // set size to zero
    _size = 0;
    // set array to be a nullptr
    _pArray = nullptr;
}

template<typename T>
Array<T>::~Array() {
    // deallocate current array
    delete[] _pArray;
}

template<typename T>
int Array<T>::size() const { 
    return _size;
}

template<typename T>
T Array<T>::get(const int POS) const {
    // if POS is out of range, throw std::out_of_range exception
    if( POS >= (int)_size || POS < 0 ) {
        throw std::out_of_range("Position out of range");
    }
    // return value at POS within array
    return _pArray[POS];
}

template<typename T>
void Array<T>::set(const int POS, const T VALUE) {
    // if POS is out of range, throw std::out_of_range exception
    if( POS >= (int)_size || POS < 0 ) {
        throw std::out_of_range("Position out of range");
    }
    // set VALUE at POS within array    
    _pArray[POS] = VALUE;
}

template<typename T>
void Array<T>::insert(const int POS, const T VALUE) {
    // if POS is before zero, clamp to zero
    unsigned int clampPos = POS;
    if( POS < 0 ) {
        clampPos = 0;
    }

    // if POS is after size, clamp to size
    if( POS > (int)_size ) {
        clampPos = _size;
    }

    // create new array of size + 1
    T* pTempArr = new T[_size + 1];

    // copy elements 0 to POS from old array to new array
    for( unsigned int i = 0; i < clampPos; i++ ) {
        pTempArr[i] = _pArray[i];
    }

    // set element at POS in new array to VALUE
    pTempArr[clampPos] = VALUE;

    // copy elements POS to size from old array to new array
    for( unsigned int i = clampPos + 1; i < _size + 1; i++ ) {
        pTempArr[i] = _pArray[i - 1];
    }

    // delete old array
    delete[] _pArray;

    // set old array to be new array
    _pArray = pTempArr;

    // increment size
    _size++;

}

template<typename T>
void Array<T>::remove(const int POS) {
    // if array is empty, throw std::out_of_range exception
    if( _size <= 0 ) {
        throw std::out_of_range("List is empty");
    }

    unsigned int clampPos = POS;
    // if POS is before zero, clamp to zero
    if( POS < 0 ) {
        clampPos = 0;
    }

    // if POS is after size, clamp to size
    if( POS >= (int)_size ) {
        clampPos = _size - 1;
    }

    // create new array of size - 1
    T* pTempArr = new T[_size - 1];

    // copy elements from 0 to POS from old array to  new array
    for( unsigned int i = 0; i < clampPos; i++ ) {
        pTempArr[i] = _pArray[i];
    }

    // copy elements from POS+1 to size from old array to new array
    for( unsigned int i = clampPos + 1; i < _size; i++ ) {
        pTempArr[i - 1] = _pArray[i];
    }

    // delete old array
    delete[] _pArray;

    // set old array to be new array
    _pArray = pTempArr;

    // decrement size
    _size--;

}

template<typename T>
T Array<T>::min() const {
    // if array is empty, throw std::out_of_range exception
    if( _size <= 0 ) {
        throw std::out_of_range("List is empty");
    }
    
    // find minimum value within array
    T minVal = _pArray[0];
    for( unsigned int i = 1; i < _size; i++ ) {
        if( _pArray[i] < minVal ) {
            minVal = _pArray[i];
        }
    }
    
    // return min value
    return minVal;
}

template<typename T>
T Array<T>::max() const {
    // if array is empty, throw std::out_of_range exception
    if( _size <= 0 ) {
        throw std::out_of_range("List is empty");
    }
    
    // find maximum value within array
    T maxVal = _pArray[0];
    for( unsigned int i = 1; i < _size; i++ ) {
        if( _pArray[i] > maxVal ) {
            maxVal = _pArray[i];
        }
    }
    
    // return max value
    return maxVal;
}

template<typename T>
int Array<T>::find(const T VALUE) const {
    // search for first occurrence of VALUE
    for( unsigned int i = 0; i < _size; i++ ) {
        if( _pArray[i] == VALUE ) {
            return i;
        }
    }
    
    // return index of first occurrence if found
    
    // otherwise return -1
    return -1;
}

template<typename T>
void Array<T>::sort() {
    // prints the current array (callee)
    std::cout << "Initial array: ";
    for( unsigned int i = 0; i < _size; i++ ) {
        std::cout << this->get(i) << " ";
    }
    std::cout << std::endl;
    
    // checks the base case (list is length 1)
    if( _size <= 1 ) { return; } // already sorted, do nothing

    // splits callee into two halves
    else {
        Array<T> *pLeft = new Array<T>, *pRight = new Array<T>;
        unsigned int thisHalf = _size / 2;
        for( unsigned int i = 0; i < thisHalf; i++ ) {
            pLeft->insert(pLeft->size(), this->get(0));
            this->remove(0);
        }
        thisHalf = _size;
        for( unsigned int i = 0; i < thisHalf; i++ ) {
            pRight->insert(pRight->size(), this->get(0));
            this->remove(0);
        }

        // prints the left half
        std::cout << "Left: ";
        for( int i = 0; i < pLeft->size(); i++ ) {
            std::cout << pLeft->get(i) << " ";
        }
        std::cout << std::endl;

        // prints the right half
        std::cout << "Right: ";
        for( int i = 0; i < pRight->size(); i++ ) {
            std::cout << pRight->get(i) << " ";
        }
        std::cout << "\n" << std::endl;

        // recurse: sort both halves
        pLeft->sort();
        pRight->sort();

        // merge: merges the halves
        for( int i = 0; i < pLeft->size(); i++ ) {
            if( pLeft->get(i) < pRight->get(i) ) {
                this->insert(0, pRight->get(i));
                this->insert(0, pLeft->get(i));
            } else {
                this->insert(0, pLeft->get(i));
                this->insert(0, pRight->get(i));
            }
        }

        // prints the merged halves
        std::cout << "Merged: ";
        for( unsigned int i = 0; i < _size; i++ ) {
            std::cout << this->get(i) << " ";
        }
        std::cout << std::endl;

    }

}

template<typename T>
int Array<T>::search(const T VALUE) const {
    search(VALUE);
    return -1;
}

#endif//ARRAY_H