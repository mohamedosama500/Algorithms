def sort_stack(stack):
    # This temporary stack will hold elements in sorted order (smallest at bottom)
    tmp_stack = []
    
    while len(stack) > 0:
        # 1. Pop the top element from the original stack
        current = stack.pop()
        
        # 2. While tmp_stack is not empty and its top element is GREATER than current
        while len(tmp_stack) > 0 and tmp_stack[-1] > current:
            # Move elements back to the original stack to clear the way
            stack.append(tmp_stack.pop())
            
        # 3. Push current into the correct spot in tmp_stack
        tmp_stack.append(current)
        
    # At this point, tmp_stack has the largest elements at the top.
    # To restore the original stack structure (with smallest on top), 
    # we copy everything back.
    while len(tmp_stack) > 0:
        stack.append(tmp_stack.pop())
        
    return stack

# --- Example Usage ---
my_stack = [34, 3, 31, 98, 92, 23]
print("Original Stack (top is right):", my_stack)

sort_stack(my_stack)
print("Sorted Stack   (top is right):", my_stack)