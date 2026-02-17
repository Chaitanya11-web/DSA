class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        int n=arr.size();
        vector<int>res=arr;
sort(res.begin(),res.end());
unordered_map<int,int>map1;
int index=1;
for(int i=0;i<n;i++){
    if(map1.find(res[i])==map1.end()){
map1[res[i]]=index;
index++;
    }
    
}
for(int i=0;i<n;i++){
    if(map1.find(arr[i])!=map1.end()){
        res[i]=map1[arr[i]];
    }
}
  return res;  }
};