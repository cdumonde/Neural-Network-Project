#include "Neuron.h"

// Constructors
Neuron::Neuron(size_t input_number, double learning_rate_definition) {
  for (int i = 0; i < input_number; i++) {
    m_weight[i] = 1;                    // initialization of all weight to 1
    m_input[i] = 0;                     // initialization of all entries to 0
  }
  learning_rate = learning_rate_definition;
  output = 0;
}

// Destructor
Neuron::~Neuron(){}
  
// re-initialize the input and calculate the outputs
bool Neuron::set_input(Data input) {
  for (int i = 0; i < input.get_size(); i++) {
    m_input[i] = input.at(i);
  }
  return output_calcul();
}
double Neuron::get_output() {
  return output;
}  
// Actualize the weight using the errors argument
void Neuron::update(double error) {                 //TODO

  for( int cpt_weight=0 , cpt_weight < weight.size(), cpt_weight++)
    weight[cpt_weight] += learning_rate*error*input[cpt_weight];   

}
bool Neuron::output_calcul(void) {
  double pre_output=0;
  if(m_input.size() != m_weight.size()){
    return false;
  }

  // make the summation function
  for(int i = 0; i < m_input.size(); i++){
    pre_output += m_input[i]*m_weight[i];
  } 
  // make the threshold function detection
  output = threshold(pre_output);
  return true;
}