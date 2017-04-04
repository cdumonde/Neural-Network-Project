  #include "Neuron.h"

 // Constructors
  Neuron::Neuron(size_t input_number = 1 , double learning_rate_definition = 0.5){
    
    for (int cpt_size_in = 0; cpt_size_in < input_number, cpt_size_in++){   // running the vector
        weight[cpt_size_in] = 1;                    // initialization of all weight to 1
        input[cpt_size_in] = 0;                     // initialization of all entries to 0
    }

    learning_rate = learning_rate_definition;

    output = 0;
  }

  // Destructor
  Neuron::~Neuron(){}
  
  // re-initialize the input and calculate the outputs
  int Neuron::set_input(vector<double>  new_input){

      for (int cpt_size = 0; cpt_size < new_input.size() , cpt_size++){   // running the vector                    // initialization of all weight to 1
        input[cpt_size_in] = new_input[cpt_size_in] ;                     // initialization of all entries to 0
      }

      if(output_calcul() != 0);
          return 1;  // problem on output calculation
      else 
          return 0;  //  no problem

  }
  
  // 
  double Neuron::get_output(){
    return output;
  }
  
  // Actualize the weight using the errors argument
  void Neuron::update(double error){

        for( int cpt_weight=0 , cpt_weight < weight.size(), cpt_weight++)
            weight[cpt_weight] += learning_rate*error*input[cpt_weight];   

  }

  // calculate the output
 int output_calcul(void){
    double pre_output=0;

    if(input.size() != weight.size()){
      cout << "Error: input and weight have not the same number" << endl
      return 1;
    }

    // make the summation function
    for(int cpt_sum=0, cpt_sum < input.size(), cpt_sum++){
        pre_output += input[cpt_sum]*weight[cpt_sum];
    } 

    // make the threshold function detection
    output = threshold(pre_output);

 }

