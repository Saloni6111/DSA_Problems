// Filename: detect-cycle-in-linkedlist.java

import java.util.HashMap;
import java.util.Map;

// Node class represents a node in a linked list
class Node {
    // Data stored in the node
    public int data;
    // Pointer to the next node in the list
    public Node next;

    // Constructor with both data and next node as parameters
    public Node(int data, Node next) {
        this.data = data;
        this.next = next;
    }

    // Constructor with only data as a parameter, sets next to null
    public Node(int data) {
        this.data = data;
        this.next = null;
    }
}

public class DetectCycleInLinkedList {

    // Function to detect a loop in a linked list using the Tortoise and Hare Algorithm
    public static boolean detectCycle(Node head) {
        // Initialize two pointers, slow and fast, to the head of the linked list
        Node slow = head;
        Node fast = head;

        // Traverse the linked list with slow and fast pointers
        while (fast != null && fast.next != null) {
            // Move slow one step
            slow = slow.next;
            // Move fast two steps
            fast = fast.next.next;

            // If slow and fast pointers meet, a cycle is detected
            if (slow == fast) {
                return true;  // Loop detected
            }
        }

        // If fast reaches the end, there is no loop
        return false;
    }

    public static void main(String[] args) {
        // Test case 1: Create a linked list with a loop for testing
        Node head = new Node(1);
        Node second = new Node(2);
        Node third = new Node(3);
        Node fourth = new Node(4);
        Node fifth = new Node(5);

        head.next = second;
        second.next = third;
        third.next = fourth;
        fourth.next = fifth;
        // Create a loop: fifth node points back to the third node
        fifth.next = third;

        // Check if there is a loop in the linked list
        if (detectCycle(head)) {
            System.out.println("Loop detected in the linked list.");
        } else {
            System.out.println("No loop detected in the linked list.");
        }

        // Test case 2: Create a linked list without a loop
        Node head2 = new Node(10);
        Node second2 = new Node(20);
        Node third2 = new Node(30);

        head2.next = second2;
        second2.next = third2;
        third2.next = null;

        // Check if there is a loop in the linked list
        if (detectCycle(head2)) {
            System.out.println("Loop detected in the second linked list.");
        } else {
            System.out.println("No loop detected in the second linked list.");
        }

        // No need to explicitly free memory in Java; the garbage collector handles it
    }
}

/*
# Test case 1: Linked list with nodes 1 -> 2 -> 3 -> 4 -> 5, and 5 points back to 3
# Expected output: "Loop detected in the linked list."

# Test case 2: Linked list with nodes 10 -> 20 -> 30 -> null
# Expected output: "No loop detected in the second linked list."
*/
