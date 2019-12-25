struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
 };
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode start = ListNode(0);
    ListNode *l3 = &start;
    
    while (l1 != nullptr) {
        if (l2 == nullptr || l1->val < l2->val) {
            l3->next = l1;
            l1 = l1->next;
        } else {
            l3->next = l2;
            l2 = l2->next;
        }
        l3 = l3->next;
    }
    
    while (l2 != nullptr) {
        l3->next = l2;
        l2 = l2->next;
        l3 = l3->next;
    }
    
    return start.next;
}