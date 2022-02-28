#include "Estudiant.hh"
// #include "vectorIOEstudiant.hh"
#include <vector>


 pair<int,int> max_min_vest(const vector<Estudiant>& v) {
 /* Pre: v.size()>0 */
 /* Post: el primer componente del resultado es el valor maximo de v;
 el segundo componente del resultado es el valor minimo de v */
     double current = 0, max = -1, min = v[0].nota_maxima() + 1;
     int x_pos = -1, y_pos = -1;
     int v_size = v.size(); 

     for (int i = 0; i < v_size; i++) {
         bool te_nota = v[i].te_nota();
         if(te_nota) {
             current = v[i].consultar_nota();
         }
         bool dni_criteria_max = max == current and v[x_pos].consultar_DNI() > v[i].consultar_DNI();
         if (te_nota and (max < current or dni_criteria_max)) { 
             max = current;
             x_pos = i;
         }
         bool dni_criteria_min = min == current and v[y_pos].consultar_DNI() > v[i].consultar_DNI();
         if (te_nota and (min > current or dni_criteria_min))  {
             min = current;
             y_pos = i;
         }
     }
     return make_pair(x_pos, y_pos);
 }
 /* Pre: v no conte repeticions de dni  */
 /* Post: si existeix a v algun estudiant amb nota, la primera component del
    resultat es la posicio de l'estudiant de nota maxima de v i la segona
    component es la posicio de l'estudiant de nota minima de v (si hi ha
    empats, s'obte en cada cas la posicio de l'estudiant amb minim DNI); si no
    hi ha cap estudiant amb nota, totes dues components valen -1 */

/*
int main() {
    vector<Estudiant> estudiants;
    leer_vector_est(estudiants);
    pair<int, int> max_min = max_min_vest(estudiants);
    cout << "max: " << max_min.first << "min: " << max_min.second << endl;
}
*/
