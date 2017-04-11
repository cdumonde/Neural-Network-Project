#ifndef _LAYER_
#define _LAYER_

enum TYPE_NEURON { STEP, LINEAR, SIGMOID};

class Layer {

 public:
  // Constructor
  Layer(size_t input_number, size_t output_number, );
  
  // Destructor
  ~Layer();
  
  // Membres
  bool update_layer(vector<double> next_layer_errors);
  vector<double> get_errors();
  
  // Operator
  Layer operator<<(const Layer);
  
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
