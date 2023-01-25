Question :
// Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.
Example 1:

// Input: arr = [3,1,2,4]
// Output: 17
// Explanation: 
// Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
// Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
// Sum is 17.

ANS: 

//intution:
//select an element and find next smaller element on right and left of it and than (ls+1)*(rs+1) 
//gives us all possible subbarays having minimum as our selected element. than adding all those for all elements gives us ans.
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        stack<int> s1,s2;
        vector<int>ls(n),rs(n);
        int i;
        long s=0;
        for (i=0;i<n;i++) {
            rs[i]=n-i-1; //if no next smaller element found on right than curr element 
            ls[i]=i; // if no next smaller element found on left of curr element
        }
        for(i=0;i<n;i++){
            while(!s1.empty() && arr[s1.top()]>arr[i]){
                rs[s1.top()]=i-s1.top()-1;//we calulate all possible subarrays on right
                s1.pop();                 //starting from arr[s1/top()] until we found next smaller element. that is a[i] and we found number of elements btw s.top to i(next samller element.)
            }                            
            s1.push(i); //keep checking possible subarrays for every element.
        }
        for(i=n-1;i>=0;i--){
            while(!s2.empty() && arr[s2.top()]>=arr[i]){
                ls[s2.top()]=s2.top()-i-1; //doing same as above this time in left side 
                s2.pop(); //so here to find no of possible elements that is greater than 
            }  // curr element until we encounter with next smaller on left we cal by
             // s2.top-i-1;
            s2.push(i); //pushing elements to stack.
        }
        for(i=0;i<n;i++){
            s+=(long)(ls[i]+1)*(rs[i]+1)*arr[i]; //calualting all possible answers  for every element. 
            s%=mod;
        }
        return s;
    }
