class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sums(n - k + 1, 0), left(n - k + 1, 0), right(n - k + 1, 0), ans;
        for (int i = 0, sum = 0; i < n; i++) {
            sum += nums[i];
            if (i >= k) {
                sum -= nums[i - k];
            }
            if (i >= k - 1) {
                sums[i - k + 1] = sum;
            }
        }
        for (int i = 0, j = 0; i < n - k + 1; i++) {
            if (sums[i] > sums[j]) {
                j = i;
            }
            left[i] = j;
        }
        for (int i = n - k, j = n - k; i >= 0; i--) {
            if (sums[i] >= sums[j]) {
                j = i;
            }
            right[i] = j;
        }
        for (int m = k, sum = 0; m < n - 2 * k + 1; m++) {
            if (sums[left[m - k]] + sums[m] + sums[right[m + k]] > sum) {
                ans = {left[m - k], m, right[m + k]};
                sum = sums[left[m - k]] + sums[m] + sums[right[m + k]];
            }
        }
        return ans;
    }
};