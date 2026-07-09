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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        // Dummy node to simplify list creation
        ListNode* dummy = new ListNode(0);

        // Pointer used to build the answer list
        ListNode* curr = dummy;

        // Stores carry generated during addition
        int carry = 0;

        // Continue until both lists are finished and no carry remains
        while (l1 != nullptr || l2 != nullptr || carry) {

            // Start sum with carry
            int sum = carry;

            // Add current digit from first list
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            // Add current digit from second list
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            // Update carry
            carry = sum / 10;

            // Create node with the last digit
            curr->next = new ListNode(sum % 10);

            // Move curr to the newly created node
            curr = curr->next;
        }

        // Return the actual head (skip dummy node)
        return dummy->next;
    }
};