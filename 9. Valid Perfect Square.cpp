/*

Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:
Input: 16
Output: true

Example 2:
Input: 14
Output: false

*/

class Solution {
public:
    bool isPerfectSquare(int num) 
    {
        if(num==0||num==1)
            return true;
        
        long long int low=0;
        long long int high=num/2;
                
        while(low<=high)
        {
            long long int mid = (low+high)/2;
            
            if(mid*mid < num)
                low=mid+1;
            
            else if(mid*mid > num)
                high=mid-1;
            
            else if(mid*mid==num)
                return true;    
        }
    return false;
    }
};
