#include <bits/stdc++.h>

struct Student {
	int id;
	std::string name, email, address, phone, password;
};

class SRecords {
private:
	struct Node {
		Student data;
		Node *next;

		Node(Student newStudent)
			: data(newStudent), next(nullptr) {}
		~Node() = default;
	};
	Node *head;
	Node *tail;
	int nodectr = 0;
public:
	SRecords()
		: head(nullptr), tail(nullptr) {}
	~SRecords() {
		while (head != nullptr) {
			Node *anchor = head;
			head = head->next;
			delete anchor;
		}
		tail = nullptr;
	}
	
	// Methods section -> this is where methods are implemented //
	
	void addStudent(Student newStudent) {
		Node *newNode = new Node(newStudent);
		if (nodectr == 0) {
			head = tail = newNode;
		} else {
			tail->next = newNode;
			tail = newNode;
		}
		++nodectr;
	}
};

int main(void) {
	
	return 0;
}
