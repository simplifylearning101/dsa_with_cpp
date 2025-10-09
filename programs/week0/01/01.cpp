#include <iostream>
using namespace std;

int main(){

    int age = 25;
    double height = 5.9;
    char initial = 'A';
    bool isStudent = true;

    cout << "Age = " << age << endl;
    cout << "Height: " << height << endl;
    cout << "Initial: " << initial << endl;
    cout << "Is Student: " << (isStudent ? "Yes" : "No") << endl;

    return 0;
}