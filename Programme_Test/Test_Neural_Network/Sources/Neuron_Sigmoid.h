#ifndef _NEURON_SIGMOID_
#define _NEURON_SIGMOID_

#include "Neuron.h"

class Neuron_Sigmoid : public Neuron {
  
 private :
  virtual double threshold(double in);

}
#endif /* _NEURON_SIGMOID_ */
