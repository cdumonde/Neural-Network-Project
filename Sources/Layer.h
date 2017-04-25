#ifndef _LAYER_
#define _LAYER_

enum TYPE_NEURON { STEP, LINEAR, SIGMOID};

class Layer {

 public:
  // Constructor
  Layer(size_t input_number, size_t output_number, TYPE_NEURON type = STEP, double learning_rate_def = 0.5 );
  
  // Destructor
  ~Layer();
  
  // Membres
  bool update_layer(vector<double> next_layer_errors);
  void update_output();
  vector<double> get_errors();
  
  // Operator
  vector<double> operator<<(const Layer);
  
 private:
  // Private Membre
  void update_input();

  //attributes
  vector<Neuron> neurons_tab;
  vector<double> errors;
  vector<double> output;
  vector<double> input;

}

#endif /* _LAYER_ */
