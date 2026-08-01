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
        /*
           if you don't use a dummy node
           You would have to check whether the head is nullptr on every single iteration
           for the curr pointer, so make sure it starts from begining initialized.
        */
        // dummyHead will be used at last of loop
        // it permanently remembers where your result list begins. At the end
        ListNode* dummyHead = new ListNode(0);
        ListNode* curr = dummyHead;
        int carry = 0;

        while (true) {
            int sum = carry;
            bool hasActiveNodes = false;

            // Add values from all non-null lists at the current position
            /*
                /* For example: 
                    List 1: 9 -> 8 
                    List 2: 9 -> 8 
                    List 3: 9 -> 8 

                    we are adding the first column for the first cycle
                    for all nodes then we take the carry after that then
                    we make Pointers are now sitting on the SECOND nodes for all lists
            */
            for (int i = 0; i < lists.size(); ++i) {
                if (lists[i] != nullptr) {
                    sum += lists[i]->val;
                    lists[i] = lists[i]->next; // Advance the pointer
                    hasActiveNodes = true;
                }
            }

            // Stop if no lists have nodes left and carry is zero
            if (!hasActiveNodes && carry == 0) break;
            // Integer devision gives the carry for the next 
            // As each node in a linked list can only hold a single digit (0 through 9)
            carry = sum / 10;
            // Creates a new node with the extracted digit and attaches it to our result list and 
            // Gives single digit for the current position [curr = curr->next]
            /* For example: 
                    List 1: 9 -> 8 
                    List 2: 9 -> 8 
                    List 3: 9 -> 8 
                    Actual Math  89 + 89 + 89 = 267 Stored as  7 --> 6 --> 2
            */
            // Output Node Created: curr->next
            curr->next = new ListNode(sum % 10);
            // At last cycle curr will be nullptr
            curr = curr->next;
        }
        // Here dummyHead will points to first node created which is 7 to sens the result
        // as 7 --> 6 --> 2
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