/*
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.

Note: You may assume the string contain only lowercase letters.
*/
class Solution {
public:
    int firstUniqChar(string s) 
    {
        vector<int>v(26);
        int n = s.size();
        
        for(int i=0;i<n;i++)
            v[s[i]-'a']++;
        
        for(int i=0;i<n;i++)
        {
            if(v[s[i]-'a']==1)
                return i;
        }

    return -1;   
    }
};

// Algorithm/Data Structure: Vectors 
// TC: O(n) 	n -> string size
// SC: O(m)		m -> vector size
