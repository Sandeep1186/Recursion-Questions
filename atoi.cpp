#include <iostream>
using namespace std;

int convertStringToInt(int index, int result, string& str) {
    if (index == str.size()) {
        return result;
    }

    if ('0' <= str[index] && str[index] <= '9') {
        return convertStringToInt(index + 1, 10 * result + str[index] - '0', str);
    } else {
        return convertStringToInt(index + 1, result, str);
    }
}

int atoi(string str) {
    int num = convertStringToInt(0, 0, str);

    if (str[0] == '-') {
        num *= -1;
    }

    return num;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    int convertedInt = atoi(input);

    cout << "Converted integer: " << convertedInt << endl;

}
