class Solution {
public:
    /* **There will be n*(n+1)/2 substring with unique characters 
        This solution uses extra space to store the last visited
        indexes of the already visited characters.
        This approach uses the Window Sliding Technique
        Refer: https://www.geeksforgeeks.org/window-sliding-technique/
        
        We scan the string from left to right and keep the track of the
        maximum length non-repeating character substring seen so far
        When we traverse the string, to know the length of the current
        window we need two indexes
        1. Ending Index (end)
        2. Starting Index (start)
        As we traverse the string, keep on updating the last seen value
        of each character
        Keep on checking if we have already seen this element or not
        If we have seen the element, move the start pointer to the postion
        after the last occurance
        
        Time Complexity: O(n)
        Space Complexity: O(n+d) n: length of the string; d = number of character
        in the input string
    */
    int lengthOfLongestSubstring(string s) {
        int maximum_length = 0;
        map<char, int> seen;
        // Start the initial point of the window at index 0
        int start = 0;
        
        for (int end = 0; end < s.length(); end++) {
            // Check of the element is not already seen
            if (seen.find(s[end]) != seen.end()) {
                // If we have seen this number, move the start pointer 
                // to the position after the last occurance
                start = max(start, seen[s[end]] + 1);
            }
            // Updating the last seen value of the character
            seen[s[end]] = end;
            maximum_length = max(maximum_length, end - start + 1);
        }
        return maximum_length;
    }
    
    /*int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            vector<bool> visited(256);
            for (int j = i; j < n; j++) {
                // If the current character is visited, break the loop
                if (visited[s[j]] == true)
                    break;
                else {
                    res = max(res, j - i + 1);
                    visited[s[j]] = true;
                }
            }
            visited[s[i]] = false;
        }
        
        return res;
    }*/
};