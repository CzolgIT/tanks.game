#include "Main.h"

class Projection {
public:
    int min, max;

    Projection(int min, int max);

    bool overlap(Projection * p2);

};
