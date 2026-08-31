/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
      if (!head || !head->next || !head->next->next) {
            return {-1, -1};
        }

        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next = curr->next;

        int first_critical = -1;
        int prev_critical = -1;
        int min_dist = INT_MAX;
        int curr_idx = 2; 

        while (next != nullptr) {
            bool is_maxima = (curr->val > prev->val && curr->val > next->val);
            bool is_minima = (curr->val < prev->val && curr->val < next->val);

            if (is_maxima || is_minima) {
                if (first_critical == -1) {
                    first_critical = curr_idx;
                } else {
                    min_dist = min(min_dist, curr_idx - prev_critical);
                }
                prev_critical = curr_idx;
            }

            
            prev = curr;
            curr = next;
            next = next->next;
            curr_idx++;
        }

       
        if (first_critical == -1 || prev_critical == first_critical) {
            return {-1, -1};
        }

        int max_dist = prev_critical - first_critical;
        return {min_dist, max_dist};  
    }
};