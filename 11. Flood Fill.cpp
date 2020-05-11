/*

An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" 
the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color 
as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), 
and so on. Replace the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image.

Example 1:
Input: 
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2

Output: [[2,2,2],[2,2,0],[2,0,1]]

Explanation: 
From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
by a path of the same color as the starting pixel are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected
to the starting pixel.

*/

class Solution {
public:
    
    void colorize(vector<vector<int>>& image, vector<vector<int>>& newImage, int x, int y, int origColor, int newColor)
    {
        if(image[x][y] != -1 && newImage[x][y] == origColor)
        {
            image[x][y] = -1;
            newImage[x][y] = newColor;

            if(x>0)
                colorize(image, newImage, x-1, y, origColor, newColor);

            if(y>0)
                colorize(image, newImage, x, y-1, origColor, newColor);

            if(x<image.size()-1)
                colorize(image, newImage, x+1, y, origColor, newColor);

            if(y<image[0].size()-1)
                colorize(image, newImage, x, y+1, origColor, newColor);
        }
    }
        
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        auto newImage(image);
        int x=sr;
        int y=sc;
        int origColor = image[x][y];
        colorize(image,newImage, x, y, origColor, newColor);
    return newImage;
    }
};
