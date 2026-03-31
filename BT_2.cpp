#include <iostream>
#include <string>

struct sv
{
	std::string ho_ten = "";
	std::string MSSV = "";
	int nam_sinh = -1;
	std::string lop = "";

	sv(	std::string n_ho_ten,
		std::string n_MSSV,
		int n_nam_sinh,
		std::string n_lop): ho_ten(n_ho_ten), MSSV(n_MSSV), nam_sinh(n_nam_sinh), lop(n_lop) { }

};

struct node {
	sv data;
	node* next;
	node(sv x) : data(x), next(nullptr) {}
};


class Singly_Linked_List {
private:

protected:
	node* first;

public:
	Singly_Linked_List() {
		this->first = nullptr;
	}

	Singly_Linked_List(sv data) {
		this->first = new node(data);
	}

	~Singly_Linked_List() {
		node* p = first;
		while (p != nullptr) {
			node* q = p;
			p = q->next;
			delete q;
		}
	}

	void print();

	void add_to_last(sv data);    //tan
};

class Circular_Linked_List {
private:

protected:
	node* last;

public:
	Circular_Linked_List() {
		this->last = nullptr;
	}

	Circular_Linked_List(sv data) {
		this->last = new node(data);
		this->last->next = last;
	}

	~Circular_Linked_List() {
		node* p = last->next;
		last->next = nullptr;

		while (p != nullptr) {
			node* q = p;
			p = q->next;
			delete q;
		}
	}

	void print();

	void add_to_last(sv data);
};

struct node_d {
	sv data;
	node_d* left;
	node_d* right;

	node_d(sv x) : data(x), left(nullptr), right(nullptr) {}
};

class Doubly_Linked_List {
private:

protected:
	node_d* first;

public:
	Doubly_Linked_List() {
		this->first = nullptr;
	}

	Doubly_Linked_List(sv data) {
		this->first = new node_d(data);
	}

	~Doubly_Linked_List() {
		node_d* p = first;
		while (p != nullptr) {
			node_d* q = p;
			p = q->right;
			delete q;
		}
	}

	void print();

	void add_to_last(sv data);
};

int main() {
	std::cout << "tai la hoc tro cung thay thinh" << std::endl;

	return 0;
}