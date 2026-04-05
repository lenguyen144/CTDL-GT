#include <iostream>
#include <string>

struct sv
{
	std::string ho_ten = "";
	int MSSV = -1;
	int nam_sinh = -1;
	std::string lop = "";

	sv(std::string n_ho_ten,
		int n_MSSV,
		int n_nam_sinh,
		std::string n_lop) : ho_ten(n_ho_ten), MSSV(n_MSSV), nam_sinh(n_nam_sinh), lop(n_lop) {
	}

};

struct node {
	sv data;
	node* next;
	node(sv x) : data(x), next(nullptr) {}
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

	void add_to_last(sv data) {
		if (this->last == nullptr) {
			this->last = new node(data);
			this->last->next = last;

			return;
		}

		node* p = new node(data);
		p->next = last->next;

		last->next = p;
		last = p;

	}

};



int main() {


	return 0;
}