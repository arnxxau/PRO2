#include "Estudiant.hh"
#include <iostream>
#include <vector>

/* Leer vector */
void leer_vector_est(vector<Estudiant>& v) {// version accion
  int numEst;
  cin >> numEst;
  v = vector<Estudiant> (numEst);
  for (int i=0; i<numEst;++i) {
    Estudiant est;
    est.llegir();
    v[i] = est;
  }
}

vector<Estudiant> get_mod(const vector<Estudiant>& v) {
    int current_DNI = v[0].consultar_DNI();
    int v_size = v.size();
    double max = 0;
    vector<Estudiant> v_est_best;
    Estudiant est = v[0];
    for (size_t i = 0; i < v_size; i++) {
      if (current_DNI != v[i].consultar_DNI()) {
        v_est_best.push_back(est);
        est = v[i];
        current_DNI = v[i].consultar_DNI();

        if (est.te_nota()) max = est.consultar_nota();
        else max = 0;

      } else if (v[i].te_nota() and max < v[i].consultar_nota()) {
        max = v[i].consultar_nota();
        est = v[i];
      }
      
    }
    v_est_best.push_back(est);
    return v_est_best;
}

int main() {
    vector<Estudiant> v_est;
    leer_vector_est(v_est);
    vector<Estudiant> v_est_best = get_mod(v_est);

    int v_size = v_est_best.size();
    for (int i = 0; i < v_size; i++) v_est_best[i].escriure();
    
}

