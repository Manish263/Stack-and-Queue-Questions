Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2


ANS:
     
      MinStack() {
        
    }
    vector<pair<int,int>>s;
//we use vector of pair in this.
    void push(int val) {
        if(s.size()==0) s.push_back({val,val});
        else {
//here we check if we get a pair having its second value smaller than current top in pair second value than we update our stack with that min value.       
            s.push_back({val,min(s.back().second,val)});
        }   
    }
    
    void pop() {
        s.pop_back();
    }
    
    int top() {
        if(s.size()==0) return -1;
        return s.back().first; //as we are using vector of pair so we've to return last.first value in order to get top.
    }
    
    int getMin() {
        if(s.size()==0) return -1;
        return s.back().second;
    }
