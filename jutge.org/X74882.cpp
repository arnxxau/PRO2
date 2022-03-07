#include "Cjt_estudiants.hh"
#include <iostream>

int main() {
    Cjt_estudiants cjt0;
    cjt0.llegir();
    Cjt_estudiants cjt1;
    cjt1.llegir();

    int cjt_size = cjt0.mida();
    for (int i = 1; i <= cjt_size; ++i) {
        Estudiant est0 = cjt0.consultar_iessim(i);
        Estudiant est1 = cjt1.consultar_iessim(i);
        
        bool first_cond = est0.te_nota() and est1.te_nota() // only if the two students have a mark
                            and est0.consultar_nota() < est1.consultar_nota();
        bool second_cond = not est0.te_nota() and est1.te_nota();
        if (first_cond or second_cond) cjt0.modificar_iessim(i, est1);
    }
    cjt0.escriure();
}