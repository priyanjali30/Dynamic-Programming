class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int sum=0;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        if(sum%2!=0)
            return false;
        
        return subsetSum(nums,n,sum/2);
    }
    
    bool subsetSum(vector<int>arr,int N, int sum)
    {
        int t[N+1][sum+1];
        for(int j=0;j<=sum;j++)
        {
            t[0][j]=0;
        }
        for(int i=0;i<=N;i++)
        {
           t[i][0]=1;
           
        }
        
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=sum;j++)
            {
               if(arr[i-1]<=j)
               {
                   t[i][j]=t[i-1][j-arr[i-1]] || t[i-1][j];
               }
               else if(arr[i-1]>j)
               {
                   t[i][j]=t[i-1][j];
               }
                
            }
        }
        return t[N][sum];
    }
};
