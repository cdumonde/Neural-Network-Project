#include "Network.h"


Network::Network(const size_t input_size, const size_t output_size, const size_t number_of_layers, NEURON_TYPE type, vector<string> labels) {
    m_input_size = input_size;
    m_output_size = output_size;
    m_hidden_size = 50;
    m_number_of_layers = number_of_layers;
    m_probs = new double[m_output_size];
    m_labels = labels;
    initializeNeurons(type);
    initializeWeights();
}
Network::~Network() {
    for(unsigned int l = 0; l < m_number_of_layers; l++) {
        if(l == 0) {
            for(unsigned int i = 0; i < m_input_size + 1; i++) {
                delete m_neurons[l][i];
            }
        }
        else if (l == m_number_of_layers - 1) {
            for(unsigned int i = 0; i < m_output_size; i++) {
                delete m_neurons[l][i];
            }
        }
        else {
            for(unsigned int i = 0; i < m_hidden_size + 1; i++) {
                delete m_neurons[l][i];
            }
        }
    }
    for(unsigned int l = 0; l < m_number_of_layers - 1; l++) {
        if(l == 0) {
            for(unsigned int i = 0; i < m_input_size + 1; i++) {
                delete[] m_weights[l][i];
            }
        }
        else if (l == m_number_of_layers - 2) {
            for(unsigned int i = 0; i < m_output_size; i++) {
                delete[] m_weights[l][i];
            }
        }
        else {
            for(unsigned int i = 0; i < m_hidden_size + 1; i++) {
                delete[] m_weights[l][i];
            }
        }
        delete[] m_weights[l];
    }
    delete[] m_weights;
}
string Network::detect(Data input) {
    vector<double> output;
    output = calcul_output(input);
    normalize(output);
    return get_max_prob();
}
double Network::train(double learning_rate, double momentum, vector<Data> data, vector<string> result) {
    vector<double> intended_output;
    vector<double> errors;
    int incorrect_detections = 0;
    m_learning_rate = learning_rate;
    m_momentum = momentum > 1 ? 1 : momentum;
    m_momentum = m_momentum < 0 ? 0 : m_momentum;
    for(unsigned int i = 0; i < data.size(); i++) {
        intended_output.clear();
        for(unsigned int j = 0; j < m_output_size; j++) {
                if(m_labels[j] == result[i]) {
                    intended_output.push_back(1);
                }
                else
                    intended_output.push_back(0);
          }
        //cout << endl << endl;
        detect(data[i]);
        errors.clear();
        for(unsigned int j = 0; j < m_output_size; j++) {
            errors.push_back(intended_output[j] - m_probs[i]);
            //cout << m_neurons[m_probs[i] << endl;
        }
        backpropagate(errors);
        updateweigths();
        //cout << get_max_prob() << endl;
    }
    for(int i = 0; i < data.size(); i++)
    {
            incorrect_detections+=(detect(data[i]) != result[i]);
    }
    return (100 - ((double)(incorrect_detections)/(data.size())*100));
}
void Network::initializeNeurons(NEURON_TYPE type) {
    vector<Neuron*> tmp;
    for(unsigned int i = 0; i < m_number_of_layers; i++) {
        tmp.clear();
        if(i == 0) {
            for(unsigned int j = 0; j < m_input_size; j++) {
                tmp.push_back(new Neuron_Linear());
            }
            tmp.push_back(new Neuron_Linear());
            tmp[m_input_size]->set_input(-1);
        }
        else if (i == m_number_of_layers - 1) {
            switch(type) {
                case STEP :
                for(unsigned int j = 0; j < m_output_size; j++) {
                    tmp.push_back(new Neuron_Step());
                }
                break;
                case SIGMOID :
                for(unsigned int j = 0; j < m_output_size; j++) {
                    tmp.push_back(new Neuron_Sigmoid());
                }
                break;
                default :
                for(unsigned int j = 0; j < m_output_size; j++) {
                    tmp.push_back(new Neuron_Linear());
                }
                break;
            }
        }
        else {
            switch(type) {
                case STEP :
                for(unsigned int j = 0; j < m_hidden_size; j++) {
                    tmp.push_back(new Neuron_Step());
                }                break;
                case SIGMOID :
                for(unsigned int j = 0; j < m_hidden_size; j++) {
                    tmp.push_back(new Neuron_Sigmoid());
                }
                break;
                default :
                for(unsigned int j = 0; j < m_hidden_size; j++) {
                    tmp.push_back(new Neuron_Linear());
                }
                break;
            }
            tmp.push_back(new Neuron_Linear());
            tmp[m_hidden_size]->set_input(-1);
        }
        m_neurons.push_back(tmp);
    }
}
void Network::initializeWeights() {
    default_random_engine generator;
    uniform_real_distribution<double> distribution(-0.5, 0.5);
    //weights
    m_weights = new double**[m_number_of_layers - 1];
    m_delta_weights = new double**[m_number_of_layers - 1];
    for(unsigned int l = 0; l < m_number_of_layers - 1; l++) {
        if(l == 0) {
            m_weights[l] = new double*[m_input_size + 1];
            for(unsigned int i = 0; i < m_input_size + 1; i++) {
                m_weights[l][i] = new double[m_hidden_size];
                for(unsigned int j = 0; j < m_hidden_size; j++) {
                    m_weights[l][i][j] = distribution(generator);
                }
            }
            m_delta_weights[l] = new double*[m_input_size + 1];
            for(unsigned int i = 0; i < m_input_size + 1; i++) {
                m_delta_weights[l][i] = new double[m_hidden_size];
                for(unsigned int j = 0; j < m_hidden_size; j++) {
                    m_delta_weights[l][i][j] = 0;
                }
            }
        }
        else if(l == m_number_of_layers - 2) {
            m_weights[l] = new double*[m_hidden_size + 1];
            for(unsigned int i = 0; i < m_hidden_size + 1; i++) {
                m_weights[l][i] = new double[m_output_size];
                for(unsigned int j = 0; j < m_output_size; j++) {
                    m_weights[l][i][j] = distribution(generator);
                }
            }
            m_delta_weights[l] = new double*[m_hidden_size + 1];
            for(unsigned int i = 0; i < m_hidden_size + 1; i++) {
                m_delta_weights[l][i] = new double[m_output_size];
                for(unsigned int j = 0; j < m_output_size; j++) {
                    m_delta_weights[l][i][j] = 0;
                }
            }
        }
        else {
            m_weights[l] = new double*[m_hidden_size + 1];
            for(unsigned int i = 0; i < m_hidden_size + 1; i++) {
                m_weights[l][i] = new double[m_hidden_size];
                for(unsigned int j = 0; j < m_hidden_size; j++) {
                    m_weights[l][i][j] = distribution(generator);
                }
            }
            m_delta_weights[l] = new double*[m_hidden_size + 1];
            for(unsigned int i = 0; i < m_hidden_size + 1; i++) {
                m_delta_weights[l][i] = new double[m_hidden_size];
                for(unsigned int j = 0; j < m_hidden_size; j++) {
                    m_delta_weights[l][i][j] = 0;
                }
            }
        }
    }

}
vector<double> Network::calcul_output(Data input) {
    double sum;
    vector<double> output;
    for(unsigned int l = 0; l < m_number_of_layers; l++) {
        if(l == 0) {
            sum = 0;
            #pragma omp for
            for(unsigned int i = 0; i < m_input_size; i++) {
                m_neurons[l][i]->set_input(input.at(i));
            }
        }
        else if(l == 1) {
            for(unsigned int j = 0; j < m_hidden_size; j++) {
                sum = 0;
                #pragma omp for
                for(unsigned int i = 0; i < m_input_size + 1; i++) {
                    sum += (m_neurons[l-1][i])->get_output()*m_weights[l-1][i][j];
                }
                m_neurons[l][j]->set_input(sum);
            }
        }
        else if(l == m_number_of_layers - 1) {
            for(unsigned int j = 0; j < m_output_size; j++) {
                sum = 0;
                #pragma omp for
                for(unsigned int i = 0; i < m_hidden_size + 1; i++) {
                    sum += (m_neurons[l-1][i])->get_output()*m_weights[l-1][i][j];
                }
                m_neurons[l][j]->set_input(sum);
                output.push_back((m_neurons[l][j])->get_output());
            }
        }
        else {
            for(unsigned int j = 0; j < m_hidden_size; j++) {
                sum = 0;
                #pragma omp for
                for(unsigned int i = 0; i < m_hidden_size + 1; i++) {
                    sum += (m_neurons[l-1][i])->get_output()*m_weights[l-1][i][j];
                }
                m_neurons[l][j]->set_input(sum);
            }
        }
    }
    return output;
}
void Network::normalize(vector<double> output) {
    for(unsigned int i = 0; i < m_output_size; i++) {
        if(output[i] > 0.9) {
            m_probs[i] = 1;
        }
        else if(output[i] < 0.001) {
            m_probs[i] = 0;
        }
        else {
            m_probs[i] = output[i];
        }
    }
}
string Network::get_max_prob() {
    int index_max = 0;
    string detection = m_labels[0];
    for(unsigned int i = 0; i < m_output_size; i++) {
        if(m_probs[i] > m_probs[index_max]) {
            index_max = i;
            detection = m_labels[i];
        }
    }
    return detection;
}
double Network::get_prob(string label) {
    for(unsigned int i = 0; i < m_output_size; i++) {
        if(m_labels[i] == label) {
            return m_probs[i];
        }
    }
    return -1;
}
void Network::backpropagate(vector<double> errors) {
    double sum;
    for(unsigned int l = 0; l < m_number_of_layers; l++) {
        if(l == 0) {
            sum = 0;
        }
        else if(l == m_number_of_layers - 2) {
            for(unsigned int i = 0; i < m_hidden_size + 1; i++) {
                sum = 0;
                #pragma omp for
                for(unsigned int j = 0; j < m_output_size; j++) {
                    sum+=m_weights[l][i][j]*(m_neurons[l+1][j]->get_error());
                }
                m_neurons[l][i]->set_error(m_neurons[l][i]->threshold_derivative()*sum);
            }
        }
        else if(l == m_number_of_layers - 1) {
            for(unsigned int j = 0; j < m_output_size; j++) {
                m_neurons[l][j]->set_error(m_neurons[l][j]->threshold_derivative()*errors[j]);
            }
        }
        else {
            for(unsigned int i = 0; i < m_hidden_size + 1; i++) {
                sum = 0;
                #pragma omp for
                for(unsigned int j = 0; j < m_hidden_size; j++) {
                    sum+=m_weights[l][i][j]*(m_neurons[l+1][j]->get_error());
                }
                m_neurons[l][i]->set_error(m_neurons[l][i]->threshold_derivative()*sum);
            }
        }
    }
}
void Network::updateweigths() {
    #pragma omp for
    for(unsigned int l = 0; l < m_number_of_layers - 1; l++) {
        if(l == 0) {
            for(unsigned int i = 0; i < m_input_size + 1; i++) {
                for(unsigned int j = 0; j < m_hidden_size; j++) {
                    m_delta_weights[l][i][j] = m_momentum*m_learning_rate * m_neurons[l+1][j]->get_error() * m_neurons[l][i]->get_output() + (1 - m_momentum) * m_delta_weights[l][i][j];
                    m_weights[l][i][j] += m_delta_weights[l][i][j];
                }
            }
        }
        else if(l == m_number_of_layers - 2) {
            for(unsigned int i = 0; i < m_hidden_size + 1; i++) {
                for(unsigned int j = 0; j < m_output_size; j++) {
                    m_delta_weights[l][i][j] = m_momentum*m_learning_rate * m_neurons[l+1][j]->get_error() * m_neurons[l][i]->get_output() + (1 - m_momentum) * m_delta_weights[l][i][j];
                    m_weights[l][i][j] += m_delta_weights[l][i][j];
                }
            }
        }
        else {
            for(unsigned int i = 0; i < m_hidden_size + 1; i++) {
                for(unsigned int j = 0; j < m_hidden_size; j++) {
                    m_delta_weights[l][i][j] = m_momentum*m_learning_rate * m_neurons[l+1][j]->get_error() * m_neurons[l][i]->get_output() + (1 - m_momentum) * m_delta_weights[l][i][j];
                    m_weights[l][i][j] += m_delta_weights[l][i][j];
                }
            }
        }
    }
}
