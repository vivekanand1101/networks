#include <bits/stdc++.h>

using namespace std;

void NRZ_L (string array)
{
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

string get_binary_sequence(char num)
{
    int val = (int)num;

    char a[1000];
    int i = 0;
    int m = 0;

    int j;
    while(val) {
        j = val % 2;
        if (j == 0) {
            a[m++] = '0';
        } else {
            a[m++] = '1';
        }

        val = val / 2;
    }

    reverse(a, a + m);

    return a;
}

int main()
{
    ifstream fi("input.txt");
    string array;

    while(getline(fi, array)) {
        int i = 0;
        cout << array << endl;
        while(array[i]) {
            string arr = get_binary_sequence(array[i]);
            NRZ_L(arr);
            //NRZ_I(arr);
            //Manchester(arr);
            //DiffManchester(arr);
            i++;
        }
    }

    return 0;
}
