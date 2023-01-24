int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int c=0,i,j;
        set<int> s(nums1.begin(),nums1.end());
        for (i=0;i<nums2.size();i++){
            if(s.find(nums2[i])!=s.end()){
                c=nums2[i]; break;
            }
            else c=-1;
        }
    
        return c;
    }
