class Solution {
public:
    bool canEat(int k, vector<int>& piles, int h) {
        long long time = 0;
        for (int p : piles) {
            time += (p + k - 1) / k;   // ceil(p / k)
        }
        return time <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (canEat(mid, piles, h)) {
                r = mid;        // keep mid
            } else {
                l = mid + 1;
            }
        }
        return l;   // or r (same)
    }
};
