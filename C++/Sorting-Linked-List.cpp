#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node * next;
    
    Node(int x, Node* n = NULL) {
        data = x;
        next = n;
    }
};

Node* convertArrayIntoLinkedList(vector<int> &arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

void print(Node* head) {
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* mergeTwoSortedLinkedLists(Node* list1, Node* list2) {
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->data <= list2->data) {
            temp->next = list1;
            list1 = list1->next;
        } else {
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next; 
    }

    if (list1 != nullptr) {
        temp->next = list1;
    } else {
        temp->next = list2;
    }

    return dummyNode->next;
}

Node* findMiddle(Node* head){
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* slow = head;
    Node* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node* sortLinkedList(Node* head) {
    if(head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* middle = findMiddle(head);

    Node* right = middle->next;
    middle->next = nullptr;
    Node* left = head;

    left = sortLinkedList(left);
    right = sortLinkedList(right);

    return mergeTwoSortedLinkedLists(left, right);
}

int main() {
    vector<int> arr = {12, 5, 8, 7, 10, 51, 21, 31};
    Node* head = convertArrayIntoLinkedList(arr);

    head = sortLinkedList(head);
    print(head);

    return 0;
}