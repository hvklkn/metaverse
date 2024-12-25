#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <stdexcept>
#include <limits>

using namespace std;

class karakter {
private:
    int kimlikid;
public:
    float para;
    float aclik;
    float susuzluk;
    bool uyku;
    float guc;
    int x, y;

    void getpara(float para) { this->para = para; };
    void getaclik(float aclik) { this->aclik = aclik; };
    void getsusuzluk(float susuzluk) { this->susuzluk = susuzluk; };
    void getguc(float guc) { this->guc = guc; };

    float setpara() { return para; };
    float setaclik() { return aclik; };
    float setsusuzluk() { return susuzluk; };
    float setguc() { return guc; };

    void aclikdurumu();
    void susuzlukdurumu();
    void yemekYedir();
    void suIc();
    void hareket(int x, int y);
    void hareket(float distance);
    void durumGoster();
};

void karakter::aclikdurumu() {
    while (true) {
        aclik -= 5;
        if (aclik <= 20) {
            cout << "Karakter yemek yedi. Açlık sorunu giderildi.";
            aclik = 100;
        }
        this_thread::sleep_for(chrono::seconds(10));
    }
}

void karakter::susuzlukdurumu() {
    while (true) {
        susuzluk -= 5;
        if (susuzluk <= 20) {
            cout << "Karakter su içti. Susuzluk sorunu giderildi.";
            susuzluk = 100;
        }
        this_thread::sleep_for(chrono::seconds(10));
    }
}

void karakter::yemekYedir() {
    cout << "Karakter yemek yedi. Açlık sorunu giderildi." << endl;
    aclik = 100;
}

void karakter::suIc() {
    cout << "Karakter su içti. Susuzluk sorunu giderildi." << endl;
    susuzluk = 100;
}

void guckarsilastirma(float guc1, float guc2) {
    if (guc1 == guc2) {
        cout << "Karakterlerin güçleri birbirine eşittir." << endl;
    }
    else if (guc1 > guc2) {
        cout << "Karakter1 daha güçlüdür." << endl;
    }
    else {
        cout << "Karakter2 daha güçlüdür." << endl;
    }
}
