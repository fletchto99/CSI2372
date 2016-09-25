using namespace std;

enum class VerboseBinary : short {
    Unset=-1,
    Null=0,
    One=1,
    Two=2,
    Four=3,
    Eight=4,
    Sixteen=5,
};

void convert(bitset<5>, VerboseBinary[6]);

void print(VerboseBinary[6]);

void xorEquals(VerboseBinary[6], VerboseBinary[6]);