//User function Template for C


//Function to find minimum number of operations that are required 
//to make the matrix beautiful.
int findMinOpeartion(int n, int matrix[][n])
{
    // Finding the maximum sum of ROWi and COLi
    int maxSum = 0;
    int totalSum = 0;
    for (int i = 0; i < n; i++){
        int rowSum = 0, colSum = 0;
        for (int j = 0; j < n; j++){
            rowSum += matrix[i][j];
            colSum += matrix[j][i];
        }
        if (maxSum < rowSum)
            maxSum = rowSum;
            
        if (maxSum < colSum)
            maxSum = colSum;
        
        totalSum += rowSum;
    }
    return maxSum*n - totalSum;
}