class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();

        for (int i = 0; i < size && n > 0; i++) {
            // Check if current spot is empty
            if (flowerbed[i] == 0) {

                // Check left and right neighbors
                int left = (i == 0) ? 0 : flowerbed[i - 1];
                int right = (i == size - 1) ? 0 : flowerbed[i + 1];

                // If both neighbors are empty, plant a flower
                if (left == 0 && right == 0) {
                    flowerbed[i] = 1;
                    n--;
                }
            }
        }

        return n == 0;
    }
};
