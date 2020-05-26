/*

Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.

Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.

Note: The length of the given binary array will not exceed 50,000.

*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) 
    {
        unordered_map<int,int>map;
        map.insert({0,-1});
        
        int sum=0;
        int maxlen=0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                sum-=1;
            else
                sum+=1;
            
            auto it = map.find(sum); 
            if(it==map.end())
                map.insert({sum,i});
            else
            {
                maxlen = max(maxlen, i-(it->second));
            }
       }
    return maxlen;
    }
};
