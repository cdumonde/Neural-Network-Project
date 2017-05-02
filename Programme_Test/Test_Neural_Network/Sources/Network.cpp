#include "Network.h"

using namespace std;

Network::Network(size_t input_number, size_t output_number, TYPE_NEURON type, double learning_rate_def, vector<string> labels)
{
  m_In      = new Layer (input_number, type, learning_rate_def);
  m_Hide    = new Layer (input_number, type, learning_rate_def);
  m_Out     = new Layer (output_number, type, learning_rate_def);
  m_outputs = new Data  ();
  m_labels = labels;
}
Network::~Network()
{
  delete m_In;
  delete m_Hide;
  delete m_Out;
  delete m_outputs;
}
bool Network::train(Data input, Data output) {
  
  output_calcul(input);
  
  vector<double> errors;

  for (int i = 0; i <= m_Out->size(); i++) {
    errors.push_back( m_outputs->at(i) - output.at(i) );
  }
  m_Out->update_layer(errors);
  m_Hide->update_layer(m_Out->get_errors());
  m_In->update_layer(m_Hide->get_errors());
  
  output_calcul(input);
  
  for (int i = 0; i <= m_Out->size(); i++) {
    if(get_prob(i) != output.at(i)) {
      return false;
    }
  }
  return true;
}
string Network::detect(Data input) {
  string value;
  double prob;
  output_calcul(input);
  get_max_prob(&prob, &value);
  return value;
}
void Network::get_max_prob(double *prob, string *output) {
  double p = 0;
  string o;
  for(int i = 0; i < m_outputs->get_size(); i++) {
    p = max(m_outputs->at(i), p);
    if(p == m_outputs->at(i)) {
      o = m_labels[i];
    }
  }
  *prob = p;
  *output = o;
}
double Network::get_prob(string out) {
  for(int i = 0; i < m_labels.size(); i++) {
    if(m_labels[i] == out) {
      return m_outputs->at(i);
    }
  }
  return -1;
}
bool Network::get_prob(int i) {
  if(m_outputs->at(i) > PROB_SUCCESS) {
    return true;
  }
  return false;
}
void Network::output_calcul(Data input)
{
  *m_In        <<      input;
  *m_Hide      <<      *m_In;
  *m_Out       <<      *m_Hide;
  *m_outputs   <<      *m_Out;
}