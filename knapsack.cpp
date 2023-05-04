#include<iostream>
using namespace std;

int knapsack(int *weight , int *value , int n , int maxweight){
    //base case
    if(n == 0 || maxweight == 0){
        return 0;
    }

    if(weight[0] > maxweight){
        return knapsack(weight+1 , value+1 , n-1 , maxweight);
    }

    int x = knapsack(weight+1 , value+1 , n-1 , maxweight-weight[0])+value[0];
    int y = knapsack(weight+1 ,value+1 , n-1 , maxweight);

    return max(x,y);
}
int knapsack_dp(int *weights, int *values, int n, int maxWeight)
{
	
	 int dp[maxWeight+1]={0};
    
    for(int i=0;i<n;i++){
        
        for(int j=maxWeight;j>=weights[i];j--){
            
            dp[j]=max(dp[j],values[i]+dp[j-weights[i]]);
        }
    }
    return dp[maxWeight];
}

int main() {
     int n ;
     int weight []= {5,1,8,9,2};
     int value [] = {4,10,2,3,1};
     int w = 15;

     cout << knapsack(weight ,value , 5 , w) << endl;
     cout << knapsack_dp(weight , value , 5 , w) << endl;
     return 0;
}