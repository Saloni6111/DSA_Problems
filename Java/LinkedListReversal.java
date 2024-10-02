
public class LinkedListReversal {

    // Define the Node class
    static class Node {
        int data;
        Node next;

        // Constructor to initialize the node
        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    // Method to reverse the linked list
    public static Node reverseLinkedList(Node head) {
        Node prev = null;  // Initialize the previous node as null
        Node current = head;  // Start with the head node
        Node next = null;  // Temporary node to store the next node

        while (current != null) {
            next = current.next;  // Store the next node
            current.next = prev;  // Reverse the current node's pointer
            prev = current;  // Move prev and current one step forward
            current = next;
        }

        head = prev;  // Set the last processed node as the new head
        return head;
    }

    // Method to print the linked list
    public static void printList(Node head) {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
        Node head = new Node(1);
        head.next = new Node(2);
        head.next.next = new Node(3);
        head.next.next.next = new Node(4);
        head.next.next.next.next = new Node(5);

        System.out.println("Original Linked List:");
        printList(head);

        // Reverse the linked list
        head = reverseLinkedList(head);

        System.out.println("Reversed Linked List:");
        printList(head);
    }
}

