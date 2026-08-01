from typing import List, Optional

class ListNode:
    def __init__(self, val: int = 0, next: Optional['ListNode'] = None):
        self.val = val
        self.next = next


class Solution:
    def addMultipleNumbers(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        """
        if you don't use a dummy node
        You would have to check whether the head is None on every single iteration
        for the curr pointer, so make sure it starts from begining initialized.
        """
        # dummy_head will be used at last of loop
        # it permanently remembers where your result list begins.
        dummy_head = ListNode(0)
        curr = dummy_head
        carry = 0

        while True:
            sum_val = carry
            has_active_nodes = False

            # Add values from all non-null lists at the current position
            """
            For example: 
                List 1: 9 -> 8 
                List 2: 9 -> 8 
                List 3: 9 -> 8 

                we are adding the first column for the first cycle
                for all nodes then we take the carry after that then
                we make Pointers are now sitting on the SECOND nodes for all lists
            """
            for i in range(len(lists)):
                if lists[i] is not None:
                    sum_val += lists[i].val
                    lists[i] = lists[i].next  # Advance the pointer
                    has_active_nodes = True

            # Stop if no lists have nodes left and carry is zero
            if not has_active_nodes and carry == 0:
                break

            # Integer division gives the carry for the next 
            # As each node in a linked list can only hold a single digit (0 through 9)
            carry = sum_val // 10

            # Creates a new node with the extracted digit and attaches it to our result list
            """
            For example: 
                List 1: 9 -> 8 
                List 2: 9 -> 8 
                List 3: 9 -> 8 
                Actual Math  89 + 89 + 89 = 267 Stored as  7 --> 6 --> 2
            """
            curr.next = ListNode(sum_val % 10)
            curr = curr.next

        # Automatic garbage collection in Python handles memory, 
        # so explicit 'delete' isn't needed.
        return dummy_head.next


def print_list(node: Optional[ListNode]) -> None:
    parts = []
    while node is not None:
        parts.append(str(node.val))
        node = node.next
    print(" -> ".join(parts))


if __name__ == "__main__":
    # List 1: 2 -> 4 -> 3  (342)
    l1 = ListNode(2)
    l1.next = ListNode(4)
    l1.next.next = ListNode(3)

    # List 2: 5 -> 6 -> 4  (465)
    l2 = ListNode(5)
    l2.next = ListNode(6)
    l2.next.next = ListNode(4)

    # List 3: 1 -> 2       (21)
    l3 = ListNode(1)
    l3.next = ListNode(2)

    # 342 + 465 + 21 = 828  (stored as 8 -> 2 -> 8)
    lists = [l1, l2, l3]

    sol = Solution()
    result = sol.addMultipleNumbers(lists)

    print("Sum of K lists: ", end="")
    print_list(result)  # Output: 8 -> 2 -> 8