#ifndef TEMPLATE_MODULE_H
#define TEMPLATE_MODULE_H

class TemplateModule {
public:
    void Sub1(int par1, float& par2, int& par3) {
        par2 += 1.0f;
        par3 = 2;
    }

    float Fun1() {
        return 10.0f;
    }
};

#endif // TEMPLATE_MODULE_H