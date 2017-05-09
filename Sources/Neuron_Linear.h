#ifndef _NEURON_LINEAR_
#define _NEURON_LINEAR_

#include "Neuron.h"

class Neuron_Linear : public Neuron {

 public:
  Neuron_Linear(size_t input_number = 1 , double learning_rate_definition = 0.5);
  ~Neuron_Linear();
 private :
  virtual double threshold(double in);
  virtual double threshold_derivative(double in); 

};
#endif /* _NEURON_LINEAR_ */
