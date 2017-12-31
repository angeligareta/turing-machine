#include "tape.h"

ostream& operator<<(ostream& output, const Tape& tape_in)
{
    output << "\t\t\t";
    
    for (list<char>::const_iterator it=tape_in.tape_.begin(); it!=tape_in.tape_.end(); ++it)
        cout << *it;
        
    output << endl;
    
    return output;
}

istream& operator>>(istream& input, Tape& tape_in)
{
    tape_in.clear();
    
    bool error=0;
    
    char* string_char = new char; input.getline(string_char,256);
    
    tape_in.tape_.push_back('$');
    
    for (int i=0; i<strlen(string_char);i++){
        if (string_char[i]!=' ')
            tape_in.tape_.push_back(string_char[i]);    
        else
            error=1;
    }
    
    tape_in.tape_.push_back('$');
    
    if(!input.eof()) // Salgo si todavia queda cadena de entrada
        error=1;  
    
    if(error==1)
        tape_in.tape_.clear();
    else{
        
    }
    
    return input;
}

Tape::Tape()
{}
   
Tape::~Tape()
{
    clear();
}

void Tape::InicializeTape()
{
    head_=tape_.begin(); 
    head_++;
}

void Tape::ShowTapeWithState(const int number_state_in) const
{
    cout << string((3*tape_.size()), '-') << endl;
    
    string string_tape, string_head_1, string_head_2;
    
    for (list<char>::const_iterator it=tape_.begin(); it!=tape_.end(); ++it) {
        if (it!=head_){
            string_tape   += *it;
            string_head_1 += ' ';
            string_head_2 += ' ';
        }
        else{
            string_tape   += *it;
            string_head_1 += "q" + to_string(number_state_in);
            string_head_2 += "↓";
        }
    }
    if (head_==tape_.end())
        cout << "HEAD ES NULL" << endl;
        
    cout << string_head_1 << endl;
    cout << string_head_2 << endl;
    cout << string_tape   << endl;
}
    
void Tape::WriteSymbolInTape(const char symbol_in)
{
    *head_ = symbol_in;
}
    
char Tape::ReadSymbolInTape() const
{
    return *head_;
}

void Tape::MoveHeadInTape(const int movement_in)
{
    list<char>::iterator final_iter=tape_.end(); final_iter--;
    
    if  (head_ == tape_.begin())
        tape_.push_front('$');
    else if (head_ == final_iter)
        tape_.push_back('$');
    advance(head_,movement_in);
    
}

bool Tape::is_empty() const
{
    return tape_.empty();
}

void Tape::clear()
{
    tape_.clear();
}