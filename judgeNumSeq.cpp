#include <iostream>
#include <string>

using namespace std;

// using the state machine
// this solution is not really correct

// using HashMap to map the state machine will be better

// ### Compiler is very difficult

#define INIT 10

#define SIGN 20
#define SIGN_NUM 21

#define NO_SIGN 30
#define NO_SIGN_NUM 31

#define START_DECIMAL 40
#define NUM_DECIMAL 41
#define DECIMAL_BODY 42

#define INDEX 50
#define INDEX_BODY 51
#define INDEX_PRE 52

#define NUM_SPACE 60

#define ERROR 100

class Solution {
public:
    bool isNumber(string s) {
        int state = INIT;
        int len = s.size();
        for(int i = 0; i < len; i ++){
            char ch = s[i];
            switch(state){
                case INIT:
                    if((ch == '+') || (ch == '-'))
                        state = SIGN;
                    else if (ch == ' ')
                        state = INIT;
                    else if ((48 <= int(ch)) && (int(ch) <= 57))
                        state = NO_SIGN;
                    else if (ch == '.')
                        state = START_DECIMAL;
                    else
                        state = ERROR;
                    break;

                case SIGN:
                    if((48 <= int(ch)) && (int(ch) <= 57))
                        state = SIGN_NUM;
                    else if(ch == '.')
                        state = START_DECIMAL;
                    else
                        state = ERROR;
                    break;

                case SIGN_NUM:
                    if((48 <= int(ch)) && (int(ch) <= 57))
                        state = SIGN_NUM;
                    else if(ch == '.')
                        state = NUM_DECIMAL;
                    else if((ch == 'e') || (ch == 'E'))
                        state = INDEX;
                    else if(ch == ' ')
                        state = NUM_SPACE;
                    else
                        state = ERROR;
                    break;

                case NO_SIGN:
                    if((48 <= int(ch)) && (int(ch) <= 57))
                        state = NO_SIGN;
                    else if(ch == '.')
                        state = NUM_DECIMAL;
                    else if((ch == 'e') || (ch == 'E'))
                        state = INDEX;
                    else if(ch == ' ')
                        state = NUM_SPACE;
                    else
                        state = ERROR;
                    break;


                case START_DECIMAL:
                    if((48 <= int(ch)) && (int(ch) <= 57))
                        state = DECIMAL_BODY;
                    else if((ch == 'e') || (ch == 'E'))
                        state = INDEX;
                    else
                        state = ERROR;
                    break;

                case DECIMAL_BODY:
                    if((48 <= int(ch)) && (int(ch) <= 57))
                        state = DECIMAL_BODY;
                    else if(ch == ' ')
                        state = NUM_SPACE;
                    else
                        state = ERROR;
                    break;

                case INDEX:
                    if((ch == '+') || (ch == '-'))
                        state = INDEX_PRE;
                    else if((48 <= int(ch)) && (int(ch) <= 57))
                        state = INDEX_BODY;
                    else
                        state = ERROR;
                    break;

                case INDEX_PRE:
                    if((48 <= int(ch)) && (int(ch) <= 57))
                        state = INDEX_BODY;
                    else
                        state = ERROR;
                    break;
                
                case INDEX_BODY:
                    if((48 <= int(ch)) && (int(ch) <= 57))
                        state = INDEX_BODY;
                    else
                        state = ERROR;
                    break;

                case NUM_SPACE:
                    if(ch == ' ')
                        state = NUM_SPACE;
                    else
                        state = ERROR;
                    break;
                
                case NUM_DECIMAL:
                    if((48 <= int(ch)) && (int(ch) <= 57))
                        state = DECIMAL_BODY;
                    else if(ch == ' ')
                        state = NUM_SPACE;
                    else
                        state = ERROR;
                    break;

                default: break;
    
            }
            // check after each run of state machine.
            if(state == ERROR)
                return false;       
        }
        
        if((state == INIT) || (state == SIGN) || (state == START_DECIMAL) || (state == INDEX) || (state == INDEX_PRE))
            return false;
        
        return true;
    }
};


    