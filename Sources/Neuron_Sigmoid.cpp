#include "Neuron_Sigmoid.h"
#include <cmath>

virtual double threshold(double in){
  return (in/(1.0+abs(in)));
}

Neuron_Sigmoid::Neuron_Sigmoid(size_t input_number = 1 , double learning_rate_definition = 0.5){
  Neuron::Neuron(input_number, learning_rate_definition);
}
