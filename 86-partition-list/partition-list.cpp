class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // Dummy nodes for the two partitions
        ListNode lessDummy(0);
        ListNode greaterDummy(0);

        ListNode* less = &lessDummy;
        ListNode* greater = &greaterDummy;

        while (head != nullptr) {
            if (head->val < x) {
                less->next = head;
                less = less->next;
            } else {
                greater->next = head;
                greater = greater->next;
            }

            head = head->next;
        }

        // Connect the two partitions
        less->next = greaterDummy.next;

        // Important: terminate the final list
        greater->next = nullptr;

        return lessDummy.next;
    }
};
