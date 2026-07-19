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
ListNode* merge2(ListNode* list1, ListNode* list2) {
        
        ListNode* dummyNode = new ListNode(-1);
        
        
        ListNode* temp = dummyNode;

       
        while (list1 != NULL && list2 != NULL) {
           
            if (list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            
            temp = temp->next;
        }
        if (list1 != nullptr) {
            temp->next = list1;
        } else {
            temp->next = list2;
        }

        // Return head of merged list
        return dummyNode->next;
    }
ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* sortList(ListNode* head) {
        if(head==NULL||head->next==NULL)
        {
            return head;
        }
       ListNode* middle=findMiddle(head);
       ListNode* lefthead=head;
       ListNode* righthead=middle->next;
       middle->next=NULL;
       lefthead=sortList(lefthead);
       righthead=sortList(righthead);
      return merge2(lefthead,righthead);
    }
};