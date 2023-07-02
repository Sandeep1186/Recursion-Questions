#include <iostream>
#include <string>

using namespace std;

string removeDuplicate(string& str, int index = 0) {
    if (index >= str.length()) {
        return "";
    }

    if (str[index] == str[index + 1]) {
        return removeDuplicate(str, index + 1);
    }
    return str[index] + removeDuplicate(str, index + 1);
}
int main(){
    string s;
    cin>>s;
    cout<<removeDuplicate(s);
}
