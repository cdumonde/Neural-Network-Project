#include "Layer.h"
  
/**** Constructor ****/
Layer::Layer(size_t input_number = 1, size_t output_number =1, TYPE_NEURON type = STEP, double learning_rate_def = 0.5 ){
  
  switch(type){
    
  case STEP :
    vector<Neuron::Neuron_Step> neuron_tab;
    vector<double> errors;
    vector<double> output;
vector<double> input;

    if (output_number != 1)
      for (int i=0; i < output_number;i++){
	neuron_tab.push_back(new Neuron::Neuron_Step(input_number, learning_rate_def));
	errors.push_back(0.0);
	output.push_back(0.0);
	input.push_back(0.0);
      }
    break;
    
  case LINEAR :
    vector<Neuron::Neuron_Linear> neuron_tab;
    vector<double> errors;
    vector<double> output;
    vector<double> input;

    if (output_number != 1)
      for (int i=1; i < output_number;i++){
	neuron_tab.push_back(new Neuron::Neuron_Linear(input_number, learning_rate_def));
	errors.push_back(0.0);
	output.push_back(0.0);
	input.push_back(0.0);
      }
    break;
    
  case SIGMOID :
    vector<Neuron::Neuron_Sigmoid> neuron_tab;
    vector<double> errors;
    vector<double> output;
    vector<double> input;

    if (output_number != 1)
      for (int i=1; i < output_number;i++){
	neuron_tab.push_back(new Neuron::Neuron_Sigmoid(input_number, learning_rate_def));
	errors.push_back(0.0);
	output.push_back(0.0);  
	input.push_back(0.0);    
      }
    break;
  }
}

/**** Destructor ****/
Layer::~Layer(){}


/***** Membres *****/
bool Layer::update_layer(vector<double> next_layer_errors){
  for(int i=0; i<= neuron_tab.size();i++){ // browse all neuron in the layer
      neuron_tab[i].update(next_layer_errors[i]);  // call of update function of each 
  }
}

vector<double> Layer::get_errors(){
  return errors;
}

/***** Operator *****/
vector<double> Layer::operator>>(const Layer previous_layer){
  
  vector<double> input = previous_Layer.output;
  
  return input;
}

/***** Private Membre *****/
void update_input(){

  for(int i=0; i<neuron_tab.size(); i++) // browse all the neuron of layer
   	neuron_tab[i].set_input(input);
}
