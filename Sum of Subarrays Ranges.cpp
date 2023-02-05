You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.

Return the sum of all subarray ranges of nums.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,2,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0 
[2], range = 2 - 2 = 0
[3], range = 3 - 3 = 0
[1,2], range = 2 - 1 = 1
[2,3], range = 3 - 2 = 1
[1,2,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.
  
  ANS: 
     O(N^2)
         long long subArrayRanges(vector<int>& a) {
        int n=a.size();
        long long i,j,mx,mn,s=0;
        for (i=0;i<n;i++) {
            mx=a[i],mn=a[i];
            for (j=i+1;j<n;j++){
                if(a[j]>mx) {
                    mx=a[j];
                }             //checking for all subarrays mx elements for every in a[i]
                else if(a[j]<mn){
                    mn=a[j];
                }     //checking for all subarrays mn elements for every element in a[i]
            s+=(mx-mn); //this is ans
            }
        }
        return s;
    }
