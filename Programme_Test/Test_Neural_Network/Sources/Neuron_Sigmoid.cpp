#include "Neuron_Sigmoid.h"
#include <cmath>

Neuron_Sigmoid::Neuron_Sigmoid() {

}
Neuron_Sigmoid::~Neuron_Sigmoid() {

}
double Neuron_Sigmoid::threshold(double value) {
  return (1/(1+exp(-value)));
}
double Neuron_Sigmoid::threshold_derivative() {
  return output*(1-output);
}
