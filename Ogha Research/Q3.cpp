#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class VersionQueue {
private:
    Node* front;
    Node* rear;
    int version;

public:
    VersionQueue() {
        front = nullptr;
        rear = nullptr;
        version = 0;
    }

    void Enqueue(int element) {
        Node* newNode = new Node();
        newNode->data = element;
        newNode->next = nullptr;

        if (IsEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        version++;
    }

    int Dequeue() {
        if (IsEmpty()) {
            cout << "Error: Queue is empty!" << endl;
            return -1;
        }

        int frontElement = front->data;
        Node* temp = front;

        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;

        version++;

        return frontElement;
    }

    void Print(int targetVersion) {
        if (targetVersion > version) {
            cout << "Error: Target version does not exist!" << endl;
            return;
        }

        Node* current = front;
        int currentVersion = 1;

        while (current != nullptr) {
            if (currentVersion > targetVersion) {
                break;
            }

            cout << current->data << " ";
            current = current->next;
            currentVersion++;
        }

        cout << endl;
    }

    bool IsEmpty() {
        return front == nullptr;
    }

    int GetVersion() {
        return version;
    }
};

int main() {
    VersionQueue queue;
    queue.Enqueue(5);
    queue.Enqueue(10);
    queue.Enqueue(15);
    queue.Enqueue(20);

    cout << "Current Version: " << queue.GetVersion() << endl;

    queue.Print(2);

    queue.Dequeue();

    cout << "Current Version: " << queue.GetVersion() << endl;

    queue.Print(3);

    return 0;
}
