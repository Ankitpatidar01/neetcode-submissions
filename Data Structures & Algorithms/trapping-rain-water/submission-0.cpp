class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> a(n);
        vector<int> b(n);

        int index = 0;

        for (int i = 0; i < n; i++) {
            if (height[index] < height[i])
                index = i;

            a[i] = index;
        }

        index = n - 1;

        for (int i = n - 1; i >= 0; i--) {
            if (height[index] < height[i])
                index = i;

            b[i] = index;
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int water = min(height[a[i]], height[b[i]]) - height[i];

            ans += water;
        }

        return ans;
    }
};
