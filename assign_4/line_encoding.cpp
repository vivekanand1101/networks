#include <bits/stdc++.h>

using namespace std;

void NRZ_L (string array)
{
    cout << "NRZ_L: " << endl;
    for (int i = 0; array[i] != '\0'; i++) {
        if (array[i] == '1') {
            cout << "L ";
        } else if (array[i] == '0') {
            cout << "H ";
        }
    }

    cout << endl;
}

void NRZ_I (string array)
{
    cout << "NRZ_I: " << endl;
    char state;
    if (array[0] == '1') {
        state = 'L';
        cout << state << " ";
    } else {
        state = 'H';
        cout << state << " ";
    }

    for (int i = 1; array[i] != '\0'; i++) {
        if (array[i] == '1') {
            if (state == 'L') {
                state = 'H';
                cout << state << " ";
            } else {
                state = 'L';
                cout << state << " ";
            }
        } else {
            if (state == 'L') {
                cout << state << " ";
            } else {
                cout << state << " ";
            }
        }
    }

    cout << endl;
}

void Manchester (string array)
{
    cout << "Manchester: " << endl;
    for (int i = 0; array[i] != '\0'; i++) {
        if (array[i] == '1') {
            cout << "L H ";
        } else {
            cout << "H L ";
        }
    }

    cout << endl;
}

void DiffManchester(string array)
{
    cout << "Diff Manchester: " << endl;
    char state;
    if (array[0] == '1') {
        state = 'H'; // The state after the first bit is taken care of
        cout << "L H ";
    } else {
        state = 'L';
        cout << "H L ";
    }

    for (int i = 1; array[i] != '\0'; i++) {
        if (array[i] == '1') {
            if (state == 'L') {
                state = 'H';
                cout << "L H ";
            } else {
                state = 'L';
                cout << "H L ";
            }
        } else {
            if (state == 'L') {
                state = 'L';
                cout << "H L ";
            } else {
                state = 'H';
                cout << "L H ";
            }
        }
    }

    cout << endl;
}

int main()
{
    string array;
    cout << "Enter the binary sequence: " << endl;
    cin >> array;
    NRZ_L(array);
    NRZ_I(array);
    Manchester(array);
    DiffManchester(array);
    return 0;
}
