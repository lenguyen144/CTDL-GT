#include <iostream>
#include <string>
using namespace std;

// cau truc sinh vien
struct SinhVien {
    string hoTen;
    int maSV;
    int namSinh;
    string lop;
};

// ham tron hai mang con da duoc sap xep
void merge(SinhVien a[], int l, int m, int r) {
    int n1 = m - l + 1; // so phan tu mang trai
    int n2 = r - m;     // so phan tu mang phai

    // tao mang tam
    SinhVien L[n1], R[n2];

    // sao chep du lieu vao mang tam
    for (int i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];

    int i = 0, j = 0, k = l;

    // tron hai mang theo thu tu tang dan cua maSV
    while (i < n1 && j < n2) {
        if (L[i].maSV <= R[j].maSV) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    // neu con phan tu o mang trai
    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }

    // neu con phan tu o mang phai
    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}

// ham merge sort de quy
void mergeSort(SinhVien a[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2; // tim diem giua

        // chia mang thanh 2 nua
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);

        // tron hai nua da sap xep
        merge(a, l, m, r);
    }
}

int main() {
    // khoi tao danh sach sinh vien
    SinhVien ds[] = {
        {"Nguyen Hoa Hau", 20093, 2002, "D20"},
        {"Do Luc Si", 20079, 2000, "D20"},
        {"Ly Minh Tinh", 21085, 2003, "D21"},
        {"Tran Dai Gia", 21096, 2003, "D21"},
        {"Duong Vo Su", 18011, 2000, "D18"}
    };

    int n = 5;

    // goi ham sap xep
    mergeSort(ds, 0, n - 1);

    // in ket qua
    cout << "Danh sach sau khi sap xep:\n";
    for (int i = 0; i < n; i++) {
        cout << ds[i].hoTen << " - "
             << ds[i].maSV << " - "
             << ds[i].namSinh << " - "
             << ds[i].lop << endl;
    }

    return 0;
}