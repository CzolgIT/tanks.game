#include "Main.h"

Projection::Projection(int min, int max)
{
    this->min = min;
    this->max = max;
}

bool Projection::overlap(Projection * p2){

    if (p2->min >= this->max || this->min >= p2->max){
        return true;
    }
    else return false;
}
