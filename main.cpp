#include <bits/stdc++.h>

struct Student {
	int id;
	std::string name, email, address, phone;
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
	int nodectr = 0;
public:
	SRecords()
		: head(nullptr) {}
	~SRecords() {
		while (head != nullptr) {
			Node *anchor = head;
			head = head->next;
			delete anchor;
		}
	}
	
	// Methods section -> this is where methods are implemented //
};

int main(void) {

}
