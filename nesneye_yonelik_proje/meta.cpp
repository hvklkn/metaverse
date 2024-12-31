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

void karakter::hareket(int x, int y) {
    try {
        int yon;
        cout << "Hangi yöne hareket etsin? 0-SOL 1-SAG 2-YUKARI 3-ASAGI: ";
        cin >> yon;

        switch (yon) {
            case 0: x -= 1; break;
            case 1: x += 1; break;
            case 2: y += 1; break;
            case 3: y -= 1; break;
            default: throw invalid_argument("Geçersiz yön seçimi.");
        }

        if (x < 0 || y < 0) {
            throw out_of_range("Koordinatlar negatif olamaz!");
        }

        cout << "Mevcut konum: " << x << ", " << y << endl;
    }
    catch (const exception &e) {
        cout << "Hata: " << e.what() << endl;
    }
}

void karakter::durumGoster() {
    cout << "Karakter Durumu:" << endl;
    cout << "Para: " << para << endl;
    cout << "Açlık: " << aclik << endl;
    cout << "Susuzluk: " << susuzluk << endl;
    cout << "Güç: " << guc << endl;
}

void paraaktarma(float &para1, float &para2) {
    try {
        int karakternumarasi;
        float miktar;
        cout << "Hangi karakter para göndersin? (1 veya 2): ";
        cin >> karakternumarasi;
        cout << "Ne kadar para yollasın? ";
        cin >> miktar;

        if (miktar < 0) {
            throw invalid_argument("Para miktarı negatif olamaz.");
        }

        switch (karakternumarasi) {
            case 1:
                if (para1 <= 0 || para1 < miktar) {
                    throw runtime_error("Karakter1 için yetersiz bakiye!");
                }
                para1 -= miktar;
                para2 += miktar;
                cout << "Karakter1 " << miktar << " TL Karakter2'ye aktardı." << endl;
                break;

            case 2:
                if (para2 <= 0 || para2 < miktar) {
                    throw runtime_error("Karakter2 için yetersiz bakiye!");
                }
                para2 -= miktar;
                para1 += miktar;
                cout << "Karakter2 " << miktar << " TL Karakter1'e aktardı." << endl;
                break;

            default:
                throw out_of_range("Geçersiz karakter numarası girildi.");
        }
    }
    catch (const exception &e) {
        cout << "Hata: " << e.what() << endl;
    }
}