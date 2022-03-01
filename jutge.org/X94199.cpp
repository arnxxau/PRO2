#include "Estudiant.hh"
#include <vector>

 void simplificar_vector(vector<Estudiant>& v, int& pos) {
     int v_size = v.size();
     vector<Estudiant> V;
     Estudiant est0 = v[0];
     double max = 0;
     for (int i = 0; i < v_size; ++i) {
         Estudiant est1 = v[i];
         if (est1.te_nota() and est1.consultar_nota() > max) {
             max = est1.consultar_nota();
             est0.modificar_nota(max);
         }
         if (est0.consultar_DNI() != est1.consultar_DNI()) {
             V.push_back(est0);
             est0 = est1;
             max = est1.consultar_nota();
         }
     }
 }
 /* Pre: v=V, v.size() > 0 i les notes d'un mateix estudiant son consecutives */
 /* Post: pos+1 es el nombre d'estudiants diferents de V; cada estudiant de V
    nomes hi apareix un cop a v[0..pos], amb la nota mes alta i en el mateix
    ordre que a V */

bool is_contained(int i, const vector<int>& idxs) { 
    int v_size = idxs.size();
    for (int j = 0; j < v_size; ++j)
        if (idxs[j] == i) return true;
    return false;
}

Estudiant get_average(int m, const vector<int>& idxs) {
    double average = 0;
    Estudiant est;
    est.llegir();
    double x = est.consultar_nota();
    for (int i = 1; i < m + 1; ++i) {
        if (is_contained(i, idxs)) average += x;
        if (i < m) cin >> x;
    }
    est.modificar_nota(average / idxs.size());
    return est;
}