/* CSCI 200: Lab 2B: Pointers: Addresses and Values
 *
 * Author: Thomas McInnes
 *
 * This project experiments with and shows some behaviors of pointers in the stack.
 */
#include <iostream>
using namespace std;

int main() {

    /* All newlines output to the console are for formatting to make
       outputs more readable, and do not necessarily correlate to 
       the actual steps themselves. Steps themeslves are outlined
       here in the code using comments. */

    // Step 1
    int iNum = 4, iNum2 = 5;

    // Step 2
    int *pINum1 = nullptr, *pINum2 = nullptr;

    // Steps 3 and 4
    pINum1 = &iNum;
    pINum2 = &iNum2;

    // Steps 5 and 6
    cout << "\n" << pINum1 << " | This is the memory address of iNum, printed using a pointer" << endl;
    cout << &iNum << " | This is the same memory address, printed using '&' instead of a pointer\n" << endl;

    cout << pINum2 << " | This is the memory address of iNum2, printed using a pointer" << endl;
    cout << &iNum2 << " | This is the same memory address, printed using '&' instead of a pointer\n" << endl;

    // Steps 7 and 8
    cout << *pINum1 << " | Using the pointer to display the value for iNum" << endl;
    cout << *pINum2 << " | Using the pointer to display the value for iNum2\n" << endl;

    // Steps 9, 10, 11
    iNum = 6;
    cout << iNum << " | Output of iNum, now changed to 6" << endl;
    cout << *pINum1 << " | Outputting iNum using pINum1" << endl;

    // Steps 12 and 13
    *pINum1 = 7;     // using pointer to change value at the address it is pointing at
    cout << iNum << " | New value of iNum after changing it with pINum1\n" << endl;

    // Steps 14, 15, 16
    pINum2 = pINum1; // assigning the address in pINum1 to pINum2 (pINum2 now points at iNum)
    cout << pINum2 << " | Value of pINum2: This should now be the same as first console output" << endl;
    cout << *pINum2 << "        | Value pINum2 is pointing at: This should be the same as iNum's value\n" << endl;

    // Step 17
    *pINum2 = 8;

    // Step 18, 19
    cout << *pINum1 << " | Outputting iNum using pINum1" << endl;
    cout << *pINum2 << " | Outputting iNum using pINum2" << endl;
    cout << iNum << " | Outputting iNum using iNum itself" << endl;
    cout << iNum2 << " | Outputting iNum2 (this value should be different from the last 3 outputs)\n" << endl;

    // Step 20
    double *pDNum = nullptr;

    /* Step 21
    pDNum = &iNum; -> error: cannot convert 'int*' to 'double*' in assignment
    */

    /* Step 22
    pDNum = pINum1; -> error: cannot convert 'int*' to 'double*' in assignment    
    */

    // Steps 23 and 24
    double dNum = 14.25;
    pDNum = &dNum;

    // Step 25
    cout << pDNum << " | Address of dNum" << endl;
    cout << *pDNum << "    | Value of dNum using pDNum\n" << endl;

    // Step 26
    *pINum1 = *pDNum; // assigning value pINum1 points at to value pDNum points at

    // Step 27
    cout << dNum << " | Outputting dNum using dNum" << endl;
    cout << *pDNum << " | Outputting dNum using pDNum" << endl;

    return 0;
}