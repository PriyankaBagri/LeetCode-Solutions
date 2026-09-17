class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
    vector<int> best(n, INT_MAX);

    int left = 0;
    int sum = 0;

    int answer = INT_MAX;
    int currentBest = INT_MAX;

    for (int right = 0; right < n; right++) {

        sum += arr[right];
        while (sum > target) {
            sum -= arr[left];
            left++;
        }
        if (sum == target) {

            int length = right - left + 1;
            if (left > 0 && best[left - 1] != INT_MAX) {
                answer = min(answer,
                             length + best[left - 1]);
            }
            currentBest = min(currentBest, length);
        }
        best[right] = currentBest;
    }

    return answer == INT_MAX ? -1 : answer;


    }
};