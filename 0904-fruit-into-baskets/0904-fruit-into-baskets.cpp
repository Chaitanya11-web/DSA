class Solution {
public:
    int totalFruit(vector<int>& fruits) {
      int n=fruits.size();
      int cnt=0;
      int k=2;
      int maxLen=INT_MIN;
      unordered_map<int,int>map1;
      int i=0;
      int j=0;
      while(j<n){
map1[fruits[j]]++;


while(map1.size()>k && i<n){
map1[fruits[i]]--;
if(map1[fruits[i]]==0){
map1.erase(fruits[i]);
}
i++;

    


}

cnt=j-i+1;
    maxLen=max(cnt,maxLen);

        j++;
      }
      return maxLen; 
    }
};