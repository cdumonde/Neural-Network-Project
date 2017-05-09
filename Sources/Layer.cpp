#include "Layer.h"

/**** Constructor ****/
Layer::Layer(size_t input_number, size_t output_number, TYPE_NEURON type, double learning_rate_def) {
    switch(type) {

  case STEP :
    for (int i = 0; i < output_number; i++) {
      m_neurons_tab.push_back(new Neuron_Step(input_number, learning_rate_def));
    }
  break;

  case LINEAR :
    for (int i = 0; i < output_number; i++) {
      m_neurons_tab.push_back(new Neuron_Linear(input_number, learning_rate_def));
    }
  break;

  case SIGMOID :
    Neuron_Sigmoid *n;
    for (int i=0; i < output_number;i++){
      m_neurons_tab.push_back(new Neuron_Sigmoid(input_number, learning_rate_def));
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
bool Layer::update_layer() {
  for(int i = 0; i < m_neurons_tab.size(); i++) {
      m_neurons_tab[i]->update();  // call of update function of each
  }
  return true;
}
void Layer::update_outputs(Data input) {
  m_output.clear();
  for(int i = 0; i < m_neurons_tab.size(); i++) {
    m_neurons_tab[i]->set_input(input); // give the inputs to the neuron and calculate the output
    m_output.add_data(m_neurons_tab[i]->get_output());  // stock the output calculated in the output vector of layer
  }
}
Data Layer::get_outputs() {
  return m_output;
}
vector<double> Layer::get_errors(vector<double> errors) {
  vector<double> tmp;
  /*for(int i = 0; i < errors.size(); i++)
  {
      cout << errors[i] << " ";
  }*/
  m_errors.clear();
  m_errors = m_neurons_tab[0]->get_error(errors[0]);
  for(int i = 1; i < m_neurons_tab.size(); i++) {
    tmp = m_neurons_tab[i]->get_error(errors[i]);
    for(int j = 0; j < tmp.size(); j++) {
      m_errors[j] += tmp[j];
    }
  }
  //cout << endl << endl;
  return m_errors;
}
size_t Layer::size(){
  return m_neurons_tab.size();
}
/***** Operator *****/
void operator<<(Layer &l0, Data const& l1) {
  l0.update_outputs(l1);
}
void operator<<(Layer &l0, Layer& l1) {
  l0.update_outputs(l1.get_outputs());
}
void operator<<(Data &l0, Layer& l1) {
  Data tmp = l1.get_outputs();
  for(int i = 0; i < tmp.get_size(); i++) {
    l0.add_data(tmp.at(i));
  }
}
