class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n==0)return tasks.size();
     vector<int>map1(26,0);
     for(char ch:tasks){
map1[ch-'A']++;
     }   
     sort(map1.begin(),map1.end());
     int maxfreq=map1[25];
     int g=maxfreq-1;
     int idleslots=n*g;
     for(int i=24;i>=0;i--){
        idleslots-=min(map1[i],g);
     }
     if(idleslots>0){
        return tasks.size()+idleslots;
     }
     return tasks.size();
    }
};