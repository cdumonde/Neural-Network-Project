class Network{

 public :

  /* Constructor */

  // give the number of neuron in each layer
  Network(size_t S_data_in, size_t N_input = 1, size_t N_hide = 1, size_t N_output = 1, TYPE_NEURON type = STEP, double learning_rate_def = 0.5 );
  
  /* Membre */
  bool train(Data input, Data output);
  string detect(Data input);
  void get_max_prob(double *prob, string *output);
  double get_prob(string out);

 private :

  /* attributs */
  Layer In;
  Layer Out;
  Layer Hide;
  Data outputs;

}
