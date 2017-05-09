#include "Network.h"

using namespace std;

Network::Network(size_t input_number, size_t output_number, TYPE_NEURON type, double learning_rate_def, vector<string> labels)
{
  m_In      = new Layer (input_number, input_number, type, learning_rate_def);
  m_Hide    = new Layer (input_number, input_number, type, learning_rate_def);
  m_Out     = new Layer (input_number, output_number, type, learning_rate_def);
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
bool Network::train(Data input, string name) {

  output_calcul(input);

  vector<double> errors;
  Data output;
  for(int i = 0; i < m_labels.size(); i++) {
    if(m_labels[i] ==  name)
      output.add_data(1);
    else
      output.add_data(0);
  }
  for (int i = 0; i < m_Out->size(); i++) {
    errors.push_back( output.at(i) - m_outputs->at(i));
  }
  m_In->get_errors(m_Hide->get_errors(m_Out->get_errors(errors)));
  m_In->update_layer();
  m_Hide->update_layer();
  m_Out->update_layer();

  output_calcul(input);
  for (int i = 0; i < m_Out->size(); i++) {
      if(output.at(i) - m_outputs->at(i) > (1-PROB_SUCCESS)) {
        return false;
      }
  }
  return true;
}
bool Network::detect(Data input) {
  output_calcul(input);
  return get_prob(0);
}
void Network::get_max_prob(double *prob, string *output) {
  double p = 0;
  string o;
  for(int i = 0; i < m_outputs->get_size(); i++) {
    cout << m_labels[i] << " : " << m_outputs->at(i) << " -- ";
    p = max(m_outputs->at(i), p);
    if(p == m_outputs->at(i)) {
      o = m_labels[i];
    }
  }
  *prob = p;
  cout << endl;
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
  for(int i = 0; i < m_outputs->get_size(); i++)
  {
      cout << m_outputs->at(i) << endl;
  }

  if(m_outputs->at(i) > PROB_SUCCESS) {
    return true;
  }
  return false;
}
void Network::output_calcul(Data input)
{
  Data tmp;
  //cout << endl << endl << "INPUT : " << endl;
  //input.print();
  m_In->update_outputs(input);
  tmp = m_In->get_outputs();
  //cout << endl << endl << "IN OUTPUT : " << endl;
  //tmp.print();
  m_Hide->update_outputs(m_In->get_outputs());
  m_Out->update_outputs(m_Hide->get_outputs());

  tmp = m_Out->get_outputs();
  m_outputs->clear();
  for(int i = 0; i < tmp.get_size(); i++) {
    m_outputs->add_data(tmp.at(i));
  }
}
