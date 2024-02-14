#include "LinkedList.hpp"
#include "Array.hpp"

#include <iostream>

using namespace std;

int main() {

    Array<int> *pIntArray = new Array<int>;
    pIntArray->insert(0, 6);
    pIntArray->insert(0, 2);
    pIntArray->insert(0, 7);
    pIntArray->insert(0, 9);
    pIntArray->insert(0, 5);
    pIntArray->insert(0, 1);
    pIntArray->insert(0, 8);
    pIntArray->insert(0, 3);
    pIntArray->insert(0, 4);

    cout << "Sorting an array:" << endl;
    pIntArray->sort();

    return 0;
}