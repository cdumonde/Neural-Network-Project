#ifndef LAYER_H
#define LAYER_H

class Layer{

  public:
      // Constructors
      Layer();
      Layer(size_t input_number, size_t output_number);
      
      // Destructor
      ~Layer();

      // Members
      bool update_layer(vector<double> next_layer_errors);
      vector<double> get_error(); 
      
      // Operators
      Layer operator<<(const Layer);

    private: 
      // attributs
      vector<Neuron> neurons_tab;
      vector<double> errors;
};
#endif // LAYER_H
