#include <iostream>
#include <stack>
#include <string>

using namespace std;

// string reverse exercise
// three reverse method
class Solution{

private:
    void reverseString(string &s, int i, int j){
        while(i < j) swap(s[i++], s[j--]);
    }

public:
    string reverseLeftWords(string s, int n){
        reverseString(s, 0, n - 1);
        reverseString(s, n, s.size() - 1);
        reverseString(s, 0, s.size() - 1);

        return s;
    }
};