#include <stdlib.h>
#include <iostream>
#include "Data.h"

using namespace std;

int main()
{
    double tab1[5] = {0};
    double **t = new double* [5];
    for (int i=0; i < 5; i++)
        t[i] = new double[ 2 ];
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            t[i][j] = 1;
        }
    }

    Data tab1D(tab1, 5);
    tab1D.print();
    Data tab2D(t, 5, 2);
    tab2D.print();

    return 0;
}
