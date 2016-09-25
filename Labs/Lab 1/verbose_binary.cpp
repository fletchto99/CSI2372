#include <iostream>

#include "verbose_binary.h"

using namespace std;

string names[] = {
        "Null",
        "One",
        "Two",
        "Four",
        "Eight",
        "Sixteen"
};

VerboseBinary values[] = {
        VerboseBinary::Sixteen,
        VerboseBinary::Eight,
        VerboseBinary::Four,
        VerboseBinary::Two,
        VerboseBinary::One
};

string enumKeyName(int enumVal) {
    return names[enumVal];
}

void convert(bitset<5> bs, VerboseBinary vb[6]) {
    for(size_t i = 0; i < 5; i++) {
        if (bs.test(4-i)) {
            vb[i] = values[i];
        } else {
            vb[i] = VerboseBinary::Unset;
        }
    }
    vb[5] = VerboseBinary::Null;
}

void print(VerboseBinary vb[6]) {
    for(size_t i = 0; i < sizeof(vb); i++) {

        if(vb[i] == VerboseBinary::Null) {
            cout << enumKeyName(static_cast<underlying_type<VerboseBinary >::type>(vb[i])) << endl;
            return;
        } else if (vb[i] != VerboseBinary::Unset) {
            cout << enumKeyName(static_cast<underlying_type<VerboseBinary >::type>(vb[i])) << ", ";
        }
    }
}

void xorEquals(VerboseBinary vb1[6], VerboseBinary vb2[6]) {
    bitset<5> bs1;
    bitset<5> bs2;

    for(size_t i = 0; i < 5; i++) {
        if (vb1[4-i] != VerboseBinary::Unset) {
            bs1.set(i);
        }
        if (vb2[4-i] != VerboseBinary::Unset) {
            bs2.set(i);
        }
    }

    convert(bs1 ^ bs2, vb1);
}
