#include <iostream>
#include <stack>

using namespace std;

// double stack method ---> principal stack and auxiliary stack
// descending order non-strict

template <typename T>
class Minstack{

private:
    stack<T> A, B;

public:
    Minstack(){}

    void push(T x){
        A.push(x);
        if((B.empty()) || (x <= B.top()))
            B.push(x);
    }

    void pop(){
        T tmp = A.top();
        A.pop()
        if(tmp == B.top())
            B.pop();
    }

    T top(){
        return A.top();
    }

    T min(){
        return B.top();
    }

};