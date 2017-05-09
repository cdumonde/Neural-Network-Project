#include "Neuron_Sigmoid.h"
#include <cmath>

Neuron_Sigmoid::Neuron_Sigmoid(size_t input_number, double learning_rate_definition) : Neuron(input_number, learning_rate_definition)
{

}
Neuron_Sigmoid::~Neuron_Sigmoid()
{

}
double Neuron_Sigmoid::threshold(double in) {
  return f(in);
}
double Neuron_Sigmoid::threshold_derivative(double in) {
  return f(in)/(1+f(in));
}
