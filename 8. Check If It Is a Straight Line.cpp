/*

You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. 
Check if these points make a straight line in the XY plane.

Example 1:
Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true

Example 2:
Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false

*/

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) 
    {
        int n = coordinates.size();
        
        //if there are 2 or less points, they will be on a straight line
        if(n<=2)
            return true;
        
        //calculating slope m = y2-y1/x2-x1
        float y2 = coordinates[1][1];
        float y1 = coordinates[0][1];
        float x2 = coordinates[1][0];
        float x1 = coordinates[0][0];
            
        float m = (y2-y1) / (x2-x1);
        
        //check if slope is same for all points
        for(int i=2;i<n-1;i++)
        {   
            if( (coordinates[i+1][0]-coordinates[i][0]) ==0 ) //divide by zero error
                continue;
            
            float new_slope = ( (coordinates[i+1][1]-coordinates[i][1]) / (coordinates[i+1][0]-coordinates[i][0]) );
            if( new_slope != m  )
                return false;
        }
        
    return true;    
    }
};
