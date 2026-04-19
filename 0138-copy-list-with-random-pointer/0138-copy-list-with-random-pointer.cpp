class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;

        Node* cur = head;
        while (cur) {
            Node* copy = new Node(cur->val);
            copy->next = cur->next;
            cur->next = copy;
            cur = copy->next;
        }

        cur = head;
        while (cur) {
            if (cur->random)
                cur->next->random = cur->random->next;
            cur = cur->next->next;
        }

        cur = head;
        Node* newHead = head->next;
        while (cur) {
            Node* copy = cur->next;
            cur->next = copy->next;
            if (copy->next)
                copy->next = copy->next->next;
            cur = cur->next;
        }

        return newHead;
    }
};