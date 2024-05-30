#include <iostream>

using namespace std;

struct Node
{
	int value;
	Node* next_node;
};

struct Queue {
    Node* first = nullptr;
    Node* last = nullptr;

    void queue(int value) {
        Node* new_node = new Node();
        new_node->value = value;
        new_node->next_node = nullptr;
        if (last == nullptr) {
            last = new_node;
            first = new_node;
        } else {
            last->next_node = new_node;
            last = new_node;
        }
    }

    int unqueue() {
        if (first == nullptr) {
            cout << "Queue is empty. 0 is returned" << endl;
            return 0;
        }
        Node* node_to_remove = first;
        first = first->next_node;
        if (first == nullptr) {
            last = nullptr;
        }
        int result = node_to_remove->value;
        delete node_to_remove;
        return result;
    }

    int count() {
        int counter = 0;
        for (Node* node = first; node != nullptr; node = node->next_node) {
            counter++;
        }
        return counter;    
    }

    void insertBeforeNegative() {
        Node* prev_node = nullptr;
        for (Node* node = first; node != nullptr; node = node->next_node) {
            if (node->value < 0) {
                Node* new_node = new Node();
                new_node->value = 1;
                if (prev_node != nullptr) {
                    prev_node->next_node = new_node;
                } else {
                    first = new_node;
                }
                new_node->next_node = node;
            }
            prev_node = node;
        }
    }

    void removeNegative() {
        Node* prev_node = nullptr;
        for (Node* node = first; node != nullptr;) {
            if (node->value < 0) {
                if (prev_node != nullptr) {
                    prev_node->next_node = node->next_node;
                } else {
                    first = node->next_node;
                }
                Node* node_to_remove = node;
                node = node->next_node;
                delete node_to_remove;
            } else {
                prev_node = node;
                node = node->next_node;
            }
        }
        if (first == nullptr) {
            last = nullptr;
        }
    }

    int count(int v) {
        int counter = 0;
        for (Node* node = first; node != nullptr; node = node->next_node) {
            if (node->value == v) {
                counter++;
            }
        }
        return counter;
    }

    void clear() {
        if (first == nullptr) {
            return;
        }
        unqueue();
        clear();
    }

    void print() {
        for (Node* node = first; node != nullptr; node = node->next_node) {
            cout << node->value << " ";
        }
    }
};

Queue* fill_queue() {
	Queue* queue = new Queue();
	while (true) {
        int value;
        cin >> value;

		if (value == 0) {
			return queue;
		}
		queue->queue(value);
	}
}

void print_instruction() {
    cout << endl;
    cout << "Enter 1 to queue;" << endl;
    cout << "Enter 2 to unqueue;" << endl;
    cout << "Enter 3 to count queue elements;" << endl;
    cout << "Enter 4 to insert 1 before all negative;" << endl;
    cout << "Enter 5 to remove all negative;" << endl;
    cout << "Enter 6 to count elements with specified value in queue;" << endl;
    cout << "Enter 7 to clear the queue;" << endl;
    cout << "Enter 8 to print instruction;" << endl;
    cout << "Enter 0 to exit;" << endl;
    cout << endl;
}

int main() {
	cout << "Enter queue elements:" << endl;
	Queue* queue = fill_queue();
	cout << "Entered queue: ";
    queue->print();
    cout << endl;

    print_instruction();

	while(true) {
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 0) {
            break;
        } else if (choice == 1) {
            cout << "Enter value to queue: ";
            int value;
            cin >> value;
            queue->queue(value);
        } else if (choice == 2) {
            int value = queue->unqueue();
            cout << "Unqueued value: " << value << endl;
        } else if (choice == 3) {
            int value = queue->count();
            cout << "Elements count: " << value << endl;
        } else if (choice == 4) {
            queue->insertBeforeNegative();
        } else if (choice == 5) {
            queue->removeNegative();
        } else if (choice == 6) {
            cout << "Enter value to count: ";
            int value;
            cin >> value;
            int count = queue->count(value);
            cout << "Elements count: " << count << endl;
        } else if (choice == 7) {
            queue->clear();
        } else if (choice == 8) {
            print_instruction();
            continue;
        } else {
            cout << "Wrong input" << endl;
            print_instruction();
            continue;
        }
        cout << "Queue: ";
        queue->print();
        cout << endl << endl;
    }
    queue->clear();
    delete queue;

	return 0;
}