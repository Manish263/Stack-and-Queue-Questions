Question : 
Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.
The next greater number of a number x is the first greater number to its traversing-order next in the array, 
which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

Example 1:

Input: nums = [1,2,1]
Output: [2,-1,2]

ANS :
     vector<int> nextGreaterElements(vector<int>& nums) {
        int i,n=nums.size();
        vector<int>v(n);
        stack<int>s;
        for(i=2*n-1;i>=0;i--){
//we keep pushing only greater elements checking from right to left if any lesser element comes during checking we pop that like we are pushing 2,3,4,-1,4; while pushing suppose we push 4 and -1 to stack as soon as we find element greater than -1 we pop -1 and keep doing in cirular manner using i%n to get index of circluar array.
            while(!s.empty() && s.top()<=nums[i%n]){
                s.pop();
            }
            if(i<n){
                if(!s.empty()){
                    //simply pushing next greater from right to left using stack.
                    v[i]=s.top();
                }
                //if not found push -1
                 else v[i]=-1;
            }
            s.push(nums[i%n]);
        }
        return v;
    }
 
