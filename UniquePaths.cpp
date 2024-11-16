//You are present at point ‘A’ which is the top-left cell of an M X N matrix, your destination is point ‘B’, which is the bottom-right cell of the same matrix. 
//Your task is to find the total number of unique paths from point ‘A’ to point ‘B’.
//In other words, you will be given the dimensions of the matrix as integers ‘M’ and ‘N’, your task is to find the total number of unique paths from the cell MATRIX[0][0] to MATRIX['M' - 1]['N' - 1].
#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {
	vector<vector<int>>dp(m,vector<int>(n,0));
	for(int i=0;i<m;i++)
	dp[i][0]=1;
	for(int i=0;i<n;i++)
	dp[0][i]=1;
	for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
	return dp[m-1][n-1];
	// Write your code here.
}
