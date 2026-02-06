class Solution {
public:
    ListNode* reverseLL(ListNode *head) {
        ListNode *curr = head;
        ListNode *prev = NULL;

        while (curr != NULL) {
            ListNode *front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        return prev;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0) return head;

        // find length
        int n = 0;
        ListNode *temp = head;
        while (temp != NULL) {
            n++;
            temp = temp->next;
        }

        k = k % n;
        if (k == 0) return head;   // 🔥 important

        // reverse entire list
        ListNode *reversedHead = reverseLL(head);

        // move to kth node
        temp = reversedHead;
        for (int i = 1; i < k; i++) {
            temp = temp->next;
        }

        // split
        ListNode *head1 = reversedHead;
        ListNode *head2 = temp->next;
        temp->next = NULL;

        // reverse both parts
        ListNode *reversedhead1 = reverseLL(head1);
        ListNode *reversedhead2 = reverseLL(head2);

        // join
        ListNode *temp1 = reversedhead1;
        while (temp1->next != NULL) {
            temp1 = temp1->next;
        }
        temp1->next = reversedhead2;

        return reversedhead1;
    }
};
