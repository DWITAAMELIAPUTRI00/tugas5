#include <iostream>
#include <string>

using namespace std;

struct Mahasiswa {
    string npm;
    string nama;
    float nilaiMid;
    float nilaiSemester;
    float nilaiAkhir;
    char nilaiHuruf;
};

float hitungNilaiAkhir(float nilaiMid, float nilaiSemester) {
    return (0.4 * nilaiMid) + (0.6 * nilaiSemester);
}

// Menentukan nilai huruf
char tentukanNilaiHuruf(float nilaiAkhir) {
    if (nilaiAkhir >= 80) {
        return 'A';
    } else if (nilaiAkhir >= 70) {
        return 'B';
    } else if (nilaiAkhir >= 55) {
        return 'C';
    } else if (nilaiAkhir >= 40) {
        return 'D';
    } else {
        return 'E';
    }
}

int main() {
    Mahasiswa mhs[100];
    int jumlahMahasiswa;

    // Input jumlah mahasiswa
    cout << "Masukkan jumlah mahasiswa (maksimal 100): ";
    cin >> jumlahMahasiswa;

    // Validasi jumlah mahasiswa
    if (jumlahMahasiswa < 1 || jumlahMahasiswa > 100) {
        cout << "Jumlah mahasiswa harus antara 1 dan 100." << endl;
        return 1;
    }

    // Input data mahasiswa
    for (int i = 0; i < jumlahMahasiswa; i++) {
        cout << "\nData Mahasiswa ke-" << (i + 1) << endl;

        cout << "NPM: ";
        cin >> mhs[i].npm;
        
        cout << "Nama: ";
        cin.ignore();  
        getline(cin, mhs[i].nama);

        cout << "Nilai Mid: ";
        cin >> mhs[i].nilaiMid;

        cout << "Nilai Semester: ";
        cin >> mhs[i].nilaiSemester;

        // Hitung nilai akhir
        mhs[i].nilaiAkhir = hitungNilaiAkhir(mhs[i].nilaiMid, mhs[i].nilaiSemester);
        
        // Tentukan nilai huruf
        mhs[i].nilaiHuruf = tentukanNilaiHuruf(mhs[i].nilaiAkhir);
    }

    // Tampilkan hasilnya
    cout << "\n\nHasil Perhitungan Nilai Akhir dan Nilai Huruf\n";
    cout << "=====================================================================\n";
    cout << "No | NPM       | Nama                | Nilai Mid | Nilai Semester | Nilai Akhir | Nilai Huruf\n";
    cout << "---------------------------------------------------------------------\n";
    for (int i = 0; i < jumlahMahasiswa; i++) {
        cout << (i + 1) << "  | " 
             << mhs[i].npm << " | " 
             << mhs[i].nama << " | " 
             << mhs[i].nilaiMid << "    | " 
             << mhs[i].nilaiSemester << "        | " 
             << mhs[i].nilaiAkhir << "       | " 
             << mhs[i].nilaiHuruf << "\n";
    }
    cout << "=====================================================================\n";

    return 0;
}
