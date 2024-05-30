#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;

struct Node
{
	int value;
	Node* next_node;
};

Node* fill_stack(bool autogenerate) {
	Node* top_element = nullptr;
	while (true) {
		int value;
		if (autogenerate) {
			value = std::rand() % 20 - 10;
			cout << value << endl;
			if (value == 0) {
				return top_element;
			}
		}
		else {
			cin >> value;
		}
		if (value == 0) {
			return top_element;
		}
		Node* element = new Node();
		element->value = value;
		element->next_node = top_element;
		top_element = element;
	}
}

Node* get_stack_from_input() {
	return fill_stack(false);
};

Node* generate_stack() {
	std::srand(std::time(nullptr));
	return fill_stack(true);
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		cout << "Wrong number of arguments. Enter <file.exe> true|false" << endl;
		return 1;
	}
	bool is_user_program = (strcmp("true", argv[1]) == 0);
	if (!is_user_program) {
		bool is_program_program = (strcmp("false", argv[1]) == 0);
		if (!is_program_program) {
			cout << "Wrong argument. Enter <file.exe> true|false" << endl;
			return 1;
		}
	}
	cout << "Input:" << endl;
	Node* top_element;
	if (is_user_program) {
		top_element = get_stack_from_input();
	}
	else {
		top_element = generate_stack();
	}
	cout << "Output:" << endl;
	while (top_element != nullptr) 
	{
		if (top_element->value > 0) {
			cout << top_element->value << endl;
		}
		Node* prev_top = top_element;
		top_element = top_element->next_node;
		delete prev_top;
	}

	return 0;
}