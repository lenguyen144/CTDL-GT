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

class Singly_Linked_List {
private:
    node* head;

    // tron 2 danh sach da sap xep
    node* merge(node* a, node* b) {
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

    // tim node giua
    node* getMiddle(node* head) {
        if (!head) return head;

        node* slow = head;
        node* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    // merge sort
    node* mergeSort(node* head) {
        if (!head || !head->next)
            return head;

        node* mid = getMiddle(head);
        node* half = mid->next;
        mid->next = nullptr;

        node* left = mergeSort(head);
        node* right = mergeSort(half);

        return merge(left, right);
    }

public:
    Singly_Linked_List() {
        head = nullptr;
    }

    // them vao cuoi
    void add_to_last(sv data) {
        node* p = new node(data);

        if (!head) {
            head = p;
            return;
        }

        node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = p;
    }

    // sap xep
    void sort_MSSV() {
        head = mergeSort(head);
    }

    // in danh sach
    void print() {
        node* p = head;
        while (p) {
           std::cout << p->data.ho_ten << " - "
                 << p->data.MSSV << " - "
                 << p->data.nam_sinh << " - "
                 << p->data.lop << std::endl;
            p = p->next;
        }
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
    void sort_merge_MSSV() {
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
    // ===== KHOI TAO DU LIEU =====
    sv ds[] = {
        {"Nguyen Hoa Hau", 20093, 2002, "D20"},
        {"Do Luc Si", 20079, 2000, "D20"},
        {"Ly Minh Tinh", 21085, 2003, "D21"},
        {"Tran Dai Gia", 21096, 2003, "D21"},
        {"Duong Vo Su", 18011, 2000, "D18"}
    };

    // ===== DSLK DON =====
    Singly_Linked_List d1;
    for (int i = 0; i < 5; i++) {
        d1.add_to_last(ds[i]);
    }

    std::cout << "=== DSLK DON BAN DAU ===\n";
    d1.print();

    d1.sort_MSSV();
    std::cout << "\n=== DSLK DON SAU MERGE SORT ===\n";
    d1.print();

    // ===== DSLK VONG =====
    Circular_Linked_List d2;
    for (int i = 0; i < 5; i++) {
        d2.add_to_last(ds[i]);
    }

    std::cout << "\n=== DSLK VONG BAN DAU ===\n";
    d2.print();

    d2.sort_merge_MSSV();
    std::cout << "\n=== DSLK VONG SAU MERGE SORT ===\n";
    d2.print();

    // ===== INSERTION SORT TREN DSLK VONG =====
    Circular_Linked_List d3;
    for (int i = 0; i < 5; i++) {
        d3.add_to_last(ds[i]);
    }

    d3.sort_insertion_MSSV();
    std::cout << "\n=== DSLK VONG SAU INSERTION SORT ===\n";
    d3.print();

    return 0;
}