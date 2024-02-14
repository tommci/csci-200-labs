/* CSCI 200: Assignment L4A: Inventory Management
 *
 * Author: Thomas McInnes
 * Resources used: Lecture Slides
 * 
 *
 * Utilizes the Big Three to create/destroy copies of classes
 */
#include "Warehouse.h"

using namespace std;

Warehouse::Warehouse() {
    _pBoxen = new vector<Box*>;
}

Warehouse::Warehouse( const Warehouse& OTHER ) {
    _pBoxen = new vector<Box*>;
    for( size_t i = 0; i < OTHER._pBoxen->size(); i++) {
        _pBoxen->push_back(new Box( *(OTHER._pBoxen->at(i)) ));
    }
}

Warehouse::~Warehouse() {
    for( size_t i = 0; i < _pBoxen->size(); i++ ) {
        delete _pBoxen->at(i);
    }
    _pBoxen->clear();
    delete _pBoxen;
}

void Warehouse::storeInBox(const int SIZE) {
    _pBoxen->push_back( new Box(SIZE) );
}

Box* Warehouse::getBox(const int BOX_POS) const {
    return _pBoxen->at(BOX_POS);
}

int Warehouse::getNumberOfBoxes() const {
    return _pBoxen->size();
}

Warehouse& Warehouse::operator=( const Warehouse& OTHER ) {
    if( this == &OTHER ) { return *this; }
    this->~Warehouse();
    _pBoxen = new vector<Box*>;
    for( size_t i = 0; i < OTHER._pBoxen->size(); i++) {
        _pBoxen->push_back(new Box( *(OTHER._pBoxen->at(i)) )); // dereferences the address at the position copying
    }
    return *this;
}

std::ostream& operator<<(ostream& os, const Warehouse& WH) {
    os << "Warehouse has " << WH.getNumberOfBoxes() << " boxes (";
    for(int i = 0; i < WH.getNumberOfBoxes(); i++) {
        os << WH.getBox(i)->getBoxSize();
        if(i < WH.getNumberOfBoxes() - 1) {
            os << ", ";
        }
    }
    os << ")";
    return os;
}