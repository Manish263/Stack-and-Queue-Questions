Given an integer array Arr of size N. For each element in the array, check whether the right adjacent element (on the next immediate position) of the array is smaller. If next element is smaller, update the current index to that element. If not, then  -1.

Example 1:

Input:
N = 5
Arr[] = {4, 2, 1, 5, 3}
Output:
2 1 -1 3 -1

ANS :
     	void immediateSmaller(vector<int>&a, int n) {
	      int i;
    	  for(i=0;i<n;i++){
    	     if((i+1<n) && a[i]>a[i+1]) a[i]=a[i+1];
    	     else a[i]=-1;
    	  }
	}
