#include "BinTreeIOParInt.hh"


void read_bintree_parint(BinTree<ParInt>& a) {
    ParInt pair_in;

    if (pair_in.llegir()) {
        BinTree<ParInt> left;
        read_bintree_parint(left);

        BinTree<ParInt> right;
        read_bintree_parint(right);

        a = BinTree<ParInt> (pair_in, left, right);

    } else {
        a = BinTree<ParInt> (pair_in);
    }
    
}