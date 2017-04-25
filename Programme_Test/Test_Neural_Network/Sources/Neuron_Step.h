#ifndef _NEURON_STEP_
#define _NEURON_STEP_

#include "Neuron.h"

class Neuron_Step : public Neuron {
  
 public:
  Neuron_Step(size_t input_number = 1 , double learning_rate_definition = 0.5);

 private :
  virtual double threshold(double in);

}
#endif /* _NEURON_STEP_ */
