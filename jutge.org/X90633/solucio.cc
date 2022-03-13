#include "Cjt_estudiants.hh"

void Cjt_estudiants::esborrar_estudiant(int dni, bool& b) {
/* Pre: existeix un estudiant al parametre implıcit amb DNI = dni */
/* Post: el parametre implıcit conte els mateixos estudiants que
l’original menys l’estudiant amb DNI = dni */

  int x = cerca_dicot(vest, 0, nest - 1, dni);
  if (x < nest and vest[x].consultar_DNI() == dni) {
      if (vest[x].te_nota()) {
        --nest_amb_nota;
        suma_notes -= vest[x].consultar_nota();
      }
      for (int i = x; i < nest - 1; ++i)
        vest[i] = vest[i + 1];
      --nest;
      b = true;
  } else b = false;

}

void Cjt_estudiants::afegir_estudiant(const Estudiant& est, bool& b) {
    int x = cerca_dicot(vest, 0, nest-1, est.consultar_DNI());
    b = x < nest and vest[x].consultar_DNI() == est.consultar_DNI();

    if (not b) {
        for(int i = nest-1; i >= x; --i)
            vest[i+1] = vest[i];
        ++nest;
        vest[x] = est;
        if(vest[x].te_nota()) {
            suma_notes += est.consultar_nota();
            ++nest_amb_nota;
        }
    }
}

