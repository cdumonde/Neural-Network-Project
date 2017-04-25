#include "Neuron_Step.h"

virtual double threshold(double in){
  double threshold_value = 0;

  if ( in < threshold )
    return 1;
  else 
    return 0;
}

Neuron_Step::Neuron_Step(size_t input_number = 1 , double learning_rate_definition = 0.5){
  Neuron::Neuron(input_number, learning_rate_definition);
}



