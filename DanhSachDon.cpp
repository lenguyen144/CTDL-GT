#include <iostream>
#include <string>

using namespace std;

struct SinhVien {				// thong tin sv
    string hoTen;
    int maSV;
    int namSinh;
    string lop;
};

struct Node {
    SinhVien data;
    Node* next;
};

Node* createNode(SinhVien sv) {					// tao node
    Node* newNode = new Node;
    if (newNode == NULL) {
        return NULL;
    }
    newNode->data = sv;
    newNode->next = NULL;
    return newNode;
}

void addTail(Node* &head, SinhVien sv) {			// them node cuoi
    Node* newNode = createNode(sv);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

SinhVien nhapThongTin() {							// nhap thong tin sv
    SinhVien sv;
    cout << "Nhap Ho ten: ";
    getline(cin, sv.hoTen);
    cout << "Nhap Ma SV: ";
    cin >> sv.maSV;
    cout << "Nhap Nam sinh: ";
    cin >> sv.namSinh;
    cout << "Nhap Lop: ";
    cin >> sv.lop;
    cin.ignore();
    return sv;
}


int main() {
    Node* head = NULL;
    int n;
    
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin sinh vien thu " << i + 1 << ":" << endl;
        SinhVien sv = nhapThongTin();
        addTail(head, sv);
    }

   

    return 0;
}
