class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
     int num=1;
     int n=arr.size();
     int i=0;
     while(i<n){
        if(arr[i]!=num){
            k--;
            if(k==0)return num;
        }
        else{
            i++;
        }
        num++;
     } 
     return num+(k-1);  
    }
};