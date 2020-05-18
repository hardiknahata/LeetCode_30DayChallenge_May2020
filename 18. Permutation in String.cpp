/*

Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, 
one of the first string's permutations is the substring of the second string.

Example 1:
Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:
Input:s1= "ab" s2 = "eidboaoo"
Output: False

*/

class Solution {
public:
    
    bool arr_comp(int a1[], int a2[])
    {
        for(int i=0;i<26;i++)
        {
            if(a1[i]!=a2[i])
                return false;
        }
    return true;
    }
    
    
    bool checkInclusion(string s1, string s2) 
    {
        //s1 is smaller string
        //s2 is larger string
        
        int n1 = s1.length();
        int n2 = s2.length();
        
        if(n1>n2)
            return false;
        
        int a1[26]={0};
        int a2[26]={0};
        
        for(int i=0;i<n1;i++)
        {
            a1[s1[i]-'a']++;
            a2[s2[i]-'a']++;
        }
        
        for(int i=n1;i<n2;i++)
        {
            if(arr_comp(a1,a2))
                return true;
            
            a2[s2[i]-'a']++;
            a2[s2[i-n1]-'a']--;
        }
        
        if(arr_comp(a1,a2))
                return true;
        
    return false;
    }
};
