#include <iostream>
#include <string>

#include <iostream>
#include <string>

// STRUCT SINH VIEN
struct sv
{
    std::string ho_ten = "";   // luu ho ten sinh vien
    std::string MSSV = "";     // luu ma so sinh vien
    int nam_sinh = -1;         // luu nam sinh
    std::string lop = "";      // luu lop hoc

    // constructor: dung de khoi tao nhanh 1 sinh vien
    sv(std::string n_ho_ten,
       std::string n_MSSV,
       int n_nam_sinh,
       std::string n_lop)
       : ho_ten(n_ho_ten), MSSV(n_MSSV), nam_sinh(n_nam_sinh), lop(n_lop) { }
};

// NODE DANH SACH DON 
struct node {
    sv data;       // du lieu sinh vien
    node* next;    // con tro toi node tiep theo

    // constructor: tao node moi tu du lieu sv
    node(sv x) : data(x), next(nullptr) {}
};

// DANH SACH LIEN KET DON
class Singly_Linked_List {
protected:
    node* first;   // con tro toi node dau tien

public:
    // constructor rong: khoi tao danh sach rong
    Singly_Linked_List() {
        this->first = nullptr;
    }

    // constructor co tham so: tao danh sach co 1 phan tu
    Singly_Linked_List(sv data) {
        this->first = new node(data);
    }

    // destructor: giai phong toan bo bo nho cua danh sach
    ~Singly_Linked_List() {
        node* p = first;
        while (p != nullptr) {
            node* q = p;
            p = q->next;
            delete q; // xoa tung node
        }
    }

    // ham in danh sach sinh vien
    void print() {
        node* temp = first;
        while (temp != nullptr) {
            std::cout << temp->data.ho_ten << "  "
                      << temp->data.MSSV << "  "
                      << temp->data.nam_sinh << "  "
                      << temp->data.lop << std::endl;
            temp = temp->next;
        }
    }

    // ham them 1 sinh vien vao cuoi danh sach
    void add_to_last(sv data) {
        node* p = new node(data);

        if (first == nullptr) {
            first = p;
            return;
        }

        node* temp = first;
        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = p;
    }
};

// DANH SACH LIEN KET VONG
class Circular_Linked_List {
protected:
    node* last;   // con tro toi node cuoi cung

public:
    // constructor rong: danh sach rong
    Circular_Linked_List() {
        this->last = nullptr;
    }

    // constructor co tham so: tao danh sach co 1 node (tu tro chinh no)
    Circular_Linked_List(sv data) {
        this->last = new node(data);
        this->last->next = last; // tro ve chinh no tao vong
    }

    // destructor: giai phong bo nho danh sach vong
    ~Circular_Linked_List() {
        if (last == nullptr) return; // neu rong thi thoat

        node* p = last->next; // node dau
        last->next = nullptr; // cat vong thanh danh sach thuong

        while (p != nullptr) {
            node* q = p;
            p = q->next;
            delete q; // xoa tung node
        }
    }

    // ham in danh sach vong
    void print() {
        if (last == nullptr) return;

        node* temp = last->next; // node dau
        do {
            std::cout << temp->data.ho_ten << "  "
                      << temp->data.MSSV << "  "
                      << temp->data.nam_sinh << "  "
                      << temp->data.lop << std::endl;
            temp = temp->next;
        } while (temp != last->next);
    }

    // ham them node vao cuoi danh sach vong
    void add_to_last(sv data) {
        node* p = new node(data);

        if (last == nullptr) {
            last = p;
            last->next = last;
            return;
        }

        p->next = last->next; // tro ve node dau
        last->next = p;
        last = p;
    }
};

// NODE DANH SACH DOI
struct node_d {
    sv data;         // du lieu sinh vien
    node_d* left;    // con tro ve node truoc
    node_d* right;   // con tro toi node sau

    // constructor: khoi tao node doi
    node_d(sv x) : data(x), left(nullptr), right(nullptr) {}
};

// DANH SACH LIEN KET DOI
class Doubly_Linked_List {
protected:
    node_d* first;   // con tro toi node dau

public:
    // constructor rong
    Doubly_Linked_List() {
        this->first = nullptr;
    }

    // constructor co tham so
    Doubly_Linked_List(sv data) {
        this->first = new node_d(data);
    }

    // destructor: giai phong bo nho
    ~Doubly_Linked_List() {
        node_d* p = first;
        while (p != nullptr) {
            node_d* q = p;
            p = q->right;
            delete q;
        }
    }

    // ham in danh sach
    void print() {
        node_d* temp = first;
        while (temp != nullptr) {
            std::cout << temp->data.ho_ten << "  "
                      << temp->data.MSSV << "  "
                      << temp->data.nam_sinh << "  "
                      << temp->data.lop << std::endl;
            temp = temp->right;
        }
    }

    // ham them vao cuoi danh sach doi
    void add_to_last(sv data) {
        node_d* p = new node_d(data);

        if (first == nullptr) {
            first = p;
            return;
        }

        node_d* temp = first;
        while (temp->right != nullptr)
            temp = temp->right;

        temp->right = p;
        p->left = temp;
    }
};

int main() {

    // tao 3 danh sach
    Singly_Linked_List ds_don;
    Circular_Linked_List ds_vong;
    Doubly_Linked_List ds_kep;

    // du lieu theo de
    sv sv1("Nguyen Hoa Hau", "20093", 2002, "D20");
    sv sv2("Do Luc Si", "20079", 2000, "D20");
    sv sv3("Ly Minh Tinh", "21085", 2003, "D21");
    sv sv4("Tran Dai Gia", "21096", 2003, "D21");
    sv sv5("Duong Vo Su", "18011", 2000, "D18");

    // them vao cuoi
    ds_don.add_to_last(sv1);
    ds_don.add_to_last(sv2);
    ds_don.add_to_last(sv3);
    ds_don.add_to_last(sv4);
    ds_don.add_to_last(sv5);

    ds_vong.add_to_last(sv1);
    ds_vong.add_to_last(sv2);
    ds_vong.add_to_last(sv3);
    ds_vong.add_to_last(sv4);
    ds_vong.add_to_last(sv5);

    ds_kep.add_to_last(sv1);
    ds_kep.add_to_last(sv2);
    ds_kep.add_to_last(sv3);
    ds_kep.add_to_last(sv4);
    ds_kep.add_to_last(sv5);

    // in ra
    std::cout << "\nDSLK DON\n";
    ds_don.print();

    std::cout << "\nDSLK VONG\n";
    ds_vong.print();

    std::cout << "\nDSLK KEP\n";
    ds_kep.print();

    return 0;
}