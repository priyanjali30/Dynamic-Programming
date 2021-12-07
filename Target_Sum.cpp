class Solution {
    
public:
    int findTargetSumWays(vector<int>& arr, int sum) {
        int N = arr.size();
        int SUM = 0;
        for(int i=0; i<N; i++)
        {
            SUM+=arr[i];
        }
   
        if(sum>SUM || (SUM+sum)%2!=0 || (SUM+sum)<0)
        return 0;
        int s = (sum+SUM)/2;
        
        int t[N+1][s+1];
        for(int j=0;j<=s;j++)
        {
            t[0][j]=0;
        }
        for(int i=0;i<=N;i++)
        {
           t[i][0]=1;
           
        }
        
        
        for(int i=1;i<=N;i++)
        {
            for(int j=0;j<=s;j++)
            {
               if(arr[i-1]<=j)
               {
                   t[i][j]=t[i-1][j-arr[i-1]] + t[i-1][j];
               }
               else if(arr[i-1]>j)
               {
                   t[i][j]=t[i-1][j];
               }
                
            }
        }
        return t[N][s];
        
       
    }
   
};
