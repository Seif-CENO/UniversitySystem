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

	Student* searchStudentLinear(int s_id) {
		Node *it = head;
		while (it != nullptr) {
			if (it->data.id == s_id) return &it->data;
			it = it->next;
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

int main(void) {
	
	return 0;
}
