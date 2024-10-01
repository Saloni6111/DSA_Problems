class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def addTwoNumbers(l1, l2):
    dummy_head = ListNode(0)  # Dummy node to help in constructing the result list
    current = dummy_head
    carry = 0
    
    # Loop through both linked lists
    while l1 is not None or l2 is not None:
        # Get values from the current nodes of both lists (or 0 if no node exists)
        val1 = l1.val if l1 is not None else 0
        val2 = l2.val if l2 is not None else 0
        
        # Calculate sum and carry
        total = val1 + val2 + carry
        carry = total // 10  # Compute carry for the next step
        current.next = ListNode(total % 10)  # Append the result digit to the list
        
        # Move to the next nodes in both lists
        current = current.next
        if l1 is not None: l1 = l1.next
        if l2 is not None: l2 = l2.next
    
    # If there is a carry remaining, append it as a new node
    if carry > 0:
        current.next = ListNode(carry)
    
    return dummy_head.next

# Helper function to create a linked list from a list of digits
def createLinkedList(digits):
    dummy_head = ListNode(0)
    current = dummy_head
    for digit in digits:
        current.next = ListNode(digit)
        current = current.next
    return dummy_head.next

# Helper function to print a linked list
def printLinkedList(node):
    while node is not None:
        print(node.val, end=' ')
        node = node.next
    print()

# Input two numbers as lists of digits (reversed order)
num1 = list(map(int, input("Enter digits of first number in reverse order: ").split()))
num2 = list(map(int, input("Enter digits of second number in reverse order: ").split()))

# Create linked lists from input
l1 = createLinkedList(num1)
l2 = createLinkedList(num2)

# Add two numbers
result = addTwoNumbers(l1, l2)

# Print the result as a linked list
print("Resultant linked list:")
printLinkedList(result)
