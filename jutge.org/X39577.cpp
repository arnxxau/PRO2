#include "Estudiant.hh"
#include <vector>
#include <iostream>

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

int main() {
    int n, m, s;
    cin >> n >> m >> s;
    vector<int> idxs (s);
    for (int i = 0; i < s; ++i) cin >> idxs[i];
    vector<Estudiant> v_est(n);
    for (int i = 0; i < n; ++i) get_average(m, idxs).escriure();
}