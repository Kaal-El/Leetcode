class Solution {

public:
    int maxPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        
        // Basic Check
        if(n<3)
        return n;

        //Setting Variables
        int ans = 2;
        double slope;

        for(int i = 0 ; i<n-1 ; i++)
        {
            unordered_map< double , int > mp;
            for(int j = i+1 ; j<n ; j++)
            {
                int x2 = points[i][0], x1 = points[j][0]; 
                int y2 = points[i][1], y1 = points[j][1]; 
                
                // If Slope is Infinte We let Slope as INT_MAX because (You can think of it)
                   if(x2 == x1)
                   {  
                      slope = INT_MAX;
                       mp[slope]++;
                   }
                // Else we calculate slope and  increase its count
                  else
                   {
                    slope = (1.0) * (y2-y1) / (x2-x1);
                     mp[slope]++;

                   }          
                //    we store the max frequency for that slope 
                // and + 1 is because we need to count ith coordinate also           
                     ans = max(ans, mp[slope]+1);
                
            }
        }
        

        return ans;
    }

    //Hope You Liked it , Upvote is appreciated 
};