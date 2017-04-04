#ifndef NETWORK_H
#define NETWORK_H

class Network{

private:
  // constructors
  Network(size_t input_number);

  // Destructors
  ~Network();
  
  // members
  bool train(Data input);
  string detect(Data input);

  // getters
  void get_max_prob(double *prob, string *output);
  dougle get_prob(string out);

public: 
  // attributs
  Layer out;
  Layer in;
  Layer hiden;
  Data outputs


};
#endif // NETWORK_H
