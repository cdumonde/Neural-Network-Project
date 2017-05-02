#include "Layer.h"
  
/**** Constructor ****/
Layer::Layer(size_t output_number, TYPE_NEURON type, double learning_rate_def) {
  switch(type) {
    
  case STEP :
    for (int i = 0; i < output_number; i++) {
      m_neurons_tab.push_back(new Neuron_Step(output_number, learning_rate_def));
    }
  break;
    
  case LINEAR :
    for (int i = 0; i < output_number; i++) {
      m_neurons_tab.push_back(new Neuron_Linear(output_number, learning_rate_def));
    }
  break;
    
  case SIGMOID :
    for (int i=1; i < output_number;i++){
      m_neurons_tab.push_back(new Neuron_Sigmoid(output_number, learning_rate_def));
    }
  break;
  }
}
/**** Destructor ****/
Layer::~Layer() {
  for(int i = 0; i < m_neurons_tab.size(); i++) {
    delete m_neurons_tab[i];
  }
}
/***** Membres *****/
bool Layer::update_layer(vector<double> errors) {
  for(int i = 0; i < m_neurons_tab.size(); i++) {
      m_neurons_tab[i]->update(errors[i]);  // call of update function of each 
  }
  return true;
}
void Layer::update_outputs(Data input) {
  m_output.clear();
  for(int i = 0; i <= m_neurons_tab.size(); i++) {
    m_neurons_tab[i]->set_input(input);   // give the inputs to the neuron and calculate the output
    m_output.add_data(m_neurons_tab[i]->get_output());  // stock the output calculated in the output vector of layer
  }  
}
Data Layer::get_outputs() {
  return m_output;
}
vector<double> Layer::get_errors() {
  m_errors.clear();
  for(int i = 0; i < m_neurons_tab.size(); i++) {
    m_errors.push_back(m_neurons_tab[i]->get_error());
  }
  return m_errors;
}
size_t Layer::size(){
  return m_neurons_tab.size();
}
/***** Operator *****/
Layer& operator<<(Layer &l0, Data const& l1) {
  l0.update_outputs(l1);
  return l0;
}
Layer& operator<<(Layer &l0, Layer& l1) {
  l0.update_outputs(l1.get_outputs());
  return l0;
}
Data& operator<<(Data &l0, Layer& l1) {
  Data tmp = l1.get_outputs();
  for(int i = 0; i < tmp.get_size(); i++) {
    l0.add_data(tmp.at(i));
  }
  return l0;
}
