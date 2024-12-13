#ifndef FINALIZE_HPP
#define FINALIZE_HPP

extern "C" {
    void finalize_dyn();
    void finalize_phy();
    void shtns_destroy();
    void gfsFinalise();
}

#endif // FINALIZE_HPP