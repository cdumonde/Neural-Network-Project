#include "Data.h"
#include "Layer.h"

class Network
{

 public :

  /* Constructor */
  Network(size_t input_number = 1, size_t output_number = 1, TYPE_NEURON type = STEP, double learning_rate_def = 0.5 );
  ~Network();
  /* Membre */
  bool train(Data input, Data output);
  void get_max_prob(double *prob, string *output);
  double get_prob(string out);
  string detect(Data input);

 private :

  /* Attributs */
  Layer *m_In;
  Layer *m_Out;
  Layer *m_Hide;
  Data *m_outputs;

};
