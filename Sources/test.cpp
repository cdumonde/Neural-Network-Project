#include "Neuron_Step.h"
#include "Data.h"
#include "iostream"



int main()
{
    unsigned char tab[] = {1, 0 , 0};
    Data dat = Data(tab, 3);
    dat.print();
    Neuron_Step n = Neuron_Step(3);
    n.set_weight(0, -0.5);
    n.set_weight(1, 1);
    n.set_weight(2, 2);
    n.set_input(dat);
    cout << n.get_output() << endl;    
    
}