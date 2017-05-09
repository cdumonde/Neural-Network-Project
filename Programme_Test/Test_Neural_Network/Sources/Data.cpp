#include "Data.h"

Data::Data()
{
    data.clear();
}
Data::Data(unsigned char *tab1D, size_t n)
{
    data.clear();
    for (unsigned int i = 0; i < n; i++)
    {
        data.push_back(tab1D[i]);
    }
}
Data::Data(unsigned char **tab2D, size_t x, size_t y)
{
    data.clear();
    for (unsigned int j = 0; j < y; j++)
    {
        for (unsigned int i = 0; i < x; i++)
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
// adder
void Data::add_data(double d)
{
    data.push_back(d);
}
// getter
size_t Data::get_size()
{
    return data.size();
}
//printer
void Data::print()
{
    for(unsigned int i = 0; i < data.size(); i++)
    {
        cout << (double)data[i] << " ";
    }
    cout << endl;
}
void Data::clear()
{
    data.clear();
}
void Data::normalize()
{
    for(unsigned int i = 0; i < data.size(); i++)
    {
        //data[i] /= 255.0;
        data[i] = 255 - data[i];
    }
}
double Data::at(int index)
{
    return data[index];
}
