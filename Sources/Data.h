#ifndef DATA_H
#define DATA_H

#include <vector>
#include <iostream>
#include <stdlib.h>

using namespace std;

class Data
{
public:
    // Constructors
    Data();
    Data(double *tab1D, size_t n);
    Data(double **tab2D, size_t x, size_t y);

    // Destructor
    ~Data();

    // getter
    size_t get_size();
    void   print();
private:
    // Attribute
    vector<double> data;
};


#endif //DATA_H

