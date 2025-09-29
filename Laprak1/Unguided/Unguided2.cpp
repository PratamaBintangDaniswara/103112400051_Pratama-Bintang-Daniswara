#include <iostream>
using namespace std;

int main() {
    int n;
    string satuan[] = {"", "satu", "dua", "tiga", "empat",
                       "lima", "enam", "tujuh", "delapan", "sembilan"};
    string puluhan[] = {"", "sepuluh", "dua puluh", "tiga puluh", "empat puluh",
                        "lima puluh", "enam puluh", "tujuh puluh", "delapan puluh", "sembilan puluh"};

    cin >> n;

    cout << n << " : ";

    if (n == 0) {
        cout << "nol";
    }
    else if (n == 100) {
        cout << "seratus";
    }
    else if (n < 10) {
        cout << satuan[n];
    }
    else if (n < 20) {
        if (n == 10) cout << "sepuluh";
        else if (n == 11) cout << "sebelas";
        else cout << satuan[n % 10] << " belas";
    }
    else {
        int p = n / 10;
        int s = n % 10;
        cout << puluhan[p];
        if (s != 0) cout << " " << satuan[s];
    }

    cout << endl;
    return 0;
}
