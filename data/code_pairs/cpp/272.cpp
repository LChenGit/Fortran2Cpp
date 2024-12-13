#ifndef CONVERTERCOMMONMODULE_HPP
#define CONVERTERCOMMONMODULE_HPP

class ConverterCommonModule {
private:
    bool SupportPreproc = false;

public:
    // Constructor
    ConverterCommonModule() {}

    // Public getter for SupportPreproc
    bool getSupportPreproc() const {
        return SupportPreproc;
    }

    // Public setter for SupportPreproc
    void setSupportPreproc(bool value) {
        SupportPreproc = value;
    }
};

#endif // CONVERTERCOMMONMODULE_HPP