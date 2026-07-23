#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addMultipleNumbers(std::vector<ListNode*>& lists) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* curr = dummyHead;
        int carry = 0;

        while (true) {
            int sum = carry;
            bool hasActiveNodes = false;

            // Add values from all non-null lists at the current position
            for (int i = 0; i < lists.size(); ++i) {
                if (lists[i] != nullptr) {
                    sum += lists[i]->val;
                    lists[i] = lists[i]->next; // Advance the pointer
                    hasActiveNodes = true;
                }
            }

            // Stop if no lists have nodes left and carry is zero
            if (!hasActiveNodes && carry == 0) break;

            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }

        ListNode* result = dummyHead->next;
        delete dummyHead;
        return result;
    }
};

void printList(ListNode* node) {
    while (node != nullptr) {
        std::cout << node->val;
        if (node->next != nullptr) std::cout << " -> ";
        node = node->next;
    }
    std::cout << std::endl;
}

int main() {
    // List 1: 2 -> 4 -> 3  (342)
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    // List 2: 5 -> 6 -> 4  (465)
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    // List 3: 1 -> 2       (21)
    ListNode* l3 = new ListNode(1);
    l3->next = new ListNode(2);

    // 342 + 465 + 21 = 828  (stored as 8 -> 2 -> 8)
    std::vector<ListNode*> lists = {l1, l2, l3};

    Solution sol;
    ListNode* result = sol.addMultipleNumbers(lists);

    std::cout << "Sum of K lists: ";
    printList(result); // Output: 8 -> 2 -> 8

    return 0;
}