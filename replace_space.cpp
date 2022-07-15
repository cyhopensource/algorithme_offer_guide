#include <iostream>
#include <vector>
#include <string>

using namespace std;

// e.g., "We are Happy."
// --->  "We%20are%20Happy."
// C++ Compilator

class Solution{

public:
    string ReplaceSpace(string s){
        int count = 0, len = s.size();
        if(len == 0) return s;

        for(int i = 0; i < len; i++){
            if(s[i] == ' ') count += 1;
        }
        s.resize(len + 2 * count);
        
        for(int i = len - 1, j = s.size(); i < j; i--, j--){
            if(s[i] != ' '){
                s[j] = s[i];
            }else{
                s[j - 2] = '%';
                s[j - 1] = '2';
                s[j] = '0';
                j -= 2;
            }
        }

        return s;
    }

};