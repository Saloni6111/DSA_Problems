#include <iostream>
#include <stack>

using namespace std;

class QueueUsingStacks {
private:
    stack<int> s1, s2;

public:
    // Enqueue operation
    void enqueue(int x) {
        s1.push(x);
    }

    // Dequeue operation
    int dequeue() {
        // If both stacks are empty, return an error
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }

        // If s2 is empty, transfer elements from s1 to s2
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        // Pop the top element from s2, which is the front of the queue
        int front = s2.top();
        s2.pop();
        return front;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return s1.empty() && s2.empty();
    }

    // Get the front element of the queue
    int front() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top();
    }
};

int main() {
    QueueUsingStacks q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Dequeued: " << q.dequeue() << endl; // Outputs 10
    cout << "Dequeued: " << q.dequeue() << endl; // Outputs 20

    q.enqueue(40);
    cout << "Front element: " << q.front() << endl; // Outputs 30

    cout << "Dequeued: " << q.dequeue() << endl; // Outputs 30
    cout << "Dequeued: " << q.dequeue() << endl; // Outputs 40

    return 0;
}
