class Solution {
public:
    vector<int> prevSmaller(vector<int>& heights){
        int n = heights.size();
        vector<int> prev(n);
        stack<int> st;
        st.push(-1);

        for(int i = 0; i < n; i++){
            int num = heights[i];

            while(st.top() != -1 && num <= heights[st.top()]){
                st.pop();
            }
            prev[i] = st.top();
            st.push(i);
        }
        return prev;
    }
    vector<int> nextSmaller(vector<int>& heights){
        int n = heights.size();
        vector<int> next(n);
        stack<int> st;
        st.push(-1);

        for(int i = n-1; i >= 0; i--){
            int num = heights[i];

            while(st.top() != -1 && num <= heights[st.top()]){
                st.pop();
            }
            next[i] = st.top() == -1 ? n : st.top();
            st.push(i);
        }
        return next;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> prev = prevSmaller(heights);
        vector<int> next = nextSmaller(heights);

        int ans = INT_MIN;

        for(int i = 0; i < n; i++){
            int height = heights[i];
            int width = next[i]-prev[i]-1;

            ans = max(ans, height*width);
        }
        return ans;

    }
}; 