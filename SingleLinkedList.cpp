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

    bool listEmpty() // fungsi untuk memeriksa apakah linked list kosong atau tidak
    {
        return START == NULL; // mengembalikan true jika START bernilai NULL, artinya linked list kosong
    }

    bool search(int nim, Node *&previous, Node *&current) // fungsi untuk mencari node dengan nomor mahasiswa tertentu
    {
        previous = START; // menginisialisasi pointer previous dengan START
        current = START; // menginisialisasi pointer current dengan START

        while (current != NULL && nim != current->noMhs)
        {
            previous = current; // update pointer previous ke current
            current = current->next; // update pointer current ke node selanjutnya
        }

        return (current != NULL);
    }

    bool delNode(int nim) // fungsi untuk menghapus node dengan nomor mahasiswa tertentu
    {
        Node * previous, * current;
        if (!search(nim, previous, current)) 
        {
            return false; // jika node tidak ditemukan, kembalikan false
        }

        if (current == START) // jika node yang akan dihapus adalah node pertama (START)
        {
            START = START->next; // update START ke node berikutnya
        }
        else
        {
            previous->next = current->next; // update pointer next pada node sebelumnya ke node setelah current
        }
        delete current; // menghapus node current dari memori
        return true; // kembalikan true setelah berhasil menghapus node
    }

    void traverse() //Untuk menampilkan list yang ada
    {
        if (listEmpty()) // memeriksa apakah linked list kosong
        {
            cout << "\nList Kosong\n"; // jika kosong, tampilkan pesan
        }
        else
        {
            cout << "\nData dalam list: \n"; // jika tidak kosong, tampilkan data dalam list
            Node * currentNode = START;

            while (currentNode != NULL)
            {
                cout << currentNode->noMhs << " "; // tampilkan nomor mahasiswa pada node saat ini
                currentNode = currentNode->next; // update currentNode ke node berikutnya
            }
            cout << endl; 
        }
    }
};
