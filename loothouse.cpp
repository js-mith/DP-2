#include <iostream>
using namespace std;

int maxMoneyLooted(int *arr, int n)
{
	//Write your code here
	 int *output = new int[n];
    output[0] = arr[0];
    output[1] = max(arr[0], arr[1]);
    for (int i = 2; i < n; i++)
        output[i] = max(output[i - 1], output[i - 2] + arr[i]);
    return output[n - 1];
}

int longestIncreasingSubsequence(int* arr, int n) {
	// Write your code here
	 int *output = new int[n];
    output[0] = 1;
    for (int i = 1; i < n; i++)
    {
        int ans = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] < arr[i])
                ans = max(output[j], ans);
        }
        output[i] = ans + 1;
    }
    int res = 0;
    for (int i = 0; i < n; i++)
        res = max(output[i], res);
    return res;
}

int main()
{
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cout << maxMoneyLooted(arr, n);
     cout << longestIncreasingSubsequence(arr, n);

	delete[] arr;
}