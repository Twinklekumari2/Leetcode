class Solution {
public:
    bool isValid(vector<int>& nums, int n, int k){
        long long BASE = 100003;
        long long MOD = 1000000007;
        long long P = 1;
        for(int i = 0; i < k-1; i++){
            P = (P*BASE)%MOD;
        }
        long long currentHash= 0;
        for(int i = 0; i < k; i++){
            currentHash = (currentHash*BASE + nums[i]) % MOD;
        }
        unordered_map<long long, int> freq;
        freq[currentHash] = 1;

        for(int i = k; i < n; i++){
            int outElement = nums[i-k];
            int inElement = nums[i];

            currentHash = ((currentHash - outElement*P) % MOD + MOD) % MOD;
            currentHash = (currentHash*BASE + inElement) % MOD;

            freq[currentHash]++;
        }

        for(auto x : freq){
            if(x.second == 1){
                return true;
            }
        }
        return false;
    }
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int low = 1, high = n, ans = n;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(isValid(nums, n, mid)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};