#ifndef NEURON_H 
#define NEURON_H

#include "Data.h"

class Neuron {

public:
  
  // Constructors
  Neuron(size_t input_number = 1, double learning_rate_definition = 0.5);  
  
  // Destructor
  ~Neuron();
  
  // setter
  bool set_input(Data input); // give input to the neuron et calculate the output
  
  // getter
  double get_output();
  double get_error();
  
  // Members
  /** Actualize the weight using the errors argument **/
  void update(double error);

private:
  // Members
  bool output_calcul(void); 
  virtual double threshold(double pre_output) = 0;  

  //attributs
  vector<double> m_weight;
  vector<double> m_input;
  double output;
  double error;
  double learning_rate; 

};
#endif //NEURON_H
