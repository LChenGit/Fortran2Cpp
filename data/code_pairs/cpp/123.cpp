#include <vector>
#include <string>

void networkinum(std::vector<int>& ipkon, std::vector<int>& inum, std::vector<int>& kon, 
                 const std::vector<std::string>& lakon, int ne, std::vector<int>& itg, 
                 int ntg, int network) {
    
    for (int i = 0; i < ntg; i++) {
        if (inum[itg[i]-1] > 0) inum[itg[i]-1] = -inum[itg[i]-1];
    }

    for (int i = 0; i < ne; i++) {
        if (ipkon[i] < 0) continue;
        std::string lakonl = lakon[i];
        if ((lakonl[0] != 'D') && ((lakonl[0] != 'D') || (network != 1))) continue;

        int indexe = ipkon[i] - 1; // Adjust for 0-based indexing
        if (kon[indexe + 1] != 0) {
            int node1 = kon[indexe + 1] - 1; // Adjust for 0-based indexing
            if (inum[node1] > 0) inum[node1] = -inum[node1];
        }
        int node2 = kon[indexe + 2] - 1; // Adjust for 0-based indexing
        if (inum[node2] > 0) inum[node2] = -inum[node2];
        
        if (kon[indexe + 3] != 0) {
            int node3 = kon[indexe + 3] - 1; // Adjust for 0-based indexing
            if (inum[node3] > 0) inum[node3] = -inum[node3];
        }
    }
}