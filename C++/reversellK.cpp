#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct node {
    int data;
    struct node* next;

    node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(struct node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


class Solution {
  public:
    struct node *reverseIt(struct node *head, int k) {
        if(head==nullptr){
            return nullptr;
        }

        node* curr= head;
        node* prev= nullptr;
        node* ford= nullptr;
        int count= 0;
        while(count<k and curr!=nullptr){
            ford= curr->next;
            curr->next= prev;
            prev= curr;
            curr= ford;
            count++;

        }
        if(ford!= nullptr){
            head->next= reverseIt(ford, k);

        }
        return prev;
    }
};

int main(void) {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        node* head = new node(data);
        node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new node(data);
            tail = tail->next;
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.reverseIt(head, k);
        printList(head);
    }

    return (0);
}
