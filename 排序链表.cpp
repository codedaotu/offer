struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
ListNode* sortList(ListNode* head) {
        quickSort(head, nullptr);
        return head;
    }

    void quickSort(ListNode* head, ListNode* tail) {
        if (head == tail || head->next == nullptr) {
            return;
        }

        ListNode* mid = partition(head, tail);

        quickSort(head, mid);
        quickSort(mid->next, tail);
    }

    ListNode* partition(ListNode* head, ListNode * tail) {

        int pivot = head->val;
        ListNode* s = head;
        ListNode* cur = head->next;
        while (cur != nullptr && cur != tail)
        {
            if (cur->val < pivot) {
                s = s->next;
                cout<<s<<cur;
                swap(s, cur);
            }
            cur = cur->next;
        }
        swap(s, head);
        return s;
    }


    void swap(ListNode* a, ListNode* b) {
        int temp = a->val;
        a->val = b->val;
        b->val = temp;
    }

int main(int argc, char const *argv[])
{
    
    return 0;
}