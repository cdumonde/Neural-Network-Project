#ifndef _NEURON_STEP_
#define _NEURON_STEP_

#include "Neuron.h"

class Neuron_Step : public Neuron {
  
 public:
  Neuron_Step(size_t input_number = 1 , double learning_rate_definition = 0.5);
  ~Neuron_Step();
 private:
  virtual double threshold(double in);
  virtual double threshold_derivative(double in); 

};
#endif /* _NEURON_STEP_ */
