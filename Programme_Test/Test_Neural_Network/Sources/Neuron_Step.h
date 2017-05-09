#ifndef NEURON_STEP_H
#define NEURON_STEP_H

#include "Neuron.h"

class Neuron_Step : public Neuron {
  
public:
  Neuron_Step();
  ~Neuron_Step();
  virtual double threshold(double value);
  virtual double threshold_derivative(); 
};
#endif /* NEURON_STEP_H */
