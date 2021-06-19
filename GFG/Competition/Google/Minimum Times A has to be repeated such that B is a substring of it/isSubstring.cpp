
class Solution {
  public:
    // Function to check if A is a substr of B
    bool isSubstr(string B, string A)
    {
        int M = B.length();
        int N = A.length();
        // Check for the substring
        //  we only need to check whether some 
        // index 0 or 1 or ... length(A) -1 of string A starts with B
        for (int i = 0; i <= N - M; i++) {
            int j;
            for (j = 0; j < M; j++) {
                if (A[i + j] != B[j])
                    break;
            }
            if (j == M)
                return true;
        }
        return false;
    }
    
    // This function returns how many times we have to repeat A such that
    // B is a substr of A
    // We only need to check if B is a substr of A (until len(A) > len(B)) and after that 
    // A+A.
    int minRepeats(string A, string B) {
        // code here
        int res = 1;   // Stores the minimum number of repetition
        string S = A;  // Stores the repeated string
        // To make the len(A) > len(B) and increment the repetition in
        // every iteration
        while (S.size() < B.size()) {
            S += A;
            res++;
        }
        // Call the isSubstr() to check for substring
        // Return ans
        if(isSubstr(B, S))
            return res;
        // Call the isSubstr() again with S added with A
        // to check for substring
        // Return ans+1
        if(isSubstr(B, S+A))
            return res + 1;
            
        return -1;
    }
};