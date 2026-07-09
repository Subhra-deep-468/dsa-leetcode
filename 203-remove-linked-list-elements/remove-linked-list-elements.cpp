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
    ListNode* removeElements(ListNode* head, int val) {

        // Create a dummy node before head
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Start from dummy
        ListNode* curr = dummy;

        while (curr->next != nullptr) {

            if (curr->next->val == val) {

                // Skip the node
                curr->next = curr->next->next;

            } else {

                // Move forward
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};