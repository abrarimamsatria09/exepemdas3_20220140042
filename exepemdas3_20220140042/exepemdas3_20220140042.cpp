#include <iostream>
#include <string>
using namespace std;

class Penerbit {
public:
    Penerbit(const std::string& nama) : namaPenerbit(nama) {}

    std::string getNamaPenerbit() const {
        return namaPenerbit;
    }

private:
    std::string namaPenerbit;
};

class Pengarang {
public:
    Pengarang(const std::string& nama, Penerbit* p) : namaPengarang(nama), penerbit(p) {}

    std::string getNamaPengarang() const {
        return namaPengarang;
    }

    std::string getNamaPenerbit() const {
        if (penerbit != nullptr) {
            return penerbit->getNamaPenerbit();
        }
        else {
            return "Tidak ada penerbit";
        }
    }

private:
    std::string namaPengarang;
    Penerbit* penerbit;
};

class Buku {
public:
    Buku(const std::string& judul, Pengarang* pengarang) : judulBuku(judul), pengarang(pengarang) {}

    std::string getJudulBuku() const {
        return judulBuku;
    }

    std::string getNamaPengarang() const {
        if (pengarang != nullptr) {
            return pengarang->getNamaPengarang();
        }
        else {
            return "Tidak ada pengarang";
        }
    }

private:
    std::string judulBuku;
    Pengarang* pengarang;
};

int main() {
    Penerbit gamaPress("Gama Press");
    Penerbit intanPariwara("Intan Pariwara");

    Pengarang joko("Joko", &gamaPress);
    Pengarang lia("Lia", &gamaPress);
    Pengarang asroni("Asroni", &intanPariwara);
    Pengarang giga("Giga", &gamaPress);

    Buku fisika("Fisika", &joko);
    Buku algoritma("Algoritma", &joko);
    Buku basisData("Basisdata", &lia);
    Buku dasarPemrograman("Dasar Pemrograman", &asroni);
    Buku matematika("Matematika", &giga);
    Buku multimedia1("Multimedia 1", &giga);

    std::cout << "Daftar pengarang pada penerbit \"Gama Press\":\n";
    std::cout << joko.getNamaPengarang() << "\n";
    std::cout << lia.getNamaPengarang() << "\n";
    std::cout << giga.getNamaPengarang() << "\n\n";

    std::cout << "Daftar pengarang pada penerbit \"Intan Pariwara\":\n";
    std::cout << asroni.getNamaPengarang() << "\n";
    std::cout << giga.getNamaPengarang() << "\n\n";

    std::cout << "Daftar penerbit yang diikuti \"Giga\":\n";
    std::cout << joko.getNamaPenerbit() << "\n";
    std::cout << lia.getNamaPenerbit() << "\n\n";

    std::cout << "Daftar buku yang dikarang \"Joko\":\n";
    std::cout << fisika.getJudulBuku() << "\n";
    std::cout << algoritma.getJudulBuku() << "\n\n";

    return 0;
}