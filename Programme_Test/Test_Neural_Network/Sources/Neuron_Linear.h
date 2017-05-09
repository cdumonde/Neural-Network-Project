#ifndef NEURON_LINEAR_H
#define NEURON_LINEAR_H

#include "Neuron.h"

class Neuron_Linear : public Neuron {

public:
  Neuron_Linear();
  ~Neuron_Linear();
  virtual double threshold(double value);
  virtual double threshold_derivative();
};
#endif /* NEURON_LINEAR_H */
