Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true


ANS:
   
    bool isValid(string s) {
        int i=0,n=s.size();
        stack<int>st;
            for(i=0;i<n;i++){  
//we simply want to push all open brackets of 3 type into stack.  
                if(s[i]=='(' || s[i]=='[' || s[i]=='{') st.push(s[i]);
//then we're checking if stack top found to be opening bracket of type we're searching by using close bracket than pop that top element from stack
                else if (s[i]==')' || s[i]==']' || s[i]=='}'){
                    if(st.empty()) return false;
                    int c=st.top();st.pop();
//simply check if s[i] and top of stack make a combination of open and close bracket if they do so then kee checking for other ones else return false.
                    if((s[i]==')' && c=='(') or
                      (s[i]=='}' && c=='{')  or 
                      (s[i]==']' && c=='[')) continue;
                     else return false;
                }  
            }
//in the end if our stack is empty then it means that all opening bracket got their closing bracket hence ans true else false.
        if(st.empty()) return true;
        else return false;
    }
