#include <vector>

class MOD_Filter_Vars {
public:
    int NFilter;
    int FilterType;
    std::vector<double> HestFilterParam;
    std::vector<std::vector<double>> FilterMat;
    bool FilterInitIsDone = false;

    // Conditionally compiled variables
    std::vector<double> lim;
    std::vector<double> eRatio;
    std::vector<double> r;
    std::vector<double> ekin_avg_old;
    std::vector<double> ekin_fluc_avg_old;
    std::vector<std::vector<std::vector<std::vector<std::vector<double>>>>> IntegrationWeight;
    double normMod;
    double LAF_alpha;

    bool DoPPLimiter;
    int iPPRefState;
    double PPEpsFac;
    double PPepsDens;
    double PPepsPres;
    std::vector<int> PP_Elems;
    std::vector<int> PP_Elems_counter;
    int PP_Switch_counter;
    std::vector<double> PP_Elems_Amount;

    MOD_Filter_Vars() {
        // Initialize HestFilterParam with size 3
        HestFilterParam.resize(3);
    }
};