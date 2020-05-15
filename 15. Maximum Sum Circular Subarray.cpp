/*

Given a circular array C of integers represented by A, find the maximum possible sum of a non-empty subarray of C.

Here, a circular array means the end of the array connects to the beginning of the array.  (Formally, C[i] = A[i] 
when 0 <= i < A.length, and C[i+A.length] = C[i] when i >= 0.)
Also, a subarray may only include each element of the fixed buffer A at most once.  
(Formally, for a subarray C[i], C[i+1], ..., C[j], there does not exist i <= k1, k2 <= j with k1 % A.length = k2 % A.length.)

Example 1:
Input: [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3

Example 2:
Input: [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10

Example 3:
Input: [3,-1,2,-1]
Output: 4
Explanation: Subarray [2,-1,3] has maximum sum 2 + (-1) + 3 = 4

Example 4:
Input: [3,-2,2,-3]
Output: 3
Explanation: Subarray [3] and [3,-2,2] both have maximum sum 3

Example 5:
Input: [-2,-3,-1]
Output: -1
Explanation: Subarray [-1] has maximum sum -1

*/

#include<climits> 

class Solution {
public:
    //Kadene's Algo
    int kad(vector<int>a)
    {
        int max_ending_here=0;
        int max_until_now=INT_MIN;
        
        for(int i=0;i<a.size();i++)
        {
            max_ending_here+=a[i];
            
            if(max_until_now<max_ending_here)
                max_until_now=max_ending_here;
            
            if(max_ending_here<0)
                max_ending_here=0;
        }
    return max_until_now;
    }
    
    //Main Function
    int maxSubarraySumCircular(vector<int>& A) 
    {
        int k1 = kad(A); //kadene of initial array;
        int total=0;   //total sum of initial array;
        int k2 =0;      //kadene of flipped array
        int cir_sum=0; //circular sum of flipped array
            
        for(auto x:A)
            total+=x;
    
        //multiplying array elements with -1
        for(int i=0;i<A.size();i++)
            A[i]=A[i]*(-1);
        
        k2 = kad(A);
        cir_sum = total + k2;
        
        if(cir_sum>k1 && cir_sum!=0)
            return cir_sum;
        else
            return k1;
    }
};
