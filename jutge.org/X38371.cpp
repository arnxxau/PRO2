#include <iostream>
#include <queue>

using namespace std;

void recompute_max_min(queue<int> q, int& max, int& min) {
    max = -1001;
    min = 1001;
    while (not q.empty()) {
        int e = q.front();
        if (e > max) max = e;
        if (e < min) min = e;
        q.pop();
    }
}

int main() {
    queue<int> q;
    int n;
    cin >> n;

    int max = -1001, min = 1001;
    int sum = 0;
    while (n < 1001 and n > -1002) {
        if (n != -1001) {
            sum += n;
            q.push(n);
            if (n > max) max = n;
            if (n < min) min = n;
        } else if (not q.empty()){
            int e = q.front();
            q.pop();
            sum -= e;
            if (e == max or e == min)
                recompute_max_min(q, max, min);
        }
        cin >> n;
        if (not q.empty()) cout << "min " << min << "; max " << max << "; media " << double(sum)/q.size() << endl;
        else cout << '0' << endl;
    }
}