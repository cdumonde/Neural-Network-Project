#ifndef NEURON_H 
#define NEURON_H

//#include <

class Neuron {

public:
  // Constructors
  Neuron(size_t input_number = 1, double learning_rate_definition = 0.5);
  
  // Destructor
  ~Neuron();
  
  // setter
  int set_input(vector<double> input);
  
  // getter
  double get_output();
  
  // Members
  void update();

private:
  // Members
  int output_calcul(void); 
  virtual double threshold(double pre_output) = 0;  

  //attributs
  vector<double> weight;
  vector<double> input;
  double output;
  const double learning_rate; 

};
#endif //NEURON_H
