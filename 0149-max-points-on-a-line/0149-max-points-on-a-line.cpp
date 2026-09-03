class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;

        int max_points = 0;

        for (int i = 0; i < n; ++i) {
           
            unordered_map<string, int> slope_count;
            int local_max = 0;

            for (int j = i + 1; j < n; ++j) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

               
                int g = std::gcd(dx, dy);
                dx /= g;
                dy /= g;

              
                if (dx < 0) {
                    dx = -dx;
                    dy = -dy;
                } else if (dx == 0) {
                    dy = 1; 
                }

                string slope_key = to_string(dy) + "/" + std::to_string(dx);
                slope_count[slope_key]++;
                local_max = std::max(local_max, slope_count[slope_key]);
            }

           
            max_points = std::max(max_points, local_max + 1);
        }

        return max_points;
    }
};