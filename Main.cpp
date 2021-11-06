#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct mahasiswa{
    int pk;
    int nim;
    string nama;
    string jurusan;
};
//proto-type
int getoption();
void writedata(mahasiswa &mhs, fstream &data);
mahasiswa bacadata(mahasiswa &baca, fstream &data);
void checkdatabase(fstream &data);

int main(){
    mahasiswa inputmahasiswa;
    fstream file;
    checkdatabase(file);
    
    int choice = getoption();
    enum {create = 1, read, selesai};
    char next;

    while (choice != selesai){
        switch (choice){
        case create:
            system ("cls");
            cout << "> Menambahkan Data Mahasiswa" << endl;
            cout << endl;
            writedata(inputmahasiswa, file);
            break;

        case read:
            system ("cls");
            cout << "> Menampilkan Data Mahasiswa" << endl;
            cout << endl;
            bacadata(inputmahasiswa, file);
            break;

        default:
            break;
        }
        label_continue:
        cout << endl;
        cout << "Lanjutkan (y/n) ? : ";
        cin >> next;
        if ((next == 'y') | (next == 'Y')){
            choice = getoption();
        }else if((next == 'n') | (next == 'N')){
            break;
        }else {
            goto label_continue;
        }
    }

    
    file.close();
    cin.get();
    return 0;
}
//fungsi return untuk getoption
int getoption(){
    int input;
    //system("cls");
    cout << "| Program Create And Read |" << endl << endl;
    cout << "[1] Tambah Data" << endl;
    cout << "[2] Baca Data" << endl;
    cout << "[3] Selesai" << endl << endl;
    cout << "Pilih (1-3) ? > ";
    cin >> input;
    return input;
}
//fungsi void untuk nulis data
void writedata(mahasiswa &mhs, fstream &data){
    cout << "Nama   : "; cin >> mhs.nama;
    cout << "Jurusan: "; cin >> mhs.jurusan;
    cout << "Nim    : "; cin >> mhs.nim;
    data.write(reinterpret_cast<char*> (&mhs), sizeof(mahasiswa));
}
//fungsi return untuk baca data
mahasiswa bacadata(mahasiswa &baca, fstream &data){
    data.read(reinterpret_cast<char*>(&baca), sizeof(mahasiswa));
    cout << "Nama\t" << "Prodi\t" << "NIM" << endl;
    cout << baca.nama << "\t" << baca.jurusan << "\t" << baca.nim << endl;
    return baca;
}
//fungsi void untuk checkdatabase
void checkdatabase(fstream &data){
	data.open("mahasiswa.bin", ios::out | ios:: in | ios::binary);
	
	if (data.is_open()){
		cout << "Data ditemukan \n";
	}else {
		cout << "Data tidak ada dan buat baru \n";
		data.close();
		data.open("mahasiswa.bin", ios::trunc | ios::out | ios::in | ios::binary);
	}
}