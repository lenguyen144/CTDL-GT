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
class MergeSortList {
public:
    static node* merge(node* a, node* b) {
        if (!a) return b;
        if (!b) return a;

        if (a->data.MSSV <= b->data.MSSV) {
            a->next = merge(a->next, b);
            return a;
        } else {
            b->next = merge(a, b->next);
            return b;
        }
    }

    static node* getMiddle(node* head) {
        if (!head) return head;

        node* slow = head;
        node* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    static node* mergeSort(node* head) {
        if (!head || !head->next)
            return head;

        node* mid = getMiddle(head);
        node* half = mid->next;
        mid->next = nullptr;

        node* left = mergeSort(head);
        node* right = mergeSort(half);

        return merge(left, right);
    }
};
class InsertionSortList {
public:
    static node* insertionSort(node* head) {
        if (!head) return head;

        node* sorted = nullptr;
        node* current = head;

        while (current) {
            node* next = current->next;

            if (!sorted || current->data.MSSV < sorted->data.MSSV) {
                current->next = sorted;
                sorted = current;
            } else {
                node* temp = sorted;
                while (temp->next && temp->next->data.MSSV < current->data.MSSV) {
                    temp = temp->next;
                }
                current->next = temp->next;
                temp->next = current;
            }

            current = next;
        }

        return sorted;
    }
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
	    if (!last) return;
	
	    node* p = last->next;
	    last->next = nullptr;
	
	    while (p != nullptr) {
	        node* q = p;
	        p = q->next;
	        delete q;
	    }
	}

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
	 void print() {
        if (!last) return;

        node* p = last->next;
        do {
            std::cout << p->data.ho_ten << " - "
                 << p->data.MSSV << " - "
                 << p->data.nam_sinh << " - "
                 << p->data.lop << std::endl;
            p = p->next;
        } while (p != last->next);
    }


    // ham sap xep merge sort
    void sort_MSSV() {
        if (!last || last->next == last) return;

        // cat vong
        node* head = last->next;
        last->next = nullptr;

        // goi merge sort
        head = MergeSortList::mergeSort(head);

        // noi lai vong
        node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }

        temp->next = head;
        last = temp;
    }
    //ham sap xep  Insertion sort
    void sort_insertion_MSSV() {
	    if (!last || last->next == last) return;
	
	    node* head = last->next;
	    last->next = nullptr;
	
	    head = InsertionSortList::insertionSort(head);
	
	    node* temp = head;
	    while (temp->next) {
	        temp = temp->next;
	    }
	
	    temp->next = head;
	    last = temp;
	}
};
int main() {
    Circular_Linked_List ds;

    ds.add_to_last(sv("Nguyen Hoa Hau", 20093, 2002, "D20"));
    ds.add_to_last(sv("Do Luc Si", 20079, 2000, "D20"));
    ds.add_to_last(sv("Ly Minh Tinh", 21085, 2003, "D21"));
    ds.add_to_last(sv("Tran Dai Gia", 21096, 2003, "D21"));
    ds.add_to_last(sv("Duong Vo Su", 18011, 2000, "D18"));

    std::cout << "Truoc khi sap xep:\n";
    ds.print();

    ds.sort_MSSV();

    std::cout << "\nSau khi sap xep:\n";
    ds.print();
    Circular_Linked_List ds2;

	ds2.add_to_last(sv("Nguyen Hoa Hau", 20093, 2002, "D20"));
	ds2.add_to_last(sv("Do Luc Si", 20079, 2000, "D20"));
	ds2.add_to_last(sv("Ly Minh Tinh", 21085, 2003, "D21"));
	ds2.add_to_last(sv("Tran Dai Gia", 21096, 2003, "D21"));
	ds2.add_to_last(sv("Duong Vo Su", 18011, 2000, "D18"));
	
	std::cout << "\nInsertion Sort:\n";
	std::cout << "Truoc:\n";
	ds2.print();
	
	ds2.sort_insertion_MSSV();
	
	std::cout << "Sau:\n";
	ds2.print();

	return 0;
}
