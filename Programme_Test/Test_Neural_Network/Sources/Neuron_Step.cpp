#include "Neuron_Step.h"

virtual double threshold(double in){
  double threshold_value = 0;

  if ( in < threshold )
    return 1;
  else 
    return 0;
}
