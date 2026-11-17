#include <iostream>
using namespace std;

int main() {
    int penjualan [4][5] ;
    int totalProduk [4];
    int totalHari [5];

    cout << "Input Data Penjualan: ";
    for (int i = 0; i < 4; i++) {
        cout << "Produk" << i +1 << ": ";
        for (int j = 0; j < 5; j++) {
            cout << "  Hari " << j + 1 << ": ";
            cin >> penjualan[i][j];
        }
    }

    for (int i = 0; i < 4; i++) {   //  hitung penjualan prodk per hari.
        for (int j = 0; j < 5; j++) {
            totalProduk[i] += penjualan[i][j];
            totalHari[j] += penjualan[i][j];
        }
    }

    int maxProdukIdx = 0;           //produk total tertingi
    for (int i = 1; i < 4; i++) {
        if (totalProduk[i] > totalProduk[maxProdukIdx]) {
            maxProdukIdx = i;
        }
    }

    int minHariIdx = 0;             // produk total terendah
    for (int j = 1; j < 5; j++) {
        if (totalHari[j] < totalHari[minHariIdx]) {
            minHariIdx = j;
        }
    }

    cout << "Total penjualan per produk: ";
    for (int i = 0; i <4; i++) {
        cout<< " Produk" << i + 1<< ": " << totalProduk[i]<< endl;
    }

    cout << "Total penjualan per hari: ";
    for (int j = 0; j < 5; j++) {
        cout << " Hari" << j + 1 << ": " << totalHari[j] << endl;
    }

    cout << "Produk dengan total penjualan tertinggi: Produk " << maxProdukIdx + 1 << " (" << totalProduk[maxProdukIdx] << ")" << endl;
    cout << "Hari dengan total penjualan terendah: Hari " << minHariIdx + 1 << " (" << totalHari[minHariIdx] << ")";

    return 0;
}