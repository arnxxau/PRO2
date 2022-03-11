#include "CuaIOParInt.hh"


void llegirCuaParInt(queue<ParInt>& c) {
    ParInt p_int;
    p_int.llegir();
    while (p_int.primer() != 0 and p_int.segon() != 0) {
        c.push(p_int);
        p_int.llegir();
    }
}

void escriureCuaParInt(queue<ParInt> c){
    while (not c.empty()) {
        c.front().escriure();
        c.pop();
    }
}

