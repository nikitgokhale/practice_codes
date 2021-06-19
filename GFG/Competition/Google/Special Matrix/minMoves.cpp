//Back-end function Template for C++

class Solution{
  public:
    int minMoves(int N, vector<vector<int>>matrix){
        // code here
        vector<int> v;
        int ans = INT_MAX;
        // Pushing the trangular numbers into the vector
        for (int i = 0;  i < 50; i++) {
            int x = (i*(i+1))/2;
            v.push_back(x);
        }
        // Check for the row
        for (int i = 0; i < N; i++) {
            int c = 0;
            for (int j = 0; j < N; j++) {
                int x = upper_bound(v.begin(), v.end(), matrix[i][j]) - v.begin();
                c += min(v[x]-matrix[i][j], matrix[i][j]-v[x-1]);
            }
            ans = min(ans, c);
        }
        // Check for the columns
        for (int j = 0; j < N; j++) {
            int c = 0;
            for (int i = 0; i < N; i++) {
                int x = upper_bound(v.begin(), v.end(), matrix[i][j]) - v.begin();
                c += min(v[x]-matrix[i][j], matrix[i][j]-v[x-1]);
            }
            ans = min(ans, c);
        }
        return ans;
    }
};