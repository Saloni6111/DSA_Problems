#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return false;
    }

    // Initialize two pointers, slow and fast.
    ListNode* slow = head;
    ListNode* fast = head;

    // Traverse the linked list.
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;          // Slow pointer moves one step
        fast = fast->next->next;    // Fast pointer moves two steps

        // If slow and fast meet, there's a cycle.
        if (slow == fast) {
            return true;
        }
    }

    // No cycle detected.
    return false;
}

int main() {
    // Example list with cycle
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);

    // Creating a cycle
    head->next->next->next->next = head->next;

    if (hasCycle(head)) {
        cout << "Cycle detected!" << endl;
    } else {
        cout << "No cycle." << endl;
    }

    return 0;
}