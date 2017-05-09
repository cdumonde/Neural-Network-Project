#ifndef NEURON_SIGMOID_H
#define NEURON_SIGMOID_H

#define f(_x) (1.0/(1.0+exp(-_x)))

#include "Neuron.h"

class Neuron_Sigmoid : public Neuron {

public:
  Neuron_Sigmoid();
  ~Neuron_Sigmoid();
  virtual double threshold(double value);
  virtual double threshold_derivative();
};
#endif /* NEURON_SIGMOID_H */
