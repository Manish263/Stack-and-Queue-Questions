A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find if there is a celebrity in the party or not.
A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.
Note: Follow 0 based indexing.
Follow Up: Can you optimize it to O(N)
 

Example 1:

Input:
N = 3
M[][] = {{0 1 0},
         {0 0 0}, 
         {0 1 0}}
Output: 1
Explanation: 0th and 2nd person both
know 1. Therefore, 1 is the celebrity. 
  
  ANS: 
O(N)
    int celebrity(vector<vector<int> >& m, int n) 
    {
       int i,c=0;
        for (i=0;i<n;i++){
            if(m[c][i]==1){
                c=i; //we made assumption that this is our celeb and below for loop 
                // conditions used to clear that it is true or not.
            }
        }
        for(i=0;i<n;i++){
            if(i!=c && (m[c][i]==1 or m[i][c]==0)) return -1;
        }              //m[c][i] means celeb knows any fan 
                       //m[i][c] means fan know no celeb. either one of them is true
                       //that means ans is -1;
        return c; //this much people know celeb.
    }

O(N^2)
   int celebrity(vector<vector<int> >& m, int n) 
    {
       int i,j;
       int celeb[n]={0};
       int fan[n]={0};
        for (i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(m[i][j]==1){
                    celeb[j]++; //celebrity-> everyone knows him.
                    fan[i]++; //fan-> no one knows him.
                }
            }
        }
        for(i=0;i<n;i++){
            if(celeb[i]==n-1 && fan[i]==0)
            return i;
        }
        return -1;
    }
