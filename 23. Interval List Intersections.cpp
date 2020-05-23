/*

Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

(Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.  The intersection of two 
closed intervals is a set of real numbers that is either empty, or can be represented as a closed interval.  
For example, the intersection of [1, 3] and [2, 4] is [2, 3].)

Example 1:
Input: A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
Reminder: The inputs and the desired output are lists of Interval objects, and not arrays or lists.

*/

#include <algorithm>

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) 
    {
        int a_pointer=0;
        int b_pointer=0;
        vector<vector<int>>intersection; //result 
        
        while(a_pointer<A.size() && b_pointer<B.size())
        {
            int start = max(A[a_pointer][0], B[b_pointer][0]);    //finding start of interval
            int end = min(A[a_pointer][1], B[b_pointer][1]);      //finding end of interval
            
            if(start<=end)  //if start is less than end then only insert
                intersection.push_back({start,end});
            
            if(A[a_pointer][1] <= B[b_pointer][1]) //increment pointer which is pointing to lesser value
                a_pointer++;
            else
                b_pointer++;
        }
    return intersection;
    }
};
