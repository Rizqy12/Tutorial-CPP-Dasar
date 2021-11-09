#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;
//struct mahasiswa
struct mahasiswa{
    int pk;
    string nama;
    string jurusan;
    string nim;
};

//proto-type
int getoption();    //untuk menu
void writedata(mahasiswa &mhs ,fstream &data); //untuk nulis data ke-ekstenal file
void readdata(mahasiswa &mhs , fstream &data); //untuk menampilkan data

//body program
int main(){

    fstream database, outdatabase;  //database ios::out | outdatabase ios::in
    mahasiswa mahasiswapolmed, outputmhs;   //mahasiswapolmed = input | outputmhs = output

    //menu
    int choice = getoption();
    enum {create = 1, read, size, finish};
    char next;
    
    while(choice != finish){
        switch (choice)        {
        case create:
            system("cls");
            cout << "> Menambahkan Data Mahasiswa" << endl << endl;
            writedata(mahasiswapolmed, database);
            break;
        
        case read:
            system("cls");
            cout << "> Menampilkan Data Mahasiswa" << endl << endl;
            readdata(outputmhs, outdatabase);
            break;
        
        case size:
            system("cls");
            cout << "> Menampilkan Ukuran Data Mahasiswa" << endl << endl;
            cout << "Ukuran Sturct : " << sizeof(mahasiswa) << endl;
            cout << "Ukuran Variabel Struct : " << sizeof(mahasiswapolmed) << endl;
            break;

        default:
            cout << "Pilihan Tidak Ditemukan !" << endl;
            break;
        }
        label_continue:
        cout << endl;
        cout << "Lanjutkan (y/n) ? = ";
        cin >> next;
        if ((next == 'y') | (next == 'Y')){
            choice = getoption();
        } else if ((next == 'n') | (next == 'N')){
            break;
        } else{
            goto label_continue;
        }
    }

    cin.get();
    return 0;
}
//fungsi return untuk get option
int getoption(){
    int input;
    system("cls");
    cout << "| Program Create And Read |\n" << endl;
    cout << "[1] Tambah Data" << endl;
    cout << "[2] Baca Data" << endl;
    cout << "[3] Ukuran Data" << endl;
    cout << "[4] Selesai" << endl << endl;
    cout << "Pilih [1-4] ? : ";
    cin >> input;
    return input;
}
//fungsi void untuk write data
void writedata(mahasiswa &mhs ,fstream &data){
    cout << "ID. "; cin >> mhs.pk;
    cout << "Nama   : "; getline(cin,mhs.nama);
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "Jurusan: "; cin >> mhs.jurusan;
    cout << "Nim    : "; cin >> mhs.nim;
    data.open("mahasiswa.txt", ios::out | ios::app);
    data << mhs.pk << "\t";
    data << mhs.nama << "\t";
    data << mhs.jurusan << "\t";
    data << mhs.nim << endl;
    data.close();
}
//fungsi void untuk baca data
void readdata(mahasiswa &mhs , fstream &data){
    data.open("mahasiswa.txt", ios::in);
    data >> mhs.pk;
    data >> mhs.nama;
    data >> mhs.jurusan;
    data >> mhs.nim;
    //tampilan diconsole
    cout << "ID \t" << "NAMA \t\t" << "PRODI \t" << "NIM" << endl;
    while(!data.eof()){
        cout << mhs.pk << "\t";
        cout << mhs.nama << "\t\t";
        cout << mhs.jurusan << "\t";
        cout << mhs.nim << endl;
        
        data >> mhs.pk;
        data >> mhs.nama;
        data >> mhs.jurusan;
        data >> mhs.nim;
    }
    data.close();
}
