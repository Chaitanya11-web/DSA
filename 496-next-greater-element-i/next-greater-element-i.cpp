class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
      
      vector<int>ans;
      int n1=nums1.size();
      int n2=nums2.size();
      unordered_map<int,int>map1;
     int i=0;
     while(i<n2){
        for(int j=i+1;j<n2;j++){
          
            if(nums2[j]>nums2[i]){
                map1[nums2[i]]=nums2[j];
               
                break;
            }
           
        }
         i++;
     }
     for(int j=0;j<n1;j++){
        if(map1.find(nums1[j])!=map1.end()){
ans.push_back(map1[nums1[j]]);
        }
        else{
            ans.push_back(-1);
        }
     }
     return ans;
    }
};