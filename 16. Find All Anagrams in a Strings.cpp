/*

Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:
Input:
s: "cbaebabacd" p: "abc"
Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

Example 2:
Input:
s: "abab" p: "ab"
Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".

*/

class Solution {
public:
    
    bool compare_arr(int a1[], int a2[]) //function to compare arrays
    {
        for(int i=0;i<26;i++)
        {
            if(a1[i]!=a2[i])
                return false;
        }
    return true;
    }
    
    vector<int> findAnagrams(string s, string p) 
    {
        int n = s.length(); //string length
        int m = p.length(); //pattern length
        vector<int>res; //vector to store answer indexes
        
        if(n==0||n<m) //if string is empty OR if n<m return empty vector
            return res;
        
        int sw_count[26]={0}; //string window count array
        int pat_count[26]={0}; //pattern count array
              
        
        for(int i=0;i<m;i++) //loading arrays with count 
        {
            pat_count[p[i]-'a']++;
            sw_count[s[i]-'a']++;
        }
        
        int i;
        for(i=m;i<n;i++)
        {
            if(compare_arr(pat_count,sw_count))
                res.push_back(i-m);
            
            sw_count[s[i]-'a']++; //adding count of next character
            
            sw_count[s[i-m]-'a']--; //removing count of first character of last string
        }
        
        if(compare_arr(pat_count,sw_count)) //comparison for last substring
            res.push_back(i-m);
        
    return res;
    }
};
