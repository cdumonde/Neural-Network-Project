#ifndef NETWORK_H
#define NETWORK_H

#include <random>
#include "Data.h"
#include "Neuron.h"
#include "Neuron_Sigmoid.h"
#include "Neuron_Step.h"
#include "Neuron_Linear.h"
#include <omp.h>

enum NEURON_TYPE { STEP, LINEAR, SIGMOID };

class Network
{
public:
    Network(const size_t input_size, const size_t output_size, const size_t number_of_layers, NEURON_TYPE type, vector<string> labels);
    ~Network();
    string detect(Data input);
    double train(double learning_rate, double momentum, vector<Data> data, vector<string> result);
    vector<double> calcul_output(Data input);
    void normalize(vector<double> output);
    string get_max_prob();
    double get_prob(string label);

private:
    void initializeNeurons(NEURON_TYPE type);
    void initializeWeights();
    void backpropagate(vector<double> errors);
    void updateweigths();
    vector < vector <Neuron*> > m_neurons;
    double ***m_weights;
    double ***m_delta_weights;
    double *m_probs;
    double m_learning_rate;
    double m_momentum;
    vector<string> m_labels;
    size_t m_input_size, m_output_size, m_hidden_size, m_number_of_layers;

};


#endif // NETWORK_H
