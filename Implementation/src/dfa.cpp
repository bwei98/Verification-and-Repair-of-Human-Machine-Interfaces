#include <vector>
#include <iostream>
#include "../include/dfa.h"

DFA::DFA (int initial, std::vector<int> Q, std::vector<int> F, int* trans, int sigma) {
  q0 = initial;
  states = Q;
  finals = F;
  transitions = trans;
  alphabet_size = sigma;
}

std::vector<int> DFA::getStates() { return states; }

std::vector<int> DFA::final_bits() { return finals; }

std::vector<int> DFA::get_finals() {
  std::vector<int> fin;
  for(int i = 0; i < num_states(); ++i)
    if(finals[i]) fin.push_back(i);
  return fin;
}

int DFA::init() { return q0; }

int DFA::alph() { return alphabet_size; }

int* DFA::getTrans() { return transitions; }

int DFA::num_states() { return states.size(); }

int DFA::num_finals() { return finals.size(); }

void DFA::print(std::string name) {
  std::cout<<"Printing DFA "<<name<<"..."<<
    "\n Alphabet Size:"<< alphabet_size<<
    "\n Initial State:"<< q0<<
    "\n Number of states:"<< num_states()<<
    "\n Final states:";
    for (auto const& j: get_finals()) {
           std::cout << j << " ";
    }
    std::cout<<"\n Transitions: "<<std::endl;
    for(int q = 0; q < num_states(); ++q){
      std::cout<<q<<": ";
      for(int i = 0; i < alphabet_size; ++i)
        std::cout<<transitions[q*alphabet_size + i]<<" ";
    std::cout<<std::endl;
    }
    std::cout<<"End of DFA"<<std::endl;
}

std::vector<bool> DFA::execute_trace(std::vector<int> trace) {
  int current_state = q0;
  std::vector<bool> visits (1, finals[current_state]);
  for(int a : trace) {
    current_state = transitions[current_state * alphabet_size + a];
    visits.push_back(finals[current_state]);
  }
  return visits;
}

bool DFA::check_property(DFA Property) {
    if(alphabet_size != Property.alph()) {
      std::cout<<"Property must have same alphabet size as DFA"<<std::endl;
      return false;
    }
    if(states.size() == 5)
      return false;

    return true;
}



void DFA::modify(DFA Property) {
  if(!check_property(Property)) {
    std::cout<<"DFA does not satisfy the property to begin with"<<std::endl;
  }
  int num_states = num_states();
  for(int origin_state : states) {
    for(int letter = 0; letter < alphabet_size; ++letter) {
      int old_dest = transitions[origin_state * alphabet_size + letter];
      for(int new_dest = 0; new_dest < num_states; ++new_dest) {
        if(new_dest == old_dest) continue;
        transitions[origin_state * alphabet_size + letter] = new_dest;
        if(!check_property(Property)) return;
      }
      transitions[origin_state * alphabet_size + letter] = old_dest
    }
  }
  // try to remove states
}
