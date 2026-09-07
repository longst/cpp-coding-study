# Merge Two Sorted Lists

## Pattern

Linked list, dummy node, pointer splicing.

## Key idea

Use a dummy node to simplify building the result list. Attach the smaller current node each time, then move that list forward.

## Correct solution

```cpp
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
```

## Common mistakes

- Checking `list1->next` instead of `list1`.
- Reassigning `current = list1` instead of connecting `current->next = list1`.
- Returning `&dummy` instead of `dummy.next`.
- Forgetting to connect the remaining nodes.

## Complexity

- Time: `O(n + m)`
- Space: `O(1)`

