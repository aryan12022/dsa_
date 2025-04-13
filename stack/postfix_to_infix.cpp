#include<bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

int priority(string a) {
    if (a == "^") return 3;
    else if (a == "*" || a == "/") return 2;
    else if (a == "+" || a == "-") return 1;
    else return -1;
}

string postfix_to_infix(string s) {
    stack<string> st;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];

        // If operand, push to stack
        if (isalnum(c)) {
            //checks for operand 
            st.push(string(1, c));
            // make a string of size 1 of character c
        } 
        // If operator 
        else {
            if (st.size() < 2) return "Invalid Expression";

            string op2 = st.top(); st.pop();
            string op1 = st.top(); st.pop();

            string temp = "(" + op1 + c + op2 + ")";
            st.push(temp);
        }
    }

    // Final answer should be on top of stack
    if (st.size() != 1) return "Invalid Expression";
    return st.top();
}
