//Write Top-Down approach for Best Time to Buy and Sell Stock
class Solution {
public:
    
    int rec(int idx,bool fg,vector<int>& pr,vector<vector<int> >& dp){
        if(idx==pr.size()){
            return 0;
        }
        
        if(dp[idx][fg]!=-1){
            return dp[idx][fg];
        }
        
        if(!fg){
            int opt = rec(idx+1,1,pr,dp) - pr[idx];
            int opt2 = rec(idx+1,0,pr,dp);
            return dp[idx][fg] = max(opt,opt2);
        }
        else{
            int opt = pr[idx];
            int opt2 = rec(idx+1,1,pr,dp);
            return dp[idx][fg] = max(opt,opt2);
        }
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int> > dp(n,vector<int>(2,-1));
        
        int ans = rec(0,0,prices,dp);
        
        return ans;
    }
};