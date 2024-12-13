#ifndef SPECIESNETWORK_HPP
#define SPECIESNETWORK_HPP

#include <string>
#include <vector>

class SpeciesNetwork {
private:
    static const int max_species = 10;
    std::vector<std::string> species_names;
    std::vector<int> atomic_numbers;
    int num_species;

public:
    SpeciesNetwork();

    void init_network();
    int find_species_index(const std::string& name);
};

#endif // SPECIESNETWORK_HPP