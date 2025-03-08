#include<iostream>
using namespace std;

int main() {

    int var = 10;


    int* ptr = &var;


   cout << "Initial values:" <<endl;
   cout << "Variable value: " << var <<endl;
    cout << "Pointer value (address): " << ptr << endl;
    cout << "Pointer value: " << *ptr << endl;

 
    *ptr = 20;

    cout << "\nUpdated values:" << endl;
    cout << "Variable value: " << var << endl;
   cout << "Pointer value (address): " << ptr << endl;
    cout << "Pointer value " << *ptr << endl;

    return 0;
}