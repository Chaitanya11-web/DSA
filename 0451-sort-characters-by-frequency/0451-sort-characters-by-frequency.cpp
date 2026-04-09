class Solution {
public:
    string frequencySort(string s) {
     int n=s.length();
     string res;
     unordered_map<char,int>map1;
     for(int i=0;i<n;i++){
        map1[s[i]]++;
     } 
vector<int>freq;
for(auto it:map1){
    freq.push_back(it.second);
}
int m=freq.size();
sort(freq.begin(),freq.end());
for(int j=m-1;j>=0;j--){
    for(auto it:map1){
        if(it.second==freq[j]){
res+=string(freq[j],it.first);
map1[it.first]=-1;
break;
        }

    }

}

return res;
    }
};