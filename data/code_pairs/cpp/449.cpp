// test_module.cpp
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cassert>

class ODBase {
public:
    int value;
};

class ODFName {
public:
    virtual void operator()(ODBase& base, int& nfam, std::vector<std::string>& cnames) = 0;
    virtual void operator()(ODBase& base, int pos, std::string& cname) = 0;
};

class ODFamilyCName : public ODFName {
public:
    void operator()(ODBase& base, int& nfam, std::vector<std::string>& cnames) override {
        nfam = static_cast<int>(cnames.size());
        std::fill(cnames.begin(), cnames.end(), "odfamilycnames");
    }

    void operator()(ODBase& base, int pos, std::string& cname) override {
        cname = "odfamilycname";
    }
};

int main() {
    ODBase base;
    ODFamilyCName odfname;
    int i = 1;
    std::string cname;
    std::vector<std::string> cnames(1);
    
    odfname(base, i, cname);
    assert(cname == "odfamilycname");
    
    int nfam = static_cast<int>(cnames.size());
    odfname(base, nfam, cnames);
    assert(cnames[0] == "odfamilycnames");
    
    std::cout << "All tests passed!" << std::endl;
    
    return 0;
}