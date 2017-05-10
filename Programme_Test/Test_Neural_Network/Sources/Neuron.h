#ifndef NEURON_H
#define NEURON_H

class Neuron {

public:

  Neuron();
  virtual ~Neuron();
  void set_input(double value);
  double get_output();
  void set_error(double value);
  double get_error();
  virtual double threshold(double value)=0;
  virtual double threshold_derivative()=0;
protected:
  double input;
  double output;
  double error;
};
#endif //NEURON_H
