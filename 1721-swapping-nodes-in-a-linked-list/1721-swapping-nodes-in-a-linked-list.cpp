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
        // Find the length of the linked list
        int length = 0;
        ListNode* temp = head;
        while (temp) {
            length++;
            temp = temp->next;
        }
        // Identify the positions from start and end
        int nodeFromStartIndex = k - 1;
        int nodeFromEndIndex = length - k;
        // Find the k-th node from the start
        ListNode* firstNode = head;
        for (int i = 0; i < nodeFromStartIndex; ++i) {
            firstNode = firstNode->next;
        }
        // Find the k-th node from the end
        ListNode* secondNode = head;
        for (int i = 0; i < nodeFromEndIndex; ++i) {
            secondNode = secondNode->next;
        }
        // Swap the values of the two nodes
        int tempVal = firstNode->val;
        firstNode->val = secondNode->val;
        secondNode->val = tempVal;
        return head;
    }
};
