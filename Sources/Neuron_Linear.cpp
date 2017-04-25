#include "Neuron_Linear.h"

virtual double threshold(double in){
  return in;
}

Neuron_Linear::Neuron_Linear(size_t input_number = 1 , double learning_rate_definition = 0.5){
  Neuron::Neuron(input_number, learning_rate_definition);
}
