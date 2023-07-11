bool isAnyMapping(vector<string>& words, int row, int col, int bal, unordered_map<char, int>& letterToDigit,
    vector<char>& digitToLetter, int totalRows, int totalCols) {
    if (col == totalCols) {
        return bal == 0;
    }

    if (row == totalRows) {
        return (bal % 10 == 0 &&
            isAnyMapping(words, 0, col + 1, bal / 10, letterToDigit, digitToLetter, totalRows, totalCols));
    }

    string w = words[row];

    if (col >= w.length()) {
        return isAnyMapping(words, row + 1, col, bal, letterToDigit, digitToLetter, totalRows, totalCols);
    }

    char letter = w[w.length() - 1 - col];
    int sign;

    if (row < totalRows - 1) {
        sign = 1;
    }
    else {
        sign = -1;
    }

    if (letterToDigit.count(letter) &&
        (letterToDigit[letter] != 0 || (letterToDigit[letter] == 0 && w.length() == 1) || col != w.length() - 1)) {

        return isAnyMapping(words, row + 1, col, bal + sign * letterToDigit[letter],
            letterToDigit, digitToLetter, totalRows, totalCols);

    }
    else {
        for (int i = 0; i < 10; i++) {
            if (digitToLetter[i] == '-' && (i != 0 || (i == 0 && w.length() == 1) || col != w.length() - 1)) {
                digitToLetter[i] = letter;
                letterToDigit[letter] = i;
                bool x = isAnyMapping(words, row + 1, col, bal + sign * letterToDigit[letter],
                    letterToDigit, digitToLetter, totalRows, totalCols);

                if (x == true) {
                    return true;
                }

                digitToLetter[i] = '-';
                if (letterToDigit.find(letter) != letterToDigit.end()) {
                    letterToDigit.erase(letter);
                }
            }
        }
    }

    return false;
}

bool isSolvable(int m, vector<string>& words, string result) {
    words.push_back(result);
    int totalRows;
    int totalCols;
    totalRows = words.size();
    totalCols = 0;

    for (int i = 0; i < words.size(); i++) {
        if (totalCols < words[i].size()) {
            totalCols = words[i].size();
        }
    }

    unordered_map<char, int> letterToDigit;
    vector<char> digitToLetter(10, '-');

    return isAnyMapping(words, 0, 0, 0, letterToDigit, digitToLetter, totalRows, totalCols);
}
