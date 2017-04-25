#include "Network.h"

using namespace std;

Network::Network(size_t input_number, size_t output_number, TYPE_NEURON type, double learning_rate_def)
{
  m_In      = new Layer (input_number, type, learning_rate_def);
  m_Hide    = new Layer (input_number, type, learning_rate_def);
  m_Out     = new Layer (output_number, type, learning_rate_def);
  m_outputs = new Data  ();
}
Network::~Network()
{
  delete m_In;
  delete m_Hide;
  delete m_Out;
  delete m_outputs;
}
bool Network::train(Data input, Data output) {
  m_In        <<      m_input;  // give data to the In-layer
  m_Hide      <<      m_In;     // give outputs of In-layer to the Hide-layer
  m_Out       <<      m_Hide;   // give outputs of Hide-layer to the out-layer
  m_outputs   <<      m_Out;    // calculate all output of the Out-layer

  vector<double> errors;

  for (int i = 0; i <= m_Out->size(); i++) {
    errors.push_back( m_outputs->at(i) - output.at(i) );
  }
  m_Out->update_layer(errors);
  m_Hide->update_layer(m_Out->get_errors());
  m_In->update_layer(m_Hide->get_errors());
  
  m_In        <<      m_input;
  m_Hide      <<      m_In;
  m_Out       <<      m_Hide;
  m_outputs   <<      m_Out;
  
  for (int i = 0; i <= m_Out->size(); i++) {
    if((m_outputs->at(i) - output.at(i)) != 0 )
    {
      return false;
    }
  }
  return true;
}
string Network::detect(Data input) {
    
}
void Network::get_max_prob(double *prob, string *output) {

}
double Network::get_prob(string out) {

}
