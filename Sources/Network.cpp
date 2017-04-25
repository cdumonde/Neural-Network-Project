Layer::Network(size_t S_data_in, size_t N_input = 1, size_t N_hide = 1, size_t N_output = 1, TYPE_NEURON type = STEP, double learning_rate_def = 0.5 ){

  Layer In = Layer(input,N_input , type, learning_rate_def);
  Layer out = Layer(N_input, N_hide , type, learning_rate_def);
  Layer hide = layer(N_hide ,N_output , type, learning_rate_def);
  Data outputs = Data();

}

bool Layer::train(Data input, Data output){

  In.input = input; // give data to the In-layer
  In.update_output();// calculate all output of the In-layer

  Hide.input << In;  // give outputs of In-layer to the Hide-layer
  Hide.update_output();// calculate all output of the Hide-Layer

  Out.input << Hide; // give outputs of Hide-layer to the out-layer
  Out.update_output();// calculate all output of the Out-layer

  vector<double> errors_for_out;

  for (int i = 0; i <= neurons_tab.size() ; i++) {
    errors_for_out.push_back( Out.output[i] - output.data[i] );
  }

  Out.update_layer(errors_for_out);
  Hide.update_layer(Out.get_errors());
}

string Layer::detect(Data input){

}

void Layer::get_max_prob(double *prob, string *output){

}

double Layer::get_prob(string out){

}
