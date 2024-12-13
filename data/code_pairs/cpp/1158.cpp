// iotk_fmt_interf.h
#ifndef IOTK_FMT_INTERF_H
#define IOTK_FMT_INTERF_H

#include <string>

class iotk_basefmt {
public:
    virtual std::string iotk_basefmt_x(const std::string& type, int ikind, int ilen) const = 0;
};

class iotk_wfmt {
public:
    virtual std::string iotk_wfmt_x(const std::string& type, int ikind, int isize, int ilen, const std::string& sep) const = 0;
};

class IOTKFormat : public iotk_basefmt, public iotk_wfmt {
public:
    std::string iotk_basefmt_x(const std::string& type, int ikind, int ilen) const override;
    std::string iotk_wfmt_x(const std::string& type, int ikind, int isize, int ilen, const std::string& sep) const override;
};

#endif // IOTK_FMT_INTERF_H

// iotk_fmt_interf.cpp
#include "iotk_fmt_interf.h"

std::string IOTKFormat::iotk_basefmt_x(const std::string& type, int ikind, int ilen) const {
    return type + std::to_string(ikind) + " Length: " + std::to_string(ilen);
}

std::string IOTKFormat::iotk_wfmt_x(const std::string& type, int ikind, int isize, int ilen, const std::string& sep) const {
    return type + std::to_string(ikind) + " Size: " + std::to_string(isize) + " Length: " + std::to_string(ilen) + " " + sep;
}