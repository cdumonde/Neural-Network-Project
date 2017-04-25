Network(size_t S_data_in, size_t N_input = 1, size_t N_hide = 1, size_t N_output = 1, TYPE_NEURON type = STEP, double learning_rate_def = 0.5 ){

  Layer In = Layer(input,N_input , type, learning_rate_def);
  Layer out = Layer(N_input, N_hide , type, learning_rate_def);
  Layer hide = layer(N_hide ,N_output , type, learning_rate_def);
  Data outputs = Data();

}

bool train(Data input, Data output){

}

string detect(Data input){

}

void get_max_prob(double *prob, string *output){

}

double get_prob(string out){

}
