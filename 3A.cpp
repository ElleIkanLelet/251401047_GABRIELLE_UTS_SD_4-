#include <iostream>
#include <string>
using namespace std;

#define MAX 100

struct Stack {
    char data[MAX];
    int top = -1;
};

int main() {
    Stack s;
    string kata;

    cout << "Masukkan kata: ";
    cin >> kata;

    for (int i = 0; i < kata.length(); i++) {      //push karakter ke stakc
        if (s.top < MAX - 1) {
            s.top++;
            s.data[s.top] = kata[i];
        }
    }

    bool isPalindrome = true;           // pop, lalu bandingkan dgn kata asli
    for (int i = 0; i < kata.length(); i++) {
        char charKeluar;
        if (s.top != -1) {
            charKeluar = s.data[s.top];
            s.top--;
        }

        if (kata[i] != charKeluar) {
            isPalindrome = false;
            break;
        }
    }

    if (isPalindrome) {
        cout << " " << kata << " adalah kata palindrome." << endl;
    } else {
        cout << " " << kata << " bukanlah kata palindrome." << endl;
    }

    return 0;
}