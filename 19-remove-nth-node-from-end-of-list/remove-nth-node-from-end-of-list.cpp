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
 // 1. DELETE the custom "class Node" definition from your file.
// LeetCode already defines ListNode for you.

class Solution {
public:
    

    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head); // Changed to Node
       ListNode* slow = dummy;
        ListNode* fast = dummy;
        
        for(int i = 0; i < n; i++) {
            fast = fast->next;
        }
        
        while(fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        if(fast==NULL)
        {
            return head->next;
        }
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;
        
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};