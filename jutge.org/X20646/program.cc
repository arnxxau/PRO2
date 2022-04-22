#include "BinTree.hh"
#include "BinTreeIOParInt.hh"
#include <list>
#include <queue>
#include <iostream>

using namespace std;


bool find_and_pop(list<int>& l, int current) {
    list<int>::iterator it = l.begin();

    bool found = false;
    while (it != l.end() and not found)
    {
        if (*it != current) ++it;
        else {
            it = l.erase(it);
            found = true;
        }
    }
    return found;
}



void breadth_search(const BinTree<ParInt>& t, int to_find) {
    bool found = false;
    if (not t.empty())
    {   
        queue<pair<BinTree<ParInt>, int>> q;
        q.push(make_pair(t, 0));

        while (not q.empty() and not found)
        {
            BinTree<ParInt> aux = q.front().first;
            int level = q.front().second;
            q.pop();
            found = to_find == aux.value().primer();

            if (not aux.left().empty()) q.push(make_pair(aux.left(), level + 1));
            if (not aux.right().empty()) q.push(make_pair(aux.right(), level + 1));
            if (found)
                cout << aux.value().primer() << ' ' << aux.value().segon() << ' ' << level << endl;
        }
        
    }
    if (not found) cout << -1 << endl;
}


int main() {
    BinTree<ParInt> b;
    read_bintree_parint(b);

    int n;
    while (cin >> n) breadth_search(b, n);    
}