class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        // Dummy node to simplify insertion
        ListNode* dummy = new ListNode(0);

        ListNode* current = head;

        while (current != nullptr) {
            ListNode* nextNode = current->next;

            // Find position to insert
            ListNode* prev = dummy;

            while (prev->next != nullptr &&
                   prev->next->val < current->val) {
                prev = prev->next;
            }

            // Insert current node
            current->next = prev->next;
            prev->next = current;

            current = nextNode;
        }

        return dummy->next;
    }
};