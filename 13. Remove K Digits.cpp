/*

Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.

Example 1:
Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

Example 2:
Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.

Example 3:
Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.

*/

class Solution {
public:
    string removeKdigits(string num, int k) 
    {
        int n=num.size();
        if(k>=n) return "0";
        
        int i=0;
        while( (i<num.size()-1) && (k>0) )
        {
            if(num[i]>num[i+1])
            {
                num.erase(i, 1); 
                k--;
                if(i!=0)
                    i--;
            }
            else
                i++;
        }
        
        //if we have traversed the string and still k>0, that means there are repeated same digits
        //Ex: "1111111" . So we remove k digits from end.
        if(k!=0)
        {
            int l = num.size()-k;
            num.erase(num.begin()+l, num.end());
        }
        
        //removing leading zeros if any
        for(int i=0;i<num.size();i++)
        {
            if(num[i]!='0')
                return num.substr(i);
        }
        
    return "0";
    }
};
