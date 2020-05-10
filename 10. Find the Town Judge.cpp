/*

In a town, there are N people labelled from 1 to N.  There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given trust, an array of pairs trust[i] = [a, b] representing that the person labelled a trusts the person labelled b.

If the town judge exists and can be identified, return the label of the town judge.  Otherwise, return -1.

Example 1:
Input: N = 2, trust = [[1,2]]
Output: 2

Example 2:
Input: N = 3, trust = [[1,3],[2,3]]
Output: 3

Example 3:
Input: N = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1

*/

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) 
    {
        int size = trust.size();
        if(size==1) return trust[0][1];
        if(N==1) return 1;
        
        map<int,int>m1; //stores the public data
        map<int,int>m2; //stores potential town judge data
        
        //Inserting elements in maps
        for(int i=0;i<size;i++)
        {
            m1[trust[i][0]]++;
            m2[trust[i][1]]++;
        }
        
        //Finding the Judge
        for(int i=1;i<=N;i++)
        {
            auto it1 = m1.find(i);
            
            if(it1 == m1.end())
            {                
                auto it2 = m2.find(i);
                // cout<<it2->first;
                if(it2==m2.end())
                    break;
                else if( it2->second==N-1)
                    return i;
            } 
        }
    return -1;
    }
};
