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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if (head == NULL || left == right) {
            return head;
        }

        ListNode* prev = NULL;
        ListNode* curr = head;

        // Move to the left position
        for (int i = 1; i < left; i++) {
            prev = curr;
            curr = curr->next;
        }

        ListNode* prevLeft = prev;
        ListNode* leftNode = curr;

        // Reverse the required nodes
        for (int i = 0; i <= right - left; i++) {

            ListNode* nextNode = curr->next;

            curr->next = prev;

            prev = curr;
            curr = nextNode;
        }

        // Connect the first part
        if (prevLeft != NULL) {
            prevLeft->next = prev;
        }
        else {
            head = prev;
        }

        // Connect the second part
        leftNode->next = curr;

        return head;
    }
};