class Solution {
public:
    int totalFruit(vector<int>& fruits) {
       unordered_map<int,int>map1;
        unordered_map<int,int>map2;
        int maxLen=INT_MIN;
        int k=2;
        int cnt1=0;
       // int cnt2=0;
        int n=fruits.size();
        int i=0;
        int j=0;
        while(j<n){
            map1[fruits[j]]++;
            if(map1.size()<=k){
cnt1=j-i+1;
maxLen=max(maxLen,cnt1);
            }
            else{
                while(map1.size()>k && i<n){
                    map1[fruits[i]]--;
                     if(map1[fruits[i]]==0){
                        map1.erase(fruits[i]);
                    }
                    i++;
                }
                 if(map1.size()<=k){
cnt1=j-i+1;
maxLen=max(maxLen,cnt1);
            }
            }
            j++;
        }
       
        return maxLen;
    }
};