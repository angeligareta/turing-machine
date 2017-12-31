#include "turing_machine.h"

ostream& operator<<(ostream& output, const TuringMachine& tm_in)
{
    output << tm_in.set_state_.size() << endl;
    
    output << tm_in.GetInitialState().get_identifier() << endl;
    
    for (set<State>::iterator it=tm_in.GetFinalState().begin(); it!=tm_in.GetFinalState().end(); ++it)
        output << (*it).get_identifier() << " ";
        
    output << endl; int transition_counter=0;
    
    for (set<State>::iterator it=tm_in.set_state_.begin(); it!=tm_in.set_state_.end(); ++it)
        transition_counter+=(*it).get_set_transition().size();
    
    output << transition_counter << endl;
    
    for (set<State>::iterator it=tm_in.set_state_.begin(); it!=tm_in.set_state_.end(); ++it)
        output << *it;
    
    return output;
}

istream& operator>>(istream& input, TuringMachine& tm_in)
{
    tm_in.clear();
    bool error=0;
    
    // 1º Linea
    int total_number_state;  input >> total_number_state;
    
    for (int i=0;i<total_number_state;i++) {
        State state(i);
        tm_in.set_state_.insert(state);
    }
    
    // 2º Linea
    int initial_state; input >> initial_state;
    
    State state_aux= tm_in.GetStateWithId(initial_state);
    
    if (state_aux.get_identifier()==-1) error=1;
    
    state_aux.set_initial(1);
    
    tm_in.SwapState(tm_in.GetStateWithId(initial_state),state_aux);
    
    // 3º Linea
    char* string_char = new char; input >> ws; 
    
    input.getline(string_char,256);
    
    for (int i=0; i<strlen(string_char);i++)
        if (string_char[i]!=' ') {
            State state = tm_in.GetStateWithId(string_char[i] - 48);
            
            if (state.get_identifier()==-1) error=1;
            
            state.set_final(1);
            tm_in.SwapState(tm_in.GetStateWithId(string_char[i] - 48),state);
        }
        
    // 4º Linea
    int line_number; input >> line_number; input >> ws;

    // Lineas sucesivas
    
    for (int i=0;i<line_number;i++){
        
        string_char=new char;
        
        input.getline(string_char,256); input >> ws;
        
        State state=tm_in.GetStateWithId(string_char[0]-48);
        
        if (string_char[0]=='\0' || string_char[2]=='\0' || string_char[4]=='\0' || string_char[6]=='\0' || string_char[8]=='\0')
            error=1;
        
        // cout << string_char[2] << string_char[4] << string_char[6] << string_char[8] << endl;
        
        //Inserto los simbolos que me encuentro en la cinta
        tm_in.alphabet_tape_.insert(string_char[2]);
        tm_in.alphabet_tape_.insert(string_char[4]);
        
        state.insert_transition(string_char[2], string_char[4], string_char[6], string_char[8]-48);
        
        tm_in.SwapState(tm_in.GetStateWithId(string_char[0]-48),state);
    }
    
    if (!input.eof()) // Salgo si todavia queda cadena de entrada
        error=1;  
    
    if (error==1)
        tm_in.clear();
    
    return input;
}

TuringMachine::TuringMachine()
{}
   
TuringMachine::~TuringMachine()
{
    clear();
}

int TuringMachine::AnalyzeTape(Tape& tape, const int show)
{
    int stop=0,infinite_counter=-1;
    
    if (is_infinite())
        infinite_counter=0;
    
    int number_actual_state = GetInitialState().get_identifier();
    
    if (show==1 || show==2)
        tape.ShowTapeWithState(number_actual_state);
    
    while (stop==0) {
        State state_aux = GetStateWithId(number_actual_state);
        char actual_symbol = tape.ReadSymbolInTape();
        if (state_aux.get_next_state(actual_symbol) != ERROR_VALUE) {
            if (infinite_counter>=0) infinite_counter++;
            tape.WriteSymbolInTape(state_aux.get_next_write_value(actual_symbol));
            tape.MoveHeadInTape(state_aux.get_next_movement(actual_symbol));
            number_actual_state = state_aux.get_next_state(actual_symbol);
            if (show==1 || show==2) {
                tape.ShowTapeWithState(number_actual_state);
                if (show==2)
                    usleep(1000000);
            }
        }
        else
            stop=1;
        if (infinite_counter==50)
            stop=1;
    }
    
    if (infinite_counter==50) return -1;
    
    return GetStateWithId(number_actual_state).get_final();
    
}

bool TuringMachine::is_empty() const
{
    return set_state_.empty();
}

void TuringMachine::clear()
{
    set_state_.clear();
    alphabet_.clear();
    alphabet_tape_.clear();
}

bool TuringMachine::is_infinite() const
{
    set<State> final_state = GetFinalState();
    set<char> alphabet= alphabet_tape_.get_alphabet();
    
    for (set<State>::iterator it=final_state.begin(); it!=final_state.end(); ++it)
        for (set<State>::iterator it2=set_state_.begin(); it2!=set_state_.end(); ++it2)
            if (!(*it2).get_final())
                for (set<char>::iterator it3=alphabet.begin(); it3!=alphabet.end(); ++it3)
                    if ((*it2).get_next_state(*it3)==(*it).get_identifier())
                        return 0;
                        
    return 1;
    
    /*for (set<State>::iterator it=set_state_.begin(); it!=set_state_.end(); ++it)
        if(!(*it).get_final())
            for (set<char>::iterator it2=alphabet_tape_.get_alphabet().begin() ; it2!=alphabet_tape_.get_alphabet().end() ; ++it2){
                if(((*it).get_next_movement('$')!=ERROR_VALUE) && ((*it).get_next_state('$')==(*it).get_identifier()))
                    return 1;
                else if((*it).get_next_state(*it2)==ERROR_VALUE)
                    return 0;
            }
    
    return 1;*/
}

State TuringMachine::GetStateWithId(const int state_id) const
{
    
    State state_return(-1);
    
    for (set<State>::iterator it=set_state_.begin(); it!=set_state_.end();++it)
        if ((*it).get_identifier()==state_id)
            state_return = (*it);

    return state_return;
}

State TuringMachine::GetInitialState() const
{
    for (set<State>::iterator it=set_state_.begin(); it!=set_state_.end();++it)
        if ((*it).get_initial())
            return (*it);
}

set<State> TuringMachine::GetFinalState() const
{
    set<State> state_return;
    
    for (set<State>::iterator it=set_state_.begin(); it!=set_state_.end();++it)
        if ((*it).get_final())
            state_return.insert(*it);
    
    return state_return;
}

void TuringMachine::SwapState(const State& state_in_1, const State& state_in_2)
{
    set_state_.erase(state_in_1);
    set_state_.insert(state_in_2);
}