#include <iostream>

int main() {
    union ShortChar {
        short num;
        char c;
    };

    ShortChar shortChar;
    shortChar.c = 'a';
    shortChar.num = shortChar.c + 257;
}