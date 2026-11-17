#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node* head = nullptr;
    int n, val, limit, target;

    cout << "Masukkan jumlah data peserta: ";
    cin >> n;

    // sorted insertion
    for (int i = 0; i < n; i++) {
        cout << "Masukkan nomor peserta ke-" << i + 1 << ": ";
        cin >> val;

        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = nullptr;

        if (head == nullptr || head->data >= val) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* curr = head;
            while (curr->next != nullptr && curr->next->data < val) {
                curr = curr->next;
            }
            newNode->next = curr->next;
            curr->next = newNode;
        }
    }

    // menampilkan isi linked list
    cout << "Isi Linked List (Terurut): ";
    Node* temp = head;
    if (temp == nullptr) {
        cout << "Linked list kosong.";
    } else {
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) {
                cout << " -> ";
            }
            temp = temp->next;
        }
    }
    cout << endl;

    // cari nomor peserta
    cout << "Masukkan nomor peserta yang ingin dicari: ";
    cin >> target;
    bool ketemu = false;
    temp = head;
    while (temp != nullptr) {
        if (temp->data == target) {
            ketemu = true;
            break;
        }
        temp = temp->next;
    }

    if (ketemu) {
        cout << "Nomor peserta " << target << " DITEMUKAN dalam list." << endl;
    } else {
        cout << "Nomor peserta " << target << " TIDAK DITEMUKAN." << endl;
    }

    // hapus node di bawah batas tertentu
    cout << "Masukkan batas nilai minimal penghapusan: ";
    cin >> limit;

    while (head != nullptr && head->data < limit) {
        Node* hapus = head;
        head = head->next;
        delete hapus;
    }

    Node* curr = head;
    while (curr != nullptr && curr->next != nullptr) {
        if (curr->next->data < limit) {
            Node* hapus = curr->next;
            curr->next = curr->next->next;
            delete hapus;
        } else {
            curr = curr->next;
        }
    }

    // menaampilkan isi Linked List setelah penghapusan
    cout << "Isi Linked List setelah penghapusan (node < " << limit << "): ";
    temp = head;
    if (temp == nullptr) {
        cout << "Linked list kosong.";
    } else {
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) {
                cout << " -> ";
            }
            temp = temp->next;
        }
    }
    cout << endl;

    return 0;
}