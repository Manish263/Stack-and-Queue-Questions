You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.
Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

  ANS: 
     vector<int> maxSlidingWindow(vector<int>& a, int k) {
        int i,j,n=a.size();
        deque<int>dq;
        vector<int>v;
        for(i=0;i<n;i++){
//we keep poping out of window elements as they are not longer needed in window
            if(!dq.empty() && dq.front()==i-k) dq.pop_front();
//if in deque elements are smaller than upcoming a[i] we pop all smaller one because we need max of subarray so no point in keeping them.
            while(!dq.empty() && a[dq.back()]<=a[i]) dq.pop_back();
//pushing elements into deque from back.
            dq.push_back(i);
//keep checking that i index is greater than k-1 that is window size and keep pusing front element as it is max of subarray into vector v (ans).
            if(i>=k-1) v.push_back(a[dq.front()]);
        }
        return v;
    }
