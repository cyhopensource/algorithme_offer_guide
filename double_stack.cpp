#include <iostream>
#include <stack>

using namespace std;

// Double stack trick, change the order of some sequences
class CQueue{

private:
    stack<int> a_queue, b_aux;

public:
    CQueue(){}

    void appendTail(int value){
        a_queue.push(value);
    }

    int deleteHead(){
        if(a_queue.empty()) return -1;
        while(!a_queue.empty()){
            b_aux.push(a_queue.top());
            a_queue.pop();
        }
        int head = b_aux.top();
        b_aux.pop();
        while(!b_aux.empty()){
            a_queue.push(b_aux.top());
            b_aux.pop();
        }
        return head;
    }


};




