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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int count = 0;
        ListNode* temp = head;

        // Count the number of nodes
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        // If the head node is to be deleted
        if (count == n) {
            return head->next;
        }

        // Find the previous node of the node to delete
        int pos = count - n;
        temp = head;

        for (int i = 1; i < pos; i++) {
            temp = temp->next;
        }

        // Delete the node
        temp->next = temp->next->next;

        return head;
    }
};