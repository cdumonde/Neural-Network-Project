#ifndef NEURON_H 
#define NEURON_H

//#include <

class Neuron {

public:
  // Constructors
  Neuron();

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
  void output_calcul(void);
  virtual double threshold(void);

  //attributs
  vector<double> weight;
  vector<double> input;
  double output;

};
#endif //NEURON_H
