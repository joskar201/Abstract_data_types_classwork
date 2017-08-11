#include <iostream>
#include <new>
using namespace std;

int i;
    int n;
    int *p;
int main {
    cout<<"How many elements will the array have?"<<endl
    cin>>i;
    p = new int[i];
    for(n=0;n<i;n++) {
        cout<<"Enter a number:";
        cin>>p[n];
    }
    for(n=0;n<i;n++) {
        cout<<"You entered"<<p[n]<<endl;
    }
    delete []p;
    return 0;
} 