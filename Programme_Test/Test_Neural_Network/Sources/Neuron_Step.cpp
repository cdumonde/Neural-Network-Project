#include "Neuron_Step.h"

Neuron_Step::Neuron_Step() {

}
Neuron_Step::~Neuron_Step() {

}
double Neuron_Step::threshold(double value) {
  return (value > 0 ? 1 : 0);
}
double Neuron_Step::threshold_derivative() {
  return (input == 0);
}



