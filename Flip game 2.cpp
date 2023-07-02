#include <iostream>
#include <string>
using namespace std;

bool canNinjaWin(string& str) {
    if (str.length() < 2) {
        return false;
    }

    for (int i = 0; i < str.length() - 1; i++) {
        if (str[i] == '$' && str[i + 1] == '$') {
            string newStr = str;
            newStr[i] = '*';
            newStr[i + 1] = '*';

            if (!canNinjaWin(newStr)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    string str;
    cin>>str;
    bool ans = canNinjaWin(str);

    if (ans) cout << "True" << endl;
     else cout << "False" << endl;

}

