#include <iostream>

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode dummy;
    ListNode* current = &dummy;

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val <= list2->val) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    current->next = (list1 != nullptr) ? list1 : list2;
    return dummy.next;
}

void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << (head->next ? " -> " : "");
        head = head->next;
    }
    std::cout << '\n';
}

int main() {
    ListNode node1_4(4);
    ListNode node1_2(2, &node1_4);
    ListNode node1_1(1, &node1_2);

    ListNode node2_4(4);
    ListNode node2_3(3, &node2_4);
    ListNode node2_1(1, &node2_3);

    ListNode* merged = mergeTwoLists(&node1_1, &node2_1);
    printList(merged); // 1 -> 1 -> 2 -> 3 -> 4 -> 4

    return 0;
}
