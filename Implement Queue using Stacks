Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.
Notes:

You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.
 

Example 1:

Input
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 1, 1, false]

Explanation
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false

ANS:

    MyQueue() {  

    }
    stack<int>s1,s2;
    void push(int x) {
       if(s1.empty()) s1.push(x); //pushing elements in stack 1 until it's full
       else {
           while(!s1.empty()){
               s2.push(s1.top()); s1.pop(); //we keep pushing s1 elements into s2 until s1 is empty.
           } 
           s1.push(x);
           while(!s2.empty()){
               s1.push(s2.top()); s2.pop(); //we keep pushing s2 elements into s1 until s2 is empty.
           }
       }  
    }
    
    int pop() {
        int ans=s1.top(); //keeping top to return then we pop it and move ahead.
         s1.pop();
        return ans;
    }
    int peek()
    {
        return s1.top(); //simply return us top element of stack
    }
    
    int top() {
        return s1.top(); //same as peek
    }
    
    bool empty() {
        return s1.empty(); //.empty() check wheather stack is empty or not if yes it return us true else false.
    }
