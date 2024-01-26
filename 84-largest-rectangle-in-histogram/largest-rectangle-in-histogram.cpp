class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> monotonic_stack;
        int max = 0;
        int h,x;
        heights.push_back(0);
        for(int i = 0; i < heights.size(); i++){
            while(!monotonic_stack.empty() && heights[monotonic_stack.top()] > heights[i]){
                h = heights[monotonic_stack.top()];
                monotonic_stack.pop();
                if(!monotonic_stack.empty()){
                    x = i - monotonic_stack.top() - 1;
                }
                else{
                    x = i;
                }
                
                h = h*x;
                max = max > h ? max : h;
                
                
                
            
            }
            
            monotonic_stack.push(i);
            
        }
        
        return max;
    
        
    }
};