#include "Neuron.h"
static default_random_engine generator;
// Constructors
Neuron::Neuron(size_t input_number, double learning_rate_definition) {
  uniform_real_distribution<double> distribution(-0.5, 0.5);
  for (int i = 0; i < input_number; i++) {
    m_weight.push_back(distribution(generator));                    // initialization of all weight to 1
    m_input.push_back(0);                     // initialization of all entries to 0
  }
  learning_rate = learning_rate_definition;
  m_output = 0;
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
  return m_output;
}
void Neuron::set_weight(int index, double value) {
  m_weight[index] = value;
}
// Actualize the weight using the errors argument
void Neuron::update() {               //TODO
  double pre_output = 0;
  for(int i = 0; i < m_input.size(); i++){
    pre_output += m_input[i]*m_weight[i];
  }
  for(int i = 0; i < m_weight.size(); i++) {
    m_weight[i] = m_weight[i] + learning_rate*m_error*threshold_derivative(pre_output);
  }
}
vector<double> Neuron::get_error(double error) {
  vector<double> errors;
  m_error = error;
  for(int i = 0; i < m_weight.size(); i++) {
    errors.push_back(m_weight[i]*error);
  }
  return errors;
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
  m_output = threshold(pre_output);
  return true;
}
