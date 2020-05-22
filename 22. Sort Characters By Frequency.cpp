/*

Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.

Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.

*/

class Solution {
public:
    
    static bool cmp(pair<char,int> &p1, pair<char, int> &p2) 
    { 
        // If frequencies are same, compare 
        // values 
        if (p1.second == p2.second) 
            return p1.first < p2.first; 
        return p1.second > p2.second; 
    } 
    
    string frequencySort(string s) 
    {
        map<char,int>freq;
        vector<pair<char,int>>v;
        string res="";
        
        for(auto &x:s)
            freq[x]++;
        
        for(auto &i : freq)
            v.push_back({i.first, i.second});
        
        sort(v.begin(),v.end(), cmp);
        
        for(auto &x:v)
        {
            // cout<<x.first<<" "<<x.second<<endl;
            int k = x.second;
            while(k--)
            {
                res+=x.first;
            }
        }
        
        
    return res;
    }
};
