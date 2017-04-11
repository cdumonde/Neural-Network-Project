#include "Neuron_Sigmoid.h"
#include <cmath>

virtual double threshold(double in){
  return (in/(1.0+abs(in)));
}
