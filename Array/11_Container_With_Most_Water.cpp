//https://leetcode.com/problems/container-with-most-water/description/
class Solution {
public:
/*
    
    area = heigt x breadth
    So more the hight of the side better 
    More the distance beween two point more is the area that we can get

    so lets use the two pointer method 
    start = 0 and end = len(array) -1

    loop (start < end){
        Min of two is needed other wise water will overflow from the lower height site
        areaL = (end - start) x min(value(start), value(end))
        maxArea = max(maxArea, areaL)
        IF height(start) < height(end) then start += 1
        ELSE end -= 1
    }
    At the end of the loop return the maxArea

*/
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int start = 0;
        int end = height.size() -1;

        while(start < end){
            auto area_local = (end - start) * min(height[start], height[end]);
            max_area = max(max_area, area_local);
            if(height[start] < height[end]) { start += 1; }
            else { end -= 1; }
        } 
        return max_area;
    }
};