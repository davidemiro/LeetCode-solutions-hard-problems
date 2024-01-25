class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> right(n);
        vector<int> left(n);
        int sum = 0;
        int l,s;
        
        left[0] = height[0];
        for(int i = 1; i < n; i++)
            left[i] = height[i] > left[i - 1] ? height[i] : left[i - 1];
        
        right[n - 1] = height[n - 1];
        for(int i = n - 2; i >= 0; i--)
            right[i] = height[i] > right[i + 1] ? height[i] : right[i + 1];
        
        for(int i = 1; i < n - 1; i++){
            l = min(left[i],right[i]);
            sum += (l - height[i]);
                
            
        }
        return sum;
        
        
    }
};