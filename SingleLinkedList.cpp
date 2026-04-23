#include <iostream> // library untuk input output
#include <string>// library untuk string
using namespace std;


class Node { // class untuk node
    public: // public agar bisa diakses dari luar class
    int noMhs; // data yang akan disimpan dalam node, dalam hal ini nomor mahasiswa
    Node * next; // pointer untuk menyimpan alamat node selanjutnya
};

class LinkedList{ // class untuk linked list
    Node * START; // pointer untuk menyimpan alamat node pertama dalam linked list

    public: // public agar bisa diakses dari luar class
    
    LinkedList()
    {
        START = NULL; //untuk menginisialisasi START dengan NULL
    }

    void addNode() // fungsi untuk menambahkan node baru ke dalam linked list
    {
        int nim; // variabel untuk menyimpan nomor mahasiswa yang akan dimasukkan ke dalam node baru
        cout << "\nMasukkan Nomor Mahasiswa: ";
        cin >> nim;

        
    }

};
