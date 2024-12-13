#ifndef TYPES_MOD_H
#define TYPES_MOD_H

class baz_type {
public:
    int id;

    baz_type() : id(0) {}
    virtual void identify() {
        std::cout << "I am baz_type with id: " << id << std::endl;
    }
    virtual ~baz_type() {}
};

class meow_type : public baz_type {
public:
    int special_id;

    meow_type() : baz_type(), special_id(1) {}
    void identify() override {
        std::cout << "I am meow_type with id: " << id << " and special_id: " << special_id << std::endl;
    }
    ~meow_type() {}
};

#endif // TYPES_MOD_H