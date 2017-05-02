#ifndef LAYER_H
#define LAYER_H

#include "Data.h"
#include "Neuron_Step.h"
#include "Neuron_Linear.h"
#include "Neuron_Sigmoid.h"

enum TYPE_NEURON { STEP, LINEAR, SIGMOID };

class Layer {

 public:
  // Constructor
  Layer(size_t output_number = 1, TYPE_NEURON type = STEP, double learning_rate_def = 0.5 );
  
  // Destructor
  ~Layer();
  
  // Membres
  bool update_layer(std::vector<double> errors);
  void update_outputs(Data input);
  Data get_outputs();
  size_t size();
  vector<double> get_errors();
  
 private:
  // Private Membre
  void update_input();

  //attributes
  vector<Neuron*> m_neurons_tab;
  vector<double>  m_errors;
  Data  m_output;

};

// Operator
Layer& operator<<(Layer &l0, Data const& l1);
Layer& operator<<(Layer &l0, Layer const& l1);
Data& operator<<(Data &l0, Layer const& l1);

#endif /* LAYER_ */
