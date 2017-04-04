
class Layer{

  public:
      //constructeur
      Layer();
      Layer(size_t input_number, size_t output_number);
      
      // membres
      bool update_layer(vector<double> next_layer_errors);
      vector<double> get_error(void);
      
      //operateur
      Layer operator<<(const Layer);

    private: 
      // attributs
      vector<Neuron> neurons_tab;
      vector<double> errors;
};
