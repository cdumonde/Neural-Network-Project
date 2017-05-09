#ifndef _NEURON_SIGMOID_
#define _NEURON_SIGMOID_

#define f(_x) (1.0/(1.0+exp(-_x)))

#include "Neuron.h"

class Neuron_Sigmoid : public Neuron {

 public:
  Neuron_Sigmoid(size_t input_number = 1 , double learning_rate_definition = 0.5);
  ~Neuron_Sigmoid();
 private:
  virtual double threshold(double in);
  virtual double threshold_derivative(double in);

};
#endif /* _NEURON_SIGMOID_ */
