class Solution {
public:
    bool dfs(vector<int>& arr, int i)
    {
        if(i>=arr.size() || i<0) return false ;
        if(arr[i]==-1) return false;
        if(arr[i]==0) return true;
        int temp=arr[i];
        arr[i]=-1;
        bool ans=dfs(arr,temp+i) || dfs(arr,i-temp); 
        arr[i]=temp;
        return ans;
    }
    bool canReach(vector<int>& arr, int start) {
         bool val=dfs(arr,start);
         return val;
    }
};