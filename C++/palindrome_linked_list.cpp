#include<iostream>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return true;  // Empty list or single node is palindrome
        
        // Step 1: Find the middle of the linked list using slow and fast pointers
        ListNode *slow = head;
        ListNode *fast = head;
        
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Step 2: Reverse the second half of the linked list
        ListNode *secondHalf = reverseList(slow->next);
        
        // Step 3: Compare first half with reversed second half
        ListNode *firstHalf = head;
        while (secondHalf != nullptr) {
            if (firstHalf->val != secondHalf->val)
                return false;
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        
        return true;
    }
    
private:
    // Helper function to reverse a linked list
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        
        while (curr != nullptr) {
            ListNode *next = curr->next;  // Store next node
            curr->next = prev;            // Reverse the link
            prev = curr;                  // Move prev one step forward
            curr = next;                  // Move curr one step forward
        }
        
        return prev;  // New head of reversed list
    }
};

// Main function to test the solution
int main() {
    // Create a sample palindrome linked list: 1->2->2->1
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    
    Solution solution;
    bool isPalindrome = solution.isPalindrome(head);
    
    // Print result
    if (isPalindrome)
        cout << "The linked list is a palindrome" << endl;
    else
        cout << "The linked list is not a palindrome" << endl;
    
    // Clean up memory (delete the linked list)
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
    
    return 0;
}
