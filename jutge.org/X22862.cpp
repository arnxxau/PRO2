#include "Cjt_estudiants.hh"
#include <iostream>



double redondear(double r) {  
  return int(10.*(r + 0.05)) / 10.0;
} 

void round_cjt_mark(Cjt_estudiants& cjt) {
    int cjt_size = cjt.mida();
    for (int i = 0; i < cjt_size; ++i) {
        Estudiant est = cjt.consultar_iessim(i);
        if (est.te_nota()) {
            int mark = redondear(est.consultar_nota());
            est.modificar_nota(mark);
            cjt.modificar_iessim(i, est);
        }
    }
}

int main() {
    Cjt_estudiants cjt;
    cjt.llegir();

    int n;
    cin >> n;
    while (n != -6) {
        Estudiant est;
        if (n == -1) { // -1 new student
            est.llegir();
            try {
                cjt.afegir_estudiant(est);
            }
            catch(const PRO2Excepcio& e) {
                cout << "el conjunto esta lleno" << endl;
            }
        } else if (n == -2) { // -2 check student mark
            int dni;
            cin >> dni;
            est = cjt.consultar_estudiant(dni);
            try {
                 cout << "el estudiante " << dni << " tiene nota " << est.consultar_nota() << endl;
            }
            catch(const PRO2Excepcio& e) {
                cout << "el estudiante " << dni << " no tiene nota" << endl;
            }
        } else if (n == -3) { // -3 modify student mark
            est.llegir();
            cjt.modificar_estudiant(est);
        } else if (n == -4)
        
        
        
        cin >> n;
    }

    
    
    
    // -4 round mark
    // -5 write cjt
}