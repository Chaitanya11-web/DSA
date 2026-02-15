class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        unordered_map<int,int>map1;
        unordered_map<int,int>map2;
        int cnt1=0;
        int cnt2=0;
        int n=nums.size();
        int i=0;
        int j=0;
        while(j<n){
            map1[nums[j]]++;
            if(map1.size()<=k){
cnt1+=j-i+1;
            }
            else{
                while(map1.size()>k && i<n){
                    map1[nums[i]]--;
                     if(map1[nums[i]]==0){
                        map1.erase(nums[i]);
                    }
                    i++;
                }
                 if(map1.size()<=k){
cnt1+=j-i+1;
            }
            }
            j++;
        }
        i=0;
        j=0;
        k=k-1;
        while(j<n){
            map2[nums[j]]++;
            if(map2.size()<=k){
cnt2+=j-i+1;
            }
            else{
                while(map2.size()>k && i<n){
                    map2[nums[i]]--;
                    if(map2[nums[i]]==0){
                        map2.erase(nums[i]);
                    }
                    i++;
                }
                 if(map2.size()<=k){
cnt2+=j-i+1;
            }
            }
            j++;
        }
        return cnt1-cnt2;;
    }
};