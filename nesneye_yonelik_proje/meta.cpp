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

