#ifndef CONTROL_BUNCH_INPUT_HPP
#define CONTROL_BUNCH_INPUT_HPP

class ControlBunchInput {
public:
    ControlBunchInput();

    void set_input_parameter(int value);
    double get_input_value() const;

private:
    int input_parameter;
    double input_value;
};

#endif // CONTROL_BUNCH_INPUT_HPP