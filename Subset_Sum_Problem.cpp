1. Memoization //TLE
class Solution{
    int t[101][10001];
public:
    bool isSubsetSum(int N, int arr[], int sum){
        // code here 
        memset(t,-1, sizeof(t));
        if(sum==0)
        {
            return 1;
        }
        if(N==0)
        {
            return 0;
        }
        if(t[N][sum]!=-1)
        {
            return t[N][sum];
        }
        
        if(arr[N-1]<=sum)
        {
            return t[N][sum]= isSubsetSum(N-1, arr, sum) || isSubsetSum(N-1, arr, sum-arr[N-1]);
        }
        else
        {
            return t[N][sum]= isSubsetSum(N-1, arr, sum);
        }
        
    }
};

2. Tabulation --> WORK PERFECTLY

class Solution{   
public:

    bool isSubsetSum(int N, int arr[], int sum){
        // code here 
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
