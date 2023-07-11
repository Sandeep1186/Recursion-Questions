#include<algorithm>

void backtrack(string & str, string temp, int ind, int count, vector < string > & ans) {
    // Base Case.
    if (ind >= str.size()) {
        // If 'COUNT' is greater than 0, it means we have skipped count characters in str.
        if (count > 0) {
            temp += to_string(count);
        }

        ans.push_back(temp);

        return;
    }

    // Recursive Calls.
    backtrack(str, temp, ind + 1, count + 1, ans);

    if (count == 0) {
        backtrack(str, temp + str[ind], ind + 1, count, ans);
    } else {
        temp += to_string(count);
        temp += str[ind];
        backtrack(str, temp, ind + 1, 0, ans);
    }
}

vector < string > findAbbr(string & str) {

    // This array will store the result.
    vector < string > ans;

    backtrack(str, "", 0, 0, ans);

    sort(ans.begin(), ans.end());
    
    return ans;
}genera
