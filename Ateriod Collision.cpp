Question:
 We are given an array asteroids of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). 
Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

 

Example 1:

Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
  
  ANS:
       vector<int> asteroidCollision(vector<int>& a) {
        int n=a.size(),i;
        stack<int>s;
        vector<int>v,v1;
        for(i=0;i<n;i++){
            if(a[i]>0){
                s.push(a[i]); //same direction elements to be pushed every time in stack
            }
            else{
                while(!s.empty() && abs(a[i])>s.top())
                    s.pop(); //we'll pop every element of stack if opp. direction element found to be greater than all elements.
                if(s.empty()) v.push_back(a[i]);// due to this element all stack ele are poped so that is our potential ans.
                else if (abs(a[i]) == s.top()) s.pop();
            } // if top==a[i] in opp. dir then both will be poped.
        }
        while(!s.empty()) {v1.push_back(s.top()); s.pop();} 
        for(i=v1.size();i>0;i--) v.push_back(v1[i-1]); //to add reverse stack into vect.
                                                    // by using v1 to push stack ele and pushing from end in order to reverse.
        return v;
    }
