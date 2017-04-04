#include "Data.h"

Data::Data()
{
    data.clear();
}
Data::Data(double *tab1D, size_t n)
{
    data.clear();
    for (int i = 0; i < n; i++)
    {
        data.push_back(tab1D[i]);
    }
}
Data::Data(double **tab2D, size_t x, size_t y)
{
    data.clear();
    for (int j = 0; j < y; j++)
    {
        for (int i = 0; i < x; i++)
        {
            data.push_back(tab2D[i][j]);
        }
        cout << endl;
    } 
}

// Destructor
Data::~Data()
{
    data.clear();
}

// getter
size_t Data::get_size()
{
    return data.size();
}

void Data::print()
{
    for(int i = 0; i < data.size(); i++)
    {
        cout << data[i] << endl;
    }
}