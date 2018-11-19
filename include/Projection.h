#include "Main.h"

class Projection {
public:
    int min, max;

    Projection(int min, int max);

    static bool overlap(Projection * p1, Projection * p2);

    static float getOverlap(Projection * p1, Projection * p2);

};
