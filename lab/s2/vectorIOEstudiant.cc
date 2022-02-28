#include "vectorIOEstudiant.hh"
#include "Estudiant.hh"

/* Leer vector */
void leer_vector_est(vector<Estudiant>& v) {// version accion
  cout<<"Escribe el tama�o del vector:"<<endl;
  int numEst;
  cin >> numEst;
  v = vector<Estudiant> (numEst);

  cout<<"Escribe los elementos del vector:"<<endl;  
  for (int i=0; i<numEst;++i) {
    Estudiant est;
    est.llegir();
    v[i] = est;
  }
}


/* Redondear vector */
void redondear_vector_est(vector<Estudiant>& v) {
    int v_size = v.size();
    for (int i = 0; i < v_size; ++i) {
	if (v[i].te_nota()) {
        int nota_red = ((int)(10.*(v[i].consultar_nota()+.05)))/10.;
        v[i].modificar_nota(nota_red);
        }
    }
}


/* Escribir vector */
void escribir_vector_est(const vector<Estudiant>& v) {
  for (int i=0; i<v.size();++i) {
    cout << "DNI: " << v[i].consultar_DNI() << "nota: " << v[i].consultar_nota() << endl;
  }
  cout << endl;
}
