#include <iostream>

using namespace std;

struct Node
{
	int value;
	Node* next_node;
};

struct CyclingList {
    Node* last = nullptr;

    void add(int value) {
        Node* new_node = new Node();
        new_node->value = value;
        if (last == nullptr) {
            new_node->next_node = new_node;
            last = new_node;
        } else {
            new_node->next_node = last->next_node;
            last->next_node = new_node;
            last = new_node;
        }
    }

    void insert(int index, int value) {
        Node* new_node = new Node();
        new_node->value = value;
        if (last == nullptr) {
            if (index != 0) {
                cout << "Index is out of list size" << endl;
                return;
            }
            this->add(value);
            return;
        }
        for (Node* node = last->next_node;; node = node->next_node, index--) {
            if (index == 0) {
                new_node->next_node = node->next_node;
                node->next_node = new_node;
                if (node == last) {
                    last = new_node;
                }
                return;
            }
            if (node == last) {
                if (index == 1) {
                    new_node->next_node = node->next_node;
                    node->next_node = new_node;
                    last = new_node;
                    return;
                }
                cout << "Index is out of list size" << endl;
                break;
            }
        }
    }

    void removeAt(int index) {
        Node* prev_node = last;
        if (last == nullptr) {
            cout << "Index is out of list size" << endl;
            return;
        }
        for (Node* node = last->next_node;; prev_node = node, node = node->next_node, index--) {
            if (index == 0) {
                if (node == node->next_node) {
                    last = nullptr;
                } else {
                    prev_node->next_node = node->next_node;
                    if (node == last) {
                        last = prev_node;
                    }
                }
                delete node;
                return;
            }
            if (node == last) {
                cout << "Index is out of list size" << endl;
                return;
            }
        }
    }

    int elementAt(int index) {
        Node* prev_node = last;
        if (last == nullptr) {
            cout << "Index is out of list size, 0 is returned" << endl;
            return 0;
        }
        for (Node* node = last->next_node;; prev_node = node, node = node->next_node, index--) {
            if (index == 0) {
                return node->value;
            }
            if (node == last) {
                cout << "Index is out of list size, 0 is returned" << endl;
                return 0;
            }
        }
    }

    int count() {
        if (last == nullptr) {
            return 0;
        }
        int counter = 1;
        for (Node* node = last->next_node; node != last; node = node->next_node) {
            counter++;
        }
        return counter;    
    }

    void insertBeforeNegative() {
        Node* prev_node = last;
        if (last == nullptr) {
            return;
        }
        for (Node* node = last->next_node;; prev_node = node, node = node->next_node) {
            if (node->value < 0) {
                Node* new_node = new Node();
                new_node->value = 1;
                prev_node->next_node = new_node;
                new_node->next_node = node;
            }
            if (node == last) {
                break;
            }
        }
    }

    void removeNegative() {
        Node* prev_node = last;
        if (last == nullptr) {
            return;
        }
        for (Node* node = last->next_node;;) {
            if (node->value < 0) {
                prev_node->next_node = node->next_node;
                if (node == node->next_node) {
                    last = nullptr;
                } else if (node == last) {
                    last = prev_node;
                }
                Node* next_node = node->next_node;
                if (node == last || last == nullptr) {
                    delete node;
                    break;
                }
                delete node;
                node = next_node;
            } else {
                prev_node = node;
                if (node == last) {
                    break;
                }
                node = node->next_node;

            }
        }
    }

    int count(int v) {
        int counter = 0;
        if (last == nullptr) {
            return 0;
        }
        for (Node* node = last->next_node;; node = node->next_node) {
            if (node->value == v) {
                counter++;
            }
            if (node == last) {
                break;
            }
        }
        return counter;
    }

    void clear() {
        if (last == nullptr) {
            return;
        }
        removeAt(0);
        clear();
    }

    void print() {
        if (last == nullptr) {
            return;
        }
        for (Node* node = last->next_node;; node = node->next_node) {
            cout << node->value << " ";
            if (node == last) {
                break;
            }
        }
    }
};

CyclingList* fill_list() {
	CyclingList* list = new CyclingList();
	while (true) {
        int value;
        cin >> value;

		if (value == 0) {
			return list;
		}
		list->add(value);
	}
}

void print_instruction() {
    cout << endl;
    cout << "Enter 1 to add;" << endl;
    cout << "Enter 2 to insert;" << endl;
    cout << "Enter 3 to remove;" << endl;
    cout << "Enter 4 to show element;" << endl;
    cout << "Enter 5 to count elements;" << endl;
    cout << "Enter 6 to insert 1 before all negative;" << endl;
    cout << "Enter 7 to remove all negative;" << endl;
    cout << "Enter 8 to count elements with specified value in list;" << endl;
    cout << "Enter 9 to clear the list;" << endl;
    cout << "Enter 10 to print instruction;" << endl;
    cout << "Enter 0 to exit;" << endl;
    cout << endl;
}

int main() {
	cout << "Enter list elements:" << endl;
	CyclingList* list = fill_list();
	cout << "Entered list: ";
    list->print();
    cout << endl;

    print_instruction();

	while(true) {
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 0) {
            break;
        } else if (choice == 1) {
            cout << "Enter value to add: ";
            int value;
            cin >> value;
            list->add(value);
        } else if (choice == 2) {
            cout << "Enter value to insert: ";
            int value;
            cin >> value;
            cout << "Enter index: ";
            int index;
            cin >> index;
            list->insert(index, value);
        } else if (choice == 3) {
            cout << "Enter index: ";
            int index;
            cin >> index;
            list->removeAt(index);
        } else if (choice == 4) {
            cout << "Enter index: ";
            int index;
            cin >> index;
            int value = list->elementAt(index);
            cout << "Element: " << value << endl;
        } else if (choice == 5) {
            int value = list->count();
            cout << "Elements count: " << value << endl;
        } else if (choice == 6) {
            list->insertBeforeNegative();
        } else if (choice == 7) {
            list->removeNegative();
        } else if (choice == 8) {
            cout << "Enter value to count: ";
            int value;
            cin >> value;
            int count = list->count(value);
            cout << "Elements count: " << count << endl;
        } else if (choice == 9) {
            list->clear();
        } else if (choice == 10) {
            print_instruction();
            continue;
        } else {
            cout << "Wrong input" << endl;
            print_instruction();
            continue;
        }
        cout << "List: ";
        list->print();
        cout << endl << endl;
    }
    list->clear();
    delete list;

	return 0;
}