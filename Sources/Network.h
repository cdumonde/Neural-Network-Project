#include "Data.h"
#include "Layer.h"

#define PROB_SUCCESS 0.98

class Network
{

 public :

  /* Constructor */
  Network(size_t input_number = 1, size_t output_number = 1, TYPE_NEURON type = STEP, double learning_rate_def = 0.5 , vector<string> labels = vector<string>());
  ~Network();
  /* Membre */
  bool train(Data input, string name);
  void get_max_prob(double *prob, string *output);
  double get_prob(string out);
  bool get_prob(int i);
  bool detect(Data input);

 private :
  /* Method */
  void output_calcul(Data input);
  /* Attributs */
  Layer *m_In;
  Layer *m_Out;
  Layer *m_Hide;
  Data *m_outputs;
  vector<string> m_labels;
};
