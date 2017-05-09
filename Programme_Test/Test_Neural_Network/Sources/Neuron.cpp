#include "Neuron.h"


Neuron::Neuron()
{
  output = 0;
}
Neuron::~Neuron()
{

}
void Neuron::set_input(double value)
{
  input = value;
  output = threshold(value);
}
double Neuron::get_output()
{
  return output;
}
void Neuron::set_error(double value) {
  error = value;
}
double Neuron::get_error() {
  return error;
}
