#include "Neuron_Linear.h"

Neuron_Linear::Neuron_Linear() {

}
Neuron_Linear::~Neuron_Linear() {

}
double Neuron_Linear::threshold(double value) {
  return value;
}
double Neuron_Linear::threshold_derivative() {
  return 1.0;
}
