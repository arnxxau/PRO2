#include "Estudiant.hh"
#include <vector>
#include <iostream>
#include <algorithm>

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

bool cmp(const Estudiant& est0, const Estudiant& est1) {
    if (est0.consultar_nota() != est1.consultar_nota()) return est0.consultar_nota() > est1.consultar_nota();
    else return est0.consultar_DNI() < est1.consultar_DNI();
}

int main() {
    int n, m, s;
    cin >> n >> m >> s;
    vector<int> idxs (s);
    for (int i = 0; i < s; ++i) cin >> idxs[i];
    vector<Estudiant> v_est(n);

    vector<Estudiant> v_vest_average;
    for (int i = 0; i < n; ++i) v_vest_average.push_back(get_average(m, idxs));


    sort(v_vest_average.begin(), v_vest_average.end(), cmp);
    int average_size = v_vest_average.size();
    for (int i = 0; i < average_size; ++i) v_vest_average[i].escriure();
}