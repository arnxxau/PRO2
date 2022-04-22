#include <iostream>
#include <map>

using namespace std;

int main() {
    map<string, int> freq;
    map<string, int>::iterator is_this_the_end = freq.end();
    string s, n;
    while (cin >> s >> n) {
        map<string, int>::iterator current_it = freq.find(n);
        if (s == "f")
        {
            if ( current_it != is_this_the_end)
            {
                cout << current_it -> second << endl;
            } else {
                cout << 0 << endl;
            }
        } else {
            if ( current_it != is_this_the_end)
            {
                current_it -> second++;
            } else {
                freq.insert(make_pair(n, 1));
            }
        }
    }
}