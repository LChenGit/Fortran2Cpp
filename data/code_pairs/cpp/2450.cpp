#include <vector>

class Synapse {
public:
    float weight;
    float delta;

    Synapse() : weight(0.0f), delta(0.0f) {}
};

class Neuron {
public:
    std::vector<Synapse> synapses;
    int nextLayerSize;
    float output;
    int id;

    Neuron() : nextLayerSize(0), output(0.0f), id(0) {}
};

class Layer {
public:
    int id;
    int layerSize;
    std::vector<Neuron> neurons;

    Layer() : id(0), layerSize(0) {}
};

class Net {
public:
    int numberOfLayers;
    std::vector<int> topology;
    std::vector<Layer> layers;

    Net() : numberOfLayers(0) {}
};