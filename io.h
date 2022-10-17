#ifndef IO_H
#define IO_h

#include <iostream>
#include <fstream>

#include "state.h"

using namespace std;


void takeInput(State startState, State finalState);

void print(int*** arr);

#endif