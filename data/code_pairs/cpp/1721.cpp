#ifndef MTADJ_VARIABLES_HPP
#define MTADJ_VARIABLES_HPP

#include <vector>
#include <complex>
#include <string>

class MtadjVariables {
public:
    static const int NDIM = 10;
    static const int NPT = 20;
    static const int NMAX_TAPER = 5;

    int iker = 0;
    int itap = 0;
    std::string meas_dir = "";
    std::string adj_dir = "";

    bool BANDPASS = false;
    float tshort = 0.0f, tlong = 0.0f;
    float fstart = 0.0f, fend = 0.0f;

    float BEFORE_SHIFT = 0.0f;
    float wtr = 0.0f;
    float npi = 0.0f;
    int ntaper = 0;
    float wtr_mtm = 0.0f;
    float MIN_DT_SIGMA = 0.0f, MIN_DlnA_SIGMA = 0.0f;

    bool SELECT_WINDOW = false;
    int ncycle_in_window = 0;
    float dt_fac = 0.0f, dt_max_scale = 0.0f, err_fac = 0.0f;

    bool INCLUDE_ERROR = false, BANDPASS_ADJ = false;
    float b_adj = 0.0f, dt_adj = 0.0f;
    int npts_adj = 0;

    std::vector<float> data;
    std::vector<float> syn;
    float b = 0.0f, dt = 0.0f;
    int npts = 0;

    std::vector<float> dataw, synw;
    int nstart = 0, nend = 0, nlen = 0;

    float tshift_cc = 0.0f, dlnA = 0.0f;
    float sigma_tshift_cc = 0.0f, sigma_dlnA_cc = 0.0f;

    std::vector<std::vector<float>> tas;

    int i_left = 0, i_right = 0, idf_fd = 0;
    float f_left = 0.0f, f_right = 0.0f, df_fd = 0.0f;
    int i_pmax = 0;

    std::vector<std::complex<float>> trans_fdm;
    std::vector<float> dtau_fdm, dlnA_fdm;
    std::vector<float> sigma_dtau_fdm, sigma_dlnA_fdm;

    int ipwr_t = 0, ipwr_w = 0;

    MtadjVariables();
};

#endif // MTADJ_VARIABLES_HPP