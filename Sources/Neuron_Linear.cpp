#include "Neuron_Linear.h"


Neuron_Linear::Neuron_Linear(size_t input_number, double learning_rate_definition) : Neuron(input_number, learning_rate_definition) 
{

}
Neuron_Linear::~Neuron_Linear() 
{

}

double Neuron_Linear::threshold(double in) {
  return in;
}
double Neuron_Linear::threshold_derivative(double in) {
  return 1.0;
}
