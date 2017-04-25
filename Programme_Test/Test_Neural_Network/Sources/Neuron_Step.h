#ifndef _NEURON_STEP_
#define _NEURON_STEP_

#include "Neuron.h"

class Neuron_Step : public Neuron {
  
 private :
  virtual double threshold(double in);

}
#endif /* _NEURON_STEP_ */
