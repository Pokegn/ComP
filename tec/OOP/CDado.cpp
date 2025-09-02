#include "CDado.h"

CDado::CDado()
{
    srand(time(0));
}


int CDado::roll()
{
    return  (rand() % 6) + 1;
}
