#include <bits/stdc++.h>

struct Student {
	int id;
	std::string name, email, address, phone, password;
};

class SRecords {          // By SEIF ALLAH //
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

	// Helper functions for Merge Sorting algorithm //
	
	Node* getMiddle(Node *startNode) {
		if (startNode == nullptr) return nullptr;

		Node *one = startNode;
		Node *two = startNode->next;
		while (two != nullptr && two->next != nullptr) {
			one = one->next;
			two = two->next->next;
		}
		return one;
	}

	Node* merge(Node *left, Node *right) {
		if (left == nullptr) return right;
		if (right == nullptr) return left;

		Node *result = nullptr;
		if (left->data.id <= right->data.id) {
			result = left;
			result->next = merge(left->next, right);
		} else {
			result = right;
			result->next = merge(left, right->next);
		}
		return result;
	}

	Node* mergeSortRec(Node *cur_h) {
		if (cur_h == nullptr || cur_h->next == nullptr) return cur_h;

		Node *middle = getMiddle(cur_h);
		Node *nextToMiddle = middle->next;
		middle->next = nullptr;

		Node *left = mergeSortRec(cur_h);
		Node *right = mergeSortRec(nextToMiddle);
		return merge(left, right);
	}

	// Helper functions for Binary Search algorithm //
	
	Node* getMiddleBinary (Node *first, Node *last) {
		if (first == nullptr) return nullptr;

		Node *one = first;
		Node *two = first->next;
		while (two != last) {
			two = two->next;
			if (two != last) {
				one = one->next;
				two = two->next;
			}
		}
		return one;
	}
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

	// Handled edge cases & the new (Node *tail) node //
	void deleteStudent(int s_id) {
		if (nodectr == 0) throw std::out_of_range("Cannot deleteStudent() from an empty Student Record.");
		else if (nodectr == 1) {
			if (head->data.id == s_id) {
				delete head;
				head = tail = nullptr;
				--nodectr;
			} else {
				std::cout << "Student with ID: " << s_id << " does not exist.\n";
			}
			return;
		} else if (head->data.id == s_id) {
			Node *anchor = head;
			head = head->next;
			delete anchor;
			--nodectr;
		} else if (tail->data.id == s_id) {
			Node *it = head;
			while (it->next != tail) it = it->next;
			delete tail;
			tail = it;
			tail->next = nullptr;
			--nodectr;
		} else {
			Node *it = head;
			while (it->next != nullptr && it->next->data.id != s_id) it = it->next;
			if (it->next == nullptr) {
				std::cout << "Student with ID: " << s_id << " does not exist.\n";
			} else {
				Node *anchor = it->next;
				it->next = anchor->next;
				delete anchor;
				--nodectr;
			}
		}
	}

	void sortStudents(void) {
		if (head == nullptr || head->next == nullptr) return;
		head = mergeSortRec(head);

		// Re-positioning the tail after sorting //

		Node *it = head;
		while (it->next != nullptr) it = it->next;
		tail = it;
		std::cout << "Students sorted by ID (Merge Sort).\n";
	}

	Student* searchStudentLinear(int s_id) {
		Node *it = head;
		while (it != nullptr) {
			if (it->data.id == s_id) return &it->data;
			it = it->next;
		}
		return nullptr;
	}

	Student* searchStudentBinary(int s_id) {
		sortStudents();
		Node *first = head;
		Node *last = nullptr;

		while (first != last) {
			Node *mid = getMiddleBinary(first, last);
			if (mid == nullptr) return nullptr;

			if (mid->data.id == s_id) return &mid->data;
			else if (mid->data.id > s_id) last = mid;
			else first = mid->next;
		}
		return nullptr;
	}

	void displayStudents(void) {
		if (head == nullptr) {
			std::cout << "------------------------\n";
			std::cout << "Student Record is Empty.\n";
			std::cout << "------------------------\n";
			return;
		}

		Node *it = head;
		std::cout << "\n=== Registered Students (" << nodectr << ") ===\n";
		while (it != nullptr) {
			std::cout << "--------------------------------------------\n";
			std::cout << "Student:  " << it->data.name << '\n';
			std::cout << "ID:       " << it->data.id << '\n';
			std::cout << "Email:    " << it->data.email << '\n';
			std::cout << "Address:  " << it->data.address << '\n';
			std::cout << "Phone:    " << it->data.phone << '\n';
			std::cout << "Password: " << it->data.password << '\n';

			it = it->next;
		}
		std::cout << "--------------------------------------------\n";
	}
};

class SHashTable {          // By SEIF ALLAH //
private:
	static const int tsize = 100;
	SRecords table[tsize];
	
	// Helper (hashing) function //
	
	int hash(int s_id) {
		return s_id % tsize;
	}
public:
	void insertStudent(Student newStudent) {
		int index = hash(newStudent.id);
		table[index].addStudent(newStudent);
	}

	Student* searchStudent(int s_id) {
		int index = hash(s_id);
		return table[index].searchStudentLinear(s_id);
	}
};

class PrereqStack {          // By SEIF ALLAH //
private:
	struct Node {
		int courseID;
		Node *next;

		Node(int c_id)
			: courseID(c_id), next(nullptr) {}
		~Node() = default;
	};
	Node *top;
public:
	PrereqStack()
		: top(nullptr) {}
	~PrereqStack() {
		while (top != nullptr) {
			Node *anchor = top;
			top = top->next;
			delete anchor;
		}
	}

	bool empty(void) {
		return top == nullptr;
	}

	int peek(void) {
		if (empty()) throw std::out_of_range("Cannot peek() on an empty Prerequisite Stack.");
		return top->courseID;
	}

	void push(int c_id) {
		Node *newNode = new Node(c_id);
		newNode->next = top;
		top = newNode;
	}

	void pop(void) {
		if (empty()) throw std::out_of_range("Cannot pop() from an empty Prerequisite Stack.");
		Node *anchor = top;
		top = top->next;
		delete anchor;
	}
};

int main(void) {
	std::cout << "=================================\n";
	std::cout << "  Test 1: LINKED LIST & SORTING  \n";
	std::cout << "=================================\n";

	SRecords myRec;
	
	// Add Students (unsorted) //
	std::cout << "[Action] Adding students with IDs: 300, 100, 200...\n";
	myRec.addStudent({300, "Alice", "alice@test.com", "City A", "123", "pass1"});
	myRec.addStudent({100, "Bob", "Bob@test.com", "City B", "456", "pass2"});
	myRec.addStudent({200, "Zeina", "Zeina@test.com", "City C", "789", "pass3"});

	// Display Students (unsorted) //
	std::cout << "\n-------List Before Sorting-------\n";
	myRec.displayStudents();

	// Sorting Students (Using Merge Sort Algorithm) //
	std::cout << "[Action] Calling sortStudents()...\n";
	myRec.sortStudents();

	// Display Students post-sorting //
	std::cout << "\n-------List After Sorting-------\n";
	myRec.displayStudents();

	// Test Binary Search //
	std::cout << "\n[Action] Binary Searching for ID 200...\n";
	Student *st = myRec.searchStudentBinary(200);
	if (st) std::cout << "SUCCESS: Found " << st->name << " (ID: " << st->id << ")\n";
	else std::cout << "FAILED: ID 200 not found.\n";

	std::cout << "=================================\n";
	std::cout << "        Test 2: Hash Table       \n";
        std::cout << "=================================\n";

	SHashTable myHash;

	// Inserting Students //
	std::cout << "[Action] Inserting IDs 105, 205, and 99 into Hash Table...\n";
	myHash.insertStudent({105, "Dave", "dave@test.com", "City D", "000", "pass4"});
	myHash.insertStudent({205, "Eve", "eve@test.com", "City E", "111", "pass5"});
	myHash.insertStudent({99, "Frank", "frank@test.com", "City F", "222", "pass6"});

	// Searching for Students //
	std::cout << "[Actions] Searching for ID 205 (Collision Case)...\n";
	Student *st2 = myHash.searchStudent(205);
	if (st2) std::cout << "SUCCESS: Found " << st2->name << " (ID: " << st2->id << ") in Hash Table.\n";
	else std::cout << "FAILED: ID 205 not found.\n";

	// Searching for non-existent Student //
	std::cout << "[Action] Searching for ID 999 (Non-existent)...\n";
	Student *missing = myHash.searchStudent(999);
	if (!missing) std::cout << "SUCCESS: Correctly returned nullptr for missing student.\n";
	else std::cout << "FAILED: Found a student that shouldn't exist???\n";

	std::cout << "=================================\n";
        std::cout << "    Test 3: Prerequisite Stack   \n";
        std::cout << "=================================\n";

	PrereqStack myStack;

	// Testing empty() method //
	if (myStack.empty()) std::cout << "SUCCESS: Stack is initially empty.\n";

	// Pushing Prerequisites //
	std::cout << "[Action] Pushing courses: 101 -> 102 -> 103\n";
	myStack.push(101);
	myStack.push(102);
	myStack.push(103);

	// Peeking the top element //
	try {
		std::cout << "Top of stack (Peek): " << myStack.peek() << " (Expected: 103)\n";
	} catch (const std::exception &e) {
		std::cout << "ERROR: " << e.what() << '\n';
	}

	// Popping until stack is empty //
	std::cout << "[Action] Popping all items:\n";
	while (!myStack.empty()) {
		std::cout << "Popped: " << myStack.peek() << '\n';
		myStack.pop();
	}

	// Verify Emptiness //
	if (myStack.empty()) std::cout << "SUCCESS: Stack is empty again.\n";

	std::cout << "\n\n=======ALL TESTS ARE COMPLETED=======\n";
	return 0;
}
