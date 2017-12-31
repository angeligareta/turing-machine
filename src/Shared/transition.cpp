#include "transition.h"

ostream& operator<<(ostream& output,const Transition& transition)
{
    char movement;
    
    switch (transition.next_movement_) {
        case 1:  movement = 'R'; break;
        case -1: movement = 'L'; break;
        case 0: movement  = 'S'; break;
        default: assert(0);
    }
    
    output << " " << transition.symbol_entry_ << " " << transition.write_value_ << " " << movement << " " << transition.number_next_state_ << endl;
        
    return output;
}

Transition::Transition(){}

Transition::Transition(const char symbol_in, const char write_value_in, const char movement_in, const int number_next_state_in):
symbol_entry_(symbol_in),
write_value_(write_value_in),
next_movement_(),
number_next_state_(number_next_state_in)
{
    ConvertMovementToInt(movement_in);
}

Transition::Transition(const Transition &transition_in):
symbol_entry_(transition_in.symbol_entry_),
write_value_(transition_in.write_value_),
next_movement_(transition_in.next_movement_),
number_next_state_(transition_in.number_next_state_){}

Transition::~Transition(){}

char Transition::get_symbol_entry() const
{
    
    return symbol_entry_;
    
}

char Transition::get_write_value() const
{
    return write_value_;
}

int Transition::get_movement() const
{
    return next_movement_;
}

int Transition::get_next_state() const
{
    
    return number_next_state_;
    
}

void Transition::ConvertMovementToInt(const char movement_in)
{
    switch (movement_in) {
        case 'R': next_movement_ =  1 ; break;
        case 'L': next_movement_ = -1 ; break;
        case 'S': next_movement_ =  0 ; break;
        default: assert(0);
    }    
}

Transition& Transition::operator=(const Transition &transition_in)
{
    
    this->symbol_entry_ = transition_in.symbol_entry_;
    this->write_value_  = transition_in.write_value_;
    this->next_movement_= transition_in.next_movement_;
    this->number_next_state_= transition_in.number_next_state_;
    return *this;
    
}

int Transition::operator==(const Transition &transition_in) const
{
    if( this->symbol_entry_       != transition_in.symbol_entry_ )      return 0;
    if( this->write_value_        != transition_in.write_value_ )       return 0;
    if( this->next_movement_      != transition_in.next_movement_ )     return 0;
    if( this->number_next_state_  != transition_in.number_next_state_)  return 0;
    return 1;
    
}

int Transition::operator<(const Transition &transition_in) const
{
    
    return (symbol_entry_ < transition_in.symbol_entry_);
    
}