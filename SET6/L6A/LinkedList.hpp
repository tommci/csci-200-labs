/* CSCI 200: Assignment L6A: The Abstract List Test Suite
 *
 * Author: Thomas McInnes
 * Resources used: Lecture Notes
 * 
 *
 * Creating two different types of lists via classes, and running them through a test suite
 */
#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include "List.hpp"

#include <exception>
#include <iostream>
#include <string>

template<typename T>
class LinkedList final : public IList<T> {
public:
    LinkedList();
    ~LinkedList();

    int size() const override;
    T get(const int POS) const override;
    void set(const int POS, const T VALUE) override;
    void insert(const int POS, const T VALUE) override;
    void remove(const int POS) override;
    T min() const override;
    T max() const override;
    int find(const T VALUE) const override;

private: 
    struct Node {
        T value;
        Node* pNext;
        Node* pPrev;
    };

    Node* _pHead;
    Node* _pTail;
    unsigned int _size; // why on EARTH was this a regular int by default?????????
};

//---------------------------------------------------------

template<typename T>
LinkedList<T>::LinkedList() {
  // set size to zero
  _size = 0;

  // set head to be a nullptr
  _pHead = nullptr;
  
  // set tail to be a nullptr
  _pTail = nullptr;
  
}

template<typename T>
LinkedList<T>::~LinkedList() {
    // remove each node in the list
    Node* pCurrentNode = _pHead;
    Node* pLastNode = nullptr;
    for( unsigned int i = 0; i < _size; i++ ) {
        pCurrentNode = pCurrentNode->pNext;
        pLastNode = pCurrentNode->pPrev;
        delete pLastNode->pNext;
        delete pLastNode;
        delete pCurrentNode->pPrev;
    }

    delete pCurrentNode;
    delete _pHead;
    delete _pTail;

}

template<typename T>
int LinkedList<T>::size() const {
    return _size;
}

template<typename T>
T LinkedList<T>::get(const int POS) const {
    // if POS is out of range, throw std::out_of_range exception
    if( POS >= (int)_size || POS < 0 ) {
        throw std::out_of_range("Index out of range");
    }
    
    // set current node to head
    Node* pCurrentNode = _pHead;
    
    // advance current node to POS
    for( int i = 0; i < POS; i++ ) {
        pCurrentNode = pCurrentNode->pNext;
    }
    
    // return value of current node
    return pCurrentNode->value;
}

template<typename T>
void LinkedList<T>::set(const int POS, const T VALUE) {
    // if POS is out of range, throw std::out_of_range exception
    if( POS >= (int)_size || POS < 0 ) {
        throw std::out_of_range("Index out of range");
    }

    // set current node to head
    Node* pCurrentNode = _pHead;

    // advance current node to POS
    for( int i = 0; i < POS; i++ ) {
        pCurrentNode = pCurrentNode->pNext;
    }

    // set value of current node   
    pCurrentNode->value = VALUE;
  
}

template<typename T>
void LinkedList<T>::insert(const int POS, const T VALUE) {
    // if POS is before zero, clamp to zero
    unsigned int clampPos = POS;
    if( POS < 0 ) { clampPos = 0; }
    
    // if POS is after size, clamp to size
    if( POS > (int)_size ) { clampPos = _size; }
    
    // create pointer to new node
    Node* pNewNode = new Node();
    
    // set value to be VALUE
    pNewNode->value = VALUE;
    
    // set previous pointer to nullptr
    pNewNode->pPrev = nullptr;
    
    // set next pointer to nullptr
    pNewNode->pNext = nullptr;
    
    // if list is currently empty
    if( _size == 0 ) {

        // set head and tail to new node
        _pHead = pNewNode;
        _pTail = pNewNode;
    
    }
    // otherwise
    else {
    
        // if position is before head
        if( clampPos == 0 ) {
    
            // set new node next to be head
            pNewNode->pNext = _pHead;
    
            // set head previous to be new node
            _pHead->pPrev = pNewNode;
    
            // set head to be new ndoe
            _pHead = pNewNode;
    
        // else if position is after tail
        } else if( clampPos == _size ) {
    
            // set new node previous to be tail
            pNewNode->pPrev = _pTail;
    
            // set tail next to be new node
            _pTail->pNext = pNewNode;
    
            // set tail to be new ndoe
            _pTail = pNewNode;
    
        // otherwise
        } else {

            // set current node to head
            Node* pCurrentNode = _pHead;
    
            // advance current node to pos
            for( unsigned int i = 0; i < clampPos; i++ ) {
                pCurrentNode = pCurrentNode->pNext;
            }
    
            // link new node into current list
            pNewNode->pPrev = pCurrentNode->pPrev;
            pNewNode->pNext = pCurrentNode;

            // link current list to new node
            pCurrentNode->pPrev = pNewNode;
            pCurrentNode = pNewNode->pPrev;
            pCurrentNode->pNext = pNewNode;
        }
    }
    
    // increment size
    _size++;
    
}

template<typename T>
void LinkedList<T>::remove(const int POS) {
    // if array is empty, throw std::out_of_range exception
    if( _size == 0 ) {
        throw std::out_of_range("List is empty");
    }
    
    // if POS is before zero, clamp to zero
    unsigned int clampPos = POS;
    if( POS < 0 ) { clampPos = 0; }
    
    // if POS is after size, clamp to size
    if( POS >= (int)_size ) { clampPos = _size - 1; }
    
    // if list has one element
    Node* pToDelete = nullptr;
    if( _size == 1 ) {
    
        // set node to delete to head
        pToDelete = _pHead;
    
        // set head and tail to be nullptr
        _pHead = nullptr;
        _pTail = nullptr;
    
    // otherwise
    } else {

        // if deleting head
        if( clampPos == 0 ) {
    
            // set node to delete to head
            pToDelete = _pHead;
    
            // advance head to next
            _pHead = _pHead->pNext;
    
            // set head previous to nullptr
            _pHead->pPrev = nullptr;

        }
        // else if deleting tail
        else if( clampPos == _size - 1 ) {
    
            // set node to delete to tail
            pToDelete = _pTail;
    
            // step tail to previous
            _pTail = _pTail->pPrev;
    
            // set tail next to nullptr
            _pTail->pNext = nullptr;
        }
        // otherwise
        else {
    
            // set current node to head
            Node* pCurrentNode = _pHead;
    
            // advance current node to space before position
            for( unsigned int i = 0; i < clampPos - 1; i++ ) {
                pCurrentNode = pCurrentNode->pNext;
            }
    
            // set node to delete to the current node's next node
            pToDelete = pCurrentNode->pNext;
    
            // unlink node to delete
            pCurrentNode->pNext = pToDelete->pNext;
            pCurrentNode = pToDelete->pNext;
            pCurrentNode->pPrev = pToDelete->pPrev;

        }
    }
    
    // delete node
    delete pToDelete;
    
    // decrement size
    _size--;
    
}

template<typename T>
T LinkedList<T>::min() const {
    // if list is empty, throw std::out_of_range exception
    if( _size == 0 ) {
        throw std::out_of_range("List is empty");
    }

    // find minimum value within list
    T minVal = _pHead->value;
    Node* pCurrentNode = _pHead;
    for( unsigned int i = 0; i < _size; i++ ) {
        if( pCurrentNode->value < minVal ) {
            minVal = pCurrentNode->value;
        }
        pCurrentNode = pCurrentNode->pNext;
    }
    
    // return min value
    return minVal;
}

template<typename T>
T LinkedList<T>::max() const {
    // if list is empty, throw std::out_of_range exception
    if( _size == 0 ) {
        throw std::out_of_range("List is empty");
    }
    
    // find maxiumum value within list
    T maxVal = _pHead->value;
    Node* pCurrentNode = _pHead;
    for( unsigned int i = 0; i < _size; i++ ) {
        if( pCurrentNode->value > maxVal ) {
            maxVal = pCurrentNode->value;
        }
        pCurrentNode = pCurrentNode->pNext;
    }
    
    // return max value
    return maxVal;
}

template<typename T>
int LinkedList<T>::find(const T VALUE) const {
    // search for first occurrence of VALUE
    Node* pCurrentNode = _pHead;
    for( unsigned int i = 0; i < _size; i++ ) {
        if( pCurrentNode->value == VALUE ) {
            return i;
        }
        pCurrentNode = pCurrentNode->pNext;
    }
    // return index of first occurrence if found
    
    // otherwise return -1
    return -1;
}

#endif//LINKED_LIST_H
