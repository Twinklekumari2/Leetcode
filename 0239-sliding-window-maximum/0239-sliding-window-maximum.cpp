class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> pq;
        vector<int> ans;
        for(int i = 0; i < k; i++){
            int num = nums[i];
            pq.push({num, i});
        }
        ans.push_back(pq.top().first);
        for(int i = k; i < n; i++){
            int num = nums[i];
            while(!pq.empty() && (pq.top().second + k) <= i){
                cout << "deleted " << pq.top().first << " at " << i << "\n";
                pq.pop();
            }

            pq.push({num, i});
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};