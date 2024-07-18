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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* first = head;
        ListNode* second = head;
        ListNode* current = head;

        // Move the `first` pointer to the k-th node
        for (int i = 1; i < k; ++i) {
            first = first->next;
        }

        // Keep a reference to the k-th node
        ListNode* kthNodeFromStart = first;

        // Move the `current` pointer to the end while moving the `second` pointer to the k-th node from the end
        while (current->next != nullptr) {
            current = current->next;
            if (--k <= 0) {
                second = second->next;
            }
        }

        // Swap the values of the k-th node from the start and the k-th node from the end
        int tempVal = kthNodeFromStart->val;
        kthNodeFromStart->val = second->val;
        second->val = tempVal;

        return head;
    }
};
