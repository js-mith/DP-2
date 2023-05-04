#include<iostream>
using namespace std;
#include<limits.h>

int mincostpath(int **input , int m , int n , int i , int j){
    if(i == m-1 && j == n-1){
        return input[i][j];
    }

    if(i >= m || j >= n){
        return INT_MAX;
    }

    int x = mincostpath(input , m ,n , i , j+1);
    int y = mincostpath(input , m ,n , i+1 , j+1);
    int z = mincostpath(input , m ,n , i+1 , j);

    int ans = min(x,min(y,z)) + input[i][j];
    return ans;
}

int mincostpath(int **input , int m , int n){
    return mincostpath(input , m ,n , 0 ,0);
}

int minCostPath_dp(int **input, int m, int n)
{
	//Write your code here
	 int **output = new int *[m];
    for (int i = 0; i < m; i++)
        output[i] = new int[n];

    output[m - 1][n - 1] = input[m - 1][n - 1];

    for (int i = n - 2; i >= 0; i--)
        output[m - 1][i] = output[m - 1][i + 1] + input[m - 1][i];

    for (int i = m - 2; i >= 0; i--)
        output[i][n - 1] = output[i + 1][n - 1] + input[i][n - 1];

    for (int i = m - 2; i >= 0; i--)
        for (int j = n - 2; j >= 0; j--)
            output[i][j] = min(output[i + 1][j], min(output[i + 1][j + 1], output[i][j + 1])) + input[i][j];

    return output[0][0];
}

int main() {
     int m , n;
     cin >> m >> n;

     int ** input = new int*[m];
     for(int i = 0; i< m ; i++){
        input[i] = new int[n];
        for(int j =0 ; j < n ;j++){
            cin >> input[i][j];
        }
     }
     cout << mincostpath(input,m,n) << endl;
     cout <<minCostPath_dp(input,m,n) << endl;
     return 0;
}