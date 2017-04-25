#ifndef _NEURON_SIGMOID_
#define _NEURON_SIGMOID_

#include "Neuron.h"

class Neuron_Sigmoid : public Neuron {
  
 public:
    Neuron_Sigmoid(size_t input_number = 1 , double learning_rate_definition = 0.5);

 private :
  virtual double threshold(double in);

}
#endif /* _NEURON_SIGMOID_ */
