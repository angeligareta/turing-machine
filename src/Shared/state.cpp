#include "state.h"

ostream& operator<<(ostream &output,const State& state){
    
    for (set<Transition>::iterator it=state.set_transition_.begin(); it!=state.set_transition_.end();++it)
        output << state.identifier_ << *it;
    
    return output;
}

State::State():
identifier_(-1),
initial_(0),
final_(0), 
set_transition_(){}

State::State(const int identifier_in):
identifier_(identifier_in),
initial_(0),
final_(0), 
set_transition_(){}

State::State(const State& state_in):
identifier_(state_in.identifier_),
initial_(state_in.initial_),
final_(state_in.final_), 
set_transition_(state_in.set_transition_){}
   
State::~State()
{
    clear();
}

void State::clear()
{
    set_transition_.clear();
}

void State::insert_transition(const char symbol_in, const char write_value_in, const char movement_in, const int number_next_state_in)
{
    Transition transition_temp(symbol_in, write_value_in, movement_in, number_next_state_in);  
    set_transition_.insert(transition_temp);
}
   
void State::set_identifier(const int identifier_in)
{
    identifier_ = identifier_in;
}
   
void State::set_initial(const bool initial_in)
{
    initial_ = initial_in;
}
   
void State::set_final(const bool final_in)
{
    final_ = final_in;
}

int State::get_identifier() const
{
    return identifier_;
}
   
bool State::get_initial() const
{
    return initial_;
}
   
bool State::get_final() const
{
    return final_;
}

set<Transition> State::get_set_transition() const
{
    return set_transition_;
}

int State::get_next_state(const char symbol_in) const
{
    int return_value = ERROR_VALUE;
    
    for(set<Transition>::iterator it=set_transition_.begin(); it!=set_transition_.end();++it)
        if((*it).get_symbol_entry()==symbol_in)
            return_value = (*it).get_next_state();
            
    return return_value;
}

int State::get_next_movement(const char symbol_in) const
{
    int return_value = ERROR_VALUE;
    
    for (set<Transition>::iterator it=set_transition_.begin(); it!=set_transition_.end();++it)
        if ((*it).get_symbol_entry()==symbol_in)
            return_value = (*it).get_movement();
            
    return return_value;        
}

char State::get_next_write_value(const char symbol_in) const
{
    char return_value = ERROR_VALUE;
    
    for (set<Transition>::iterator it=set_transition_.begin(); it!=set_transition_.end();++it)
        if ((*it).get_symbol_entry()==symbol_in)
            return_value = (*it).get_write_value();
            
    return return_value;        
}

void State::SwapTransition(const Transition& transition_1, const Transition& transition_2)
{
    set_transition_.erase(transition_1);
    set_transition_.insert(transition_2);    
}

State& State::operator=(const State &state_in)
{
    this->identifier_= state_in.identifier_;
    this->initial_= state_in.initial_;
    this->final_=state_in.final_;
    this->set_transition_ = state_in.set_transition_;
        
    return *this;
}

int State::operator==(const State &state_in) const
{
    if(this->identifier_ != state_in.identifier_) return 0;
    if(this->initial_ != state_in.initial_) return 0;
    if(this->final_ != state_in.final_) return 0;
    if(this->set_transition_.size() != state_in.set_transition_.size()) return 0;
    
    set<Transition>::iterator iter1=set_transition_.begin();
    set<Transition>::iterator iter2=state_in.set_transition_.begin();
    while(iter1!=set_transition_.end()){
        if(!(*iter1 ==*iter2))
            return 0;
        ++iter1; ++iter2;
    }
    return 1;
}

int State::operator<(const State &state_in) const
{
    return (identifier_ < state_in.identifier_);
}