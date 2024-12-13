#include <vector>
#include <algorithm>
#include <omp.h>

class m_work_4_sph_trans_spin {
public:
    std::vector<double> vr_rtm_wk, sp_rlm_wk;
    const int nnod_rlm = 10, nnod_rtm = 20;

    void allocate_work_sph_trans(int ncomp) {
        sp_rlm_wk.resize(nnod_rlm * ncomp);
        vr_rtm_wk.resize(nnod_rtm * ncomp);

        clear_bwd_legendre_work(ncomp);
        clear_fwd_legendre_work(ncomp);
    }

    void deallocate_work_sph_trans() {
        vr_rtm_wk.clear();
        sp_rlm_wk.clear();
    }

    void clear_fwd_legendre_work(int ncomp) {
        if (ncomp <= 0) return;
        #pragma omp parallel for
        for (int i = 0; i < nnod_rlm * ncomp; ++i) {
            sp_rlm_wk[i] = 0.0;
        }
    }

    void clear_bwd_legendre_work(int ncomp) {
        if (ncomp <= 0) return;
        #pragma omp parallel for
        for (int i = 0; i < nnod_rtm * ncomp; ++i) {
            vr_rtm_wk[i] = 0.0;
        }
    }
};