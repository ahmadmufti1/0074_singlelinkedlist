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

        Node * nodeBaru = new Node(); // membuat node baru dengan menggunakan operator new
        nodeBaru->noMhs = nim; // mengisi data nomor mahasiswa pada node baru dengan nilai yang dimasukkan oleh user
        
        if (START == NULL || nim <= START->noMhs) 
        {
            if (START != NULL && nim == START->noMhs) {
                cout << "\nDuplikasi noMhs tidak dijinkan.\n";
                return;
            }

            nodeBaru->next = START;
            START = nodeBaru;
            return;
        }
        Node * previous = START; // pointer untuk menyimpan alamat node sebelumnya, diinisialisasi dengan START
        Node * current = START; // pointer untuk menyimpan alamat node saat ini, diinis

        while (current != NULL && nim > current->noMhs)
        {
            if (nim == current->noMhs) 
            {
                cout << "\nDuplikasi noMhs tidak dijinkan.\n";
                return;
            }
            previous = current;
            current = current->next;
        }
        nodeBaru->next = current;
        previous->next = nodeBaru;
    }

};
