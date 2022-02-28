 #include <vector>
 // #include "vectorIOint.hh"
 using namespace std;
 
 struct parint {int prim, seg;};
 
 parint max_min1(const vector<int>& v)
 /* Pre: v.size()>0 */
 /* Post: el primer componente del resultado es el valor maximo de v;
    el segundo componente del resultado es el valor minimo de v */
 {
     int x = v[0], y = v[0];
     int v_size = v.size();
     for (int i = 1; i < v_size; i++)
     {
         if (x < v[i]) x = v[i];
         if (y > v[i]) y = v[i];
     }
     return parint{x, y};
 }
 
 pair<int,int> max_min2(const vector<int>& v)
 /* Pre: v.size()>0 */
 /* Post: el primer componente del resultado es el valor maximo de v;
 el segundo componente del resultado es el valor minimo de v */
 {
     int x = v[0], y = v[0];
     int v_size = v.size();
     for (int i = 1; i < v_size; i++)
     {
         if (x < v[i]) x = v[i];
         if (y > v[i]) y = v[i];
     }
     return make_pair(x, y);
 }
 
 void max_min3(const vector<int>& v, int& x, int& y)
 /* Pre: v.size()>0 */
 /* Post: x es el valor maximo de v;  y es el valor minimo de v */
 {
     x = v[0]; y = v[0];
     int v_size = v.size();
     for (int i = 1; i < v_size; i++)
     {
         if (x < v[i]) x = v[i];
         if (y > v[i]) y = v[i];
     }
     
 }

/*
 int main() {
     vector<int> v;
     leer_vector_int(v);
     escribir_vector_int(v);
     int x, y;
     max_min3(v, x, y);
     cout << "max: " << x << ' ' << "min: " << y << endl;
 }
 */