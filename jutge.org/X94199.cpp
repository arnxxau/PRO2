#include "Estudiant.hh"
#include <vector>


 /* Pre: v=V, v.size() > 0 i les notes d'un mateix estudiant son consecutives */
 /* Post: pos+1 es el nombre d'estudiants diferents de V; cada estudiant de V
    nomes hi apareix un cop a v[0..pos], amb la nota mes alta i en el mateix
    ordre que a V */
 void simplificar_vector(vector<Estudiant>& v, int& pos) {
     int v_size = v.size();
     vector<Estudiant> V;
     pos = 0;
     Estudiant est0 = v[0];
     double max = 0;
     Estudiant est1;
     
     for (int i = 0; i < v_size; ++i) {
         est1 = v[i];
         if (est0.consultar_DNI() != est1.consultar_DNI()) {
             v[pos] = est0;
             ++pos;
             est0 = est1;
             if (est1.te_nota()) max = est1.consultar_nota();
             else max = 0;
         }
         else if (est1.te_nota() and est1.consultar_nota() > max) {
             max = est1.consultar_nota();
             est0 = est1;
         }
     }
     v[pos] = est0;
 }



/*
int main() {
    int n;
    cin >> n;
    vector<Estudiant> estudiants(n);
    for (int i  = 0; i < n; ++i) {
        Estudiant est;
        est.llegir();
        estudiants[i] = est;
    }

    int pos;
    simplificar_vector(estudiants, pos);
    cout << "pos: " << pos << endl;
    for (int i = 0; i < estudiants.size(); ++i)
        estudiants[i].escriure();
}
*/