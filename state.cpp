#include "state.h"

State::State() {
	this->space = new int **[6];
	for (int i = 0; i < 6; i++) {
		this->space[i] = new int *[3];
		for (int j = 0; j < 3; j++) {
			this->space[i][j] = new int[3];
		}
	}
}

State::State(const State &otherState) {
	this->space = new int **[6];
	for (int i = 0; i < 6; i++) {
		this->space[i] = new int *[3];
		for (int j = 0; j < 3; j++) {
			this->space[i][j] = new int[3];
			for (int k = 0; k < 3; k++) {
				this->space[i][j][k] = otherState.space[i][j][k];
			}
			
		}
	}
}

State &State::operator=(const State &otherState) {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				this->space[i][j][k] = otherState.space[i][j][k];
			}
		}
	}
}

State::~State() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			delete[] this->space[i][j];
		}
		delete[] this->space[i];
	}
	delete[] this->space;
}