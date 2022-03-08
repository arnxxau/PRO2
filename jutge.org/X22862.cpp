#include "Cjt_estudiants.hh"
#include <iostream>



double redondear(double r) {  
  return int(10.*(r + 0.05)) / 10.0;
} 

void round_cjt_mark(Cjt_estudiants& cjt) {
    int cjt_size = cjt.mida();
    for (int i = 1; i <= cjt_size; ++i) {
        Estudiant est = cjt.consultar_iessim(i);
        if (est.te_nota()) {
            double mark = redondear(est.consultar_nota());
            est.modificar_nota(mark);
            cjt.modificar_iessim(i, est);
        }
    }
}

void check_student_mark(const Cjt_estudiants& cjt) {
     int dni;
     cin >> dni;
     if (cjt.existeix_estudiant(dni)) {
         Estudiant est = cjt.consultar_estudiant(dni);
         if (est.te_nota()) cout << "el estudiante " << dni << " tiene nota " 
                                << est.consultar_nota() << endl << endl;
         else cout << "el estudiante " << dni << " no tiene nota" << endl << endl;
     } else 
        cout << "el estudiante " << dni 
                << " no esta" << endl << endl;
}

void modify_student_mark(Cjt_estudiants& cjt) {
    Estudiant est;
    est.llegir();
    if (cjt.existeix_estudiant(est.consultar_DNI()))
        cjt.modificar_estudiant(est);
    else cout << "el estudiante " << est.consultar_DNI() 
            << " no esta" << endl << endl; 
}

void add_student(Cjt_estudiants& cjt) {
    Estudiant est;
    est.llegir();
    if (cjt.existeix_estudiant(est.consultar_DNI())) cout << "el estudiante " 
                        << est.consultar_DNI() << " ya estaba" << endl << endl;
    else if (cjt.mida_maxima() > cjt.mida()) cjt.afegir_estudiant(est);
    else cout << "el conjunto esta lleno" << endl << endl;
}

int main() {
    Cjt_estudiants cjt;
    cjt.llegir();

    int n;
    cin >> n;
    while (n != -6) {
        Estudiant est;
        if (n == -1) add_student(cjt); // -1 new student
        else if (n == -2) check_student_mark(cjt);  // -2 check student mark
        else if (n == -3) modify_student_mark(cjt); // -3 modify student mark
        else if (n == -4) round_cjt_mark(cjt); // -4 round mark
        else {
            cjt.escriure();
            cout << endl;
        }// -5 write cjt
        cin >> n;
    }
}