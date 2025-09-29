#include <iostream>
using namespace std;

int main(){
    int n; //n=3
    int a = 1;
    cin >> n;

    for (int i = n; i >= 1; i--)  //3
    {
        //cetak 321
        for (int j = i; j >= 1; j--) // 3 2 1
        {
            cout << j;
        }
        
        cout << "*";
        //cetak 123
        for (int j = 1; j <= i; j++)
        {
            cout << j ;
        }

        cout << endl;
        //spasi 
        for (int j = 1; j <= a; j++) //2 //3
        {
           cout << " ";
        }
        a = a + 1;

    }
    cout << "*";

}