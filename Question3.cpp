#include<bits/stdc++.h>
using namespace std;
#define int long long int

// Function to perform shifting of a character
char shiftChar(char c, int shift) {
    if (isupper(c)) {
        return (c - 'A' + shift) % 26 + 'A';
    } else if (islower(c)) {
        return (c - 'a' + shift) % 26 + 'a';
    }
    return c; 
}

// Function to encode the string using Caesar cipher with a variable shift
string encode(string s, int shift) {
    string result = "";
    for (int i = 0; i < s.size(); i++) {
        result += shiftChar(s[i], shift + i); 
    }
    return result;
}

// Function to split the encoded string into 5 parts as per the problem statement
vector<string> split(string s) {
    vector<string> parts(5, ""); 

    int n = s.size();
    int baseSize = ceil((double)n/5);

    int index = 0;
    for (int i = 0; i < 5; i++) {
        if(n>baseSize)
        {
        parts[i] = s.substr(index, baseSize);
        index += baseSize;
        n-=baseSize;
        }
        else
        {
         parts[i] = s.substr(index, n);
         n=0;
        }
    }

    return parts;
}

vector<string> movingShift(string s, int shift) {
    string encodedMessage = encode(s, shift); 
    return split(encodedMessage); 
}

int32_t main() {
    string s ;
    int shift;
    cout << "Enter the string to encode: ";
    getline(cin, s); 
    cout << "Enter the initial shift value: ";
    cin >> shift; 
    vector<string> result = movingShift(s, shift); 
    for (auto &i: result) {
        cout << "\"" << i << "\"" << endl;
    }

    return 0;
}
