#include <iostream>

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Edge case: empty list or single node
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;

        // Iterate through the list, reversing pointers
        while (current != nullptr) {
            // Store next node
            next = current->next;
            
            // Reverse the link
            current->next = prev;
            
            // Move pointers one step forward
            prev = current;
            current = next;
        }

        // Return the new head (last node of original list)
        return prev;
    }

    // Helper function to print the list
    void printList(ListNode* head) {
        while (head != nullptr) {
            std::cout << head->val << " ";
            head = head->next;
        }
        std::cout << std::endl;
    }

    // Helper function to create a list from an array
    ListNode* createList(int arr[], int n) {
        if (n == 0) return nullptr;
        ListNode* head = new ListNode(arr[0]);
        ListNode* current = head;
        for (int i = 1; i < n; i++) {
            current->next = new ListNode(arr[i]);
            current = current->next;
        }
        return head;
    }
};

int main() {
    Solution sol;

    // Test case 1: Empty list
    // Expected output: Empty list
    ListNode* emptyList = nullptr;
    std::cout << "Test case 1 (Empty list):" << std::endl;
    std::cout << "Original: ";
    sol.printList(emptyList);
    ListNode* reversedEmpty = sol.reverseList(emptyList);
    std::cout << "Reversed: ";
    sol.printList(reversedEmpty);
    std::cout << std::endl;

    // Test case 2: Single node
    // Expected output: 1
    ListNode* singleNode = new ListNode(1);
    std::cout << "Test case 2 (Single node):" << std::endl;
    std::cout << "Original: ";
    sol.printList(singleNode);
    ListNode* reversedSingle = sol.reverseList(singleNode);
    std::cout << "Reversed: ";
    sol.printList(reversedSingle);
    std::cout << std::endl;

    // Test case 3: Multiple nodes
    // Expected output: 5 4 3 2 1
    int arr[] = {1, 2, 3, 4, 5};
    ListNode* multipleNodes = sol.createList(arr, 5);
    std::cout << "Test case 3 (Multiple nodes):" << std::endl;
    std::cout << "Original: ";
    sol.printList(multipleNodes);
    ListNode* reversedMultiple = sol.reverseList(multipleNodes);
    std::cout << "Reversed: ";
    sol.printList(reversedMultiple);

    return 0;
}