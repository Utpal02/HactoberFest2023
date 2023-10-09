class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) 
        return 0; 
        int res = 0;
        stack<int> path;   
        for(int i=0; i<height.size(); i++) {
            while(!path.empty() && height[i] > height[path.top()]) {
                int concaveIdx = path.top();
                path.pop();
                
                if(path.empty()) break; // no left side
                int leftIdx = path.top();
                // get a left side
                int concaveWidth = i - leftIdx - 1;
                int rainDepth = min(height[i], height[leftIdx]) - height[concaveIdx];
                res += rainDepth*concaveWidth;
            }
            path.push(i);
        }
        return res;
    }
};
