#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector< vector<int>> matrix;

struct team {
    int n;
    int total_points;
    int goals;
    int r_goals;
};

matrix read_sq_matrix(int n) {
    matrix m (n, vector<int>(n*2));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n*2; j++) {
            cin >> m[i][j];
        }   
    }
    return m;
}

void update_team(team& t, int& x, int& y) {
    int points = 0;
    if (x > y) points = 3;
    else if (x == y) points = 1;
    t.total_points += points;
    t.goals += x;
    t.r_goals += y;
} 

bool cmp (const team& t1, const team& t2) {
    if (t1.total_points != t2.total_points) 
        return t1.total_points > t2.total_points;
    else if (t1.goals - t1.r_goals != t2.goals - t2.r_goals) 
        return t1.goals - t1.r_goals > t2.goals - t2.r_goals;
    else 
        return t1.n < t2.n;
}

int main() {
    int n;
    cin >> n;
    matrix matrx = read_sq_matrix(n);
    vector<team> teams (n, team{0, 0, 0, 0});
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n*2; j += 2) {
            if (i != j/2) {
                int x = matrx[i][j], y = matrx[i][j + 1];
                update_team(teams[i], x, y);
                update_team(teams[j/2], y, x);
            }
            teams[i].n = i + 1;
        }
        
    }
    
    sort(teams.begin(), teams.end(), cmp);
    for (int i = 0; i < n; ++i) {
        cout << teams[i].n << ' ' 
            << teams[i].total_points << ' ' 
            << teams[i].goals << ' ' << teams[i].r_goals << endl;
    }
}