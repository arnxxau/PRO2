#include "CuaIOParInt.hh"

int main() {
    queue<ParInt> q0;
    llegirCuaParInt(q0);

    int t1 = 0, t2 = 0;
    queue<ParInt> q1;
    queue<ParInt> q2;

    while (not q0.empty()) {
        if (t1 <= t2) {
            q1.push(q0.front());
            t1 += q0.front().segon();
        } else {
            q2.push(q0.front());
            t2 += q0.front().segon();
        }

        q0.pop();
    }

    escriureCuaParInt(q1);
    cout << endl;
    escriureCuaParInt(q2);
}