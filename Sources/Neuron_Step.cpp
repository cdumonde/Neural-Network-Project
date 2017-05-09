#include "Neuron_Step.h"

Neuron_Step::Neuron_Step(size_t input_number, double learning_rate_definition) : Neuron(input_number, learning_rate_definition) 
{

}
Neuron_Step::~Neuron_Step() 
{

}

double Neuron_Step::threshold(double in) {
  return (in > 0 ? 1 : 0);
}
double Neuron_Step::threshold_derivative(double in) {
  return (in == 0);
}



