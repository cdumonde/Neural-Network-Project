#ifndef NEURON 
#define NEURON

#include <stdio>
//#include <

class Neuron {

public:
  //constructeur
  Neuron(void);
  int set_input(vector<double> input);
  double get_output(void);
  void update(void);

private:
  //membre
  void output_calcul(void);
  virtual double threshold(void);

  //attributs
  vector<double> weight;
  vector<double> input;
  double output;

};
#endif
