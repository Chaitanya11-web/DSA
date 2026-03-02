class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int>res;
        int el1=0;
        int el2=0;
        int count1=0;
        int count2=0;
        for(int i=0;i<n;i++){
            if(el1==nums[i]){
                count1++;
            }
            else if(el2==nums[i]){
                count2++;
            }
            else if(count1==0){
                el1=nums[i];
                count1=1;
            }
            else if(count2==0){
                el2=nums[i];
                count2=1;
            }
            else{
                count1--;
                count2--;
            }
        }
        count1=0;
        count2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==el1){
count1++;
            }
            else if(nums[i]==el2){
                count2++;
            }
           
        }
         if(count1>n/3){
                res.push_back(el1);
            }
            if(count2>n/3){
                res.push_back(el2);
            }
        return res;
    }
};