class Solution {
public:
    
    /* Using Binomial Coefficient Approach
       Formula Cn = (1/n+1)(2n C n)
       For example 5 C 2 is:
            5! / (3! * 2!)
       So Here n C k will be n!/k!(n-k)!
       
       Time Complexity is O(n)
    */
    unsigned long int binomialCoeff(unsigned int n, unsigned int k) {
        unsigned long int res = 1;
        
        if (k > n - k)
            k = n - k;
        // Calculate value of [n*(n-1)*---*(n-k+1)] / [k*(k-1)*---*1]
        for (int i = 0; i < k; i++) {
            res *= n - i;
            res /= i + 1;
        }
        
        return res;
    }
    
    unsigned long int catalan(int n) {
        // Calculate the value of 2nCn
        // See this: https://study.com/academy/lesson/catalan-numbers-formula-applications-example.html, for more explanation
        unsigned long int res = binomialCoeff(2*n, n);
        // Returning 2nCn/n+1
        return res/(n+1);
    }
    /*  Dynamic Programming Approach 
        Here the formula is 
        catalan(n) is sum of
        catalan(i)*catalan(n-i-1)
        Time Complexity: O(n2)
    */
    
    unsigned long int catalanDP(int n) {
        unsigned long int res[n+1];
        res[0] = res[1] = 1;
        
        for (int i = 2; i <= n; ++i) {
            res[i] = 0;
            for (int j = 0; j < i; ++j) {
                res[i] += res[j] * res[i-j-1]; 
            }
        }
        
        return res[n];
    }
    /* This is a mathematical problem, for the approach we can use the 
       Catalan Number sequence to calculate how many unique BST can be formed
       for the given n number of nodes */
    int numTrees(int n) {
        // Base case
        if (n <= 1)
            return 1;
        // unsigned long int count = catalan(n);
        unsigned long int count = catalanDP(n);
        
        return count;
    }
};