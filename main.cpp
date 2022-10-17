#include <stack>
#include <vector>
#include <iostream>

#include "io.h"
#include "state.h"

using namespace std;


State rightAntiClock(State state) {
	State temp(state);

	temp.space[4][0][1] = state.space[4][1][0];
	temp.space[4][1][0] = state.space[4][2][1];
	temp.space[4][2][1] = state.space[4][1][2];
	temp.space[4][1][2] = state.space[4][0][1];

	temp.space[4][0][0] = state.space[4][2][0];
	temp.space[4][2][0] = state.space[4][2][2];
	temp.space[4][2][2] = state.space[4][0][2];
	temp.space[4][0][2] = state.space[4][0][0];

	temp.space[0][0][2] = state.space[3][0][2];
	temp.space[0][1][2] = state.space[3][1][2];
	temp.space[0][2][2] = state.space[3][2][2];

	temp.space[3][0][2] = state.space[5][0][2];
	temp.space[3][1][2] = state.space[5][1][2];
	temp.space[3][2][2] = state.space[5][2][2];

	temp.space[5][0][2] = state.space[1][0][2];
	temp.space[5][1][2] = state.space[1][1][2];
	temp.space[5][2][2] = state.space[1][2][2];

	temp.space[1][0][2] = state.space[0][0][2];
	temp.space[1][1][2] = state.space[0][1][2];
	temp.space[1][2][2] = state.space[0][2][2];

	return temp;
}

State rightClock(State state) {
	State temp;

	temp.space[4][0][1] = state.space[4][1][2];
	temp.space[4][1][0] = state.space[4][0][1];
	temp.space[4][2][1] = state.space[4][1][0];
	temp.space[4][1][2] = state.space[4][2][1];

	temp.space[4][0][0] = state.space[4][0][2];
	temp.space[4][2][0] = state.space[4][0][0];
	temp.space[4][2][2] = state.space[4][2][0];
	temp.space[4][0][2] = state.space[4][2][2];

	temp.space[0][0][2] = state.space[1][0][2];
	temp.space[0][1][2] = state.space[1][1][2];
	temp.space[0][2][2] = state.space[1][2][2];

	temp.space[3][0][2] = state.space[0][0][2];
	temp.space[3][1][2] = state.space[0][1][2];
	temp.space[3][2][2] = state.space[0][2][2];

	temp.space[5][0][2] = state.space[3][0][2];
	temp.space[5][1][2] = state.space[3][1][2];
	temp.space[5][2][2] = state.space[3][2][2];

	temp.space[1][0][2] = state.space[5][0][2];
	temp.space[1][1][2] = state.space[5][1][2];
	temp.space[1][2][2] = state.space[5][2][2];

	return temp;
}

State upClock(State state) {
	State temp;

	temp.space[0][0][1] = state.space[0][1][2];
	temp.space[0][1][0] = state.space[0][0][1];
	temp.space[0][2][1] = state.space[0][1][0];
	temp.space[0][1][2] = state.space[0][2][1];

	temp.space[0][0][0] = state.space[0][0][2];
	temp.space[0][2][0] = state.space[0][0][0];
	temp.space[0][2][2] = state.space[0][2][0];
	temp.space[0][0][2] = state.space[0][2][2];

	temp.space[2][0][0] = state.space[1][0][0];
	temp.space[2][1][0] = state.space[1][1][0];
	temp.space[2][2][0] = state.space[1][2][0];

	temp.space[3][0][0] = state.space[2][0][0];
	temp.space[3][1][0] = state.space[2][1][0];
	temp.space[3][2][0] = state.space[2][2][0];

	temp.space[4][0][0] = state.space[3][0][0];
	temp.space[4][1][0] = state.space[3][1][0];
	temp.space[4][2][0] = state.space[3][2][0];

	temp.space[1][0][0] = state.space[4][0][0];
	temp.space[1][1][0] = state.space[4][1][0];
	temp.space[1][2][0] = state.space[4][2][0];

	return temp;
}

State upAntiClock(State state) {
	State temp;

	temp.space[0][0][1] = state.space[0][1][0];
	temp.space[0][1][0] = state.space[0][2][1];
	temp.space[0][2][1] = state.space[0][1][2];
	temp.space[0][1][2] = state.space[0][0][1];

	temp.space[0][0][0] = state.space[0][2][0];
	temp.space[0][2][0] = state.space[0][2][2];
	temp.space[0][2][2] = state.space[0][0][2];
	temp.space[0][0][2] = state.space[0][0][0];

	temp.space[2][0][0] = state.space[3][0][0];
	temp.space[2][1][0] = state.space[3][1][0];
	temp.space[2][2][0] = state.space[3][2][0];

	temp.space[3][0][0] = state.space[4][0][0];
	temp.space[3][1][0] = state.space[4][1][0];
	temp.space[3][2][0] = state.space[4][2][0];

	temp.space[4][0][0] = state.space[1][0][0];
	temp.space[4][1][0] = state.space[1][1][0];
	temp.space[4][2][0] = state.space[1][2][0];

	temp.space[1][0][0] = state.space[2][0][0];
	temp.space[1][1][0] = state.space[2][1][0];
	temp.space[1][2][0] = state.space[2][2][0];

	return temp;
}

State leftClock(State state)
{
	State temp(state);

	temp.space[2][0][1] = state.space[2][1][0];
	temp.space[2][1][0] = state.space[2][2][1];
	temp.space[2][2][1] = state.space[2][1][2];
	temp.space[2][1][2] = state.space[2][0][1];

	temp.space[2][0][0] = state.space[2][2][0];
	temp.space[2][2][0] = state.space[2][2][2];
	temp.space[2][2][2] = state.space[2][0][2];
	temp.space[2][0][2] = state.space[2][0][0];

	temp.space[0][0][0] = state.space[3][0][0];
	temp.space[0][1][0] = state.space[3][1][0];
	temp.space[0][2][0] = state.space[3][2][0];

	temp.space[3][0][0] = state.space[5][0][0];
	temp.space[3][1][0] = state.space[5][1][0];
	temp.space[3][2][0] = state.space[5][2][0];

	temp.space[5][0][0] = state.space[1][0][0];
	temp.space[5][1][0] = state.space[1][1][0];
	temp.space[5][2][0] = state.space[1][2][0];

	temp.space[1][0][0] = state.space[0][0][0];
	temp.space[1][1][0] = state.space[0][1][0];
	temp.space[1][2][0] = state.space[0][2][0];

	return temp;
}

State leftAntiClock(State state)
{
	State temp;

	temp.space[2][0][1] = state.space[2][1][2];
	temp.space[2][1][0] = state.space[2][0][1];
	temp.space[2][2][1] = state.space[2][1][0];
	temp.space[2][1][2] = state.space[2][2][1];

	temp.space[2][0][0] = state.space[2][0][2];
	temp.space[2][2][0] = state.space[2][0][0];
	temp.space[2][2][2] = state.space[2][2][0];
	temp.space[2][0][2] = state.space[2][2][2];

	temp.space[0][0][0] = state.space[1][0][0];
	temp.space[0][1][0] = state.space[1][1][0];
	temp.space[0][2][0] = state.space[1][2][0];

	temp.space[3][0][0] = state.space[0][0][0];
	temp.space[3][1][0] = state.space[0][1][0];
	temp.space[3][2][0] = state.space[0][2][0];

	temp.space[5][0][0] = state.space[3][0][0];
	temp.space[5][1][0] = state.space[3][1][0];
	temp.space[5][2][0] = state.space[3][2][0];

	temp.space[1][0][0] = state.space[5][0][0];
	temp.space[1][1][0] = state.space[5][1][0];
	temp.space[1][2][0] = state.space[5][2][0];

	return temp;
}

State downClock(State state) {
	State temp;

	temp.space[5][0][1] = state.space[5][1][0];
	temp.space[5][1][0] = state.space[5][2][1];
	temp.space[5][2][1] = state.space[5][1][2];
	temp.space[5][1][2] = state.space[5][0][1];

	temp.space[5][0][0] = state.space[5][2][0];
	temp.space[5][2][0] = state.space[5][2][2];
	temp.space[5][2][2] = state.space[5][0][2];
	temp.space[5][0][2] = state.space[5][0][0];

	temp.space[2][0][2] = state.space[3][0][2];
	temp.space[2][1][2] = state.space[3][1][2];
	temp.space[2][2][2] = state.space[3][2][2];

	temp.space[3][0][2] = state.space[4][0][2];
	temp.space[3][1][2] = state.space[4][1][2];
	temp.space[3][2][2] = state.space[4][2][2];

	temp.space[4][0][2] = state.space[1][0][2];
	temp.space[4][1][2] = state.space[1][1][2];
	temp.space[4][2][2] = state.space[1][2][2];

	temp.space[1][0][2] = state.space[2][0][2];
	temp.space[1][1][2] = state.space[2][1][2];
	temp.space[1][2][2] = state.space[2][2][2];

	return temp;
}

State downAntiClock(State state) {
	State temp;

	temp.space[5][0][1] = state.space[5][1][2];
	temp.space[5][1][0] = state.space[5][0][1];
	temp.space[5][2][1] = state.space[5][1][0];
	temp.space[5][1][2] = state.space[5][2][1];

	temp.space[5][0][0] = state.space[5][0][2];
	temp.space[5][2][0] = state.space[5][0][0];
	temp.space[5][2][2] = state.space[5][2][0];
	temp.space[5][0][2] = state.space[5][2][2];

	temp.space[2][0][2] = state.space[1][0][2];
	temp.space[2][1][2] = state.space[1][1][2];
	temp.space[2][2][2] = state.space[1][2][2];

	temp.space[3][0][2] = state.space[2][0][2];
	temp.space[3][1][2] = state.space[2][1][2];
	temp.space[3][2][2] = state.space[2][2][2];

	temp.space[4][0][2] = state.space[3][0][2];
	temp.space[4][1][2] = state.space[3][1][2];
	temp.space[4][2][2] = state.space[3][2][2];

	temp.space[1][0][2] = state.space[4][0][2];
	temp.space[1][1][2] = state.space[4][1][2];
	temp.space[1][2][2] = state.space[4][2][2];

	return temp;
}

State frontClock(State state) {
	State temp;

	temp.space[1][0][1] = state.space[1][1][2];
	temp.space[1][1][0] = state.space[1][0][1];
	temp.space[1][2][1] = state.space[1][1][0];
	temp.space[1][1][2] = state.space[1][2][1];

	temp.space[1][0][0] = state.space[1][0][2];
	temp.space[1][2][0] = state.space[1][0][0];
	temp.space[1][2][2] = state.space[1][2][0];
	temp.space[1][0][2] = state.space[1][2][2];

	temp.space[0][0][2] = state.space[2][0][2];
	temp.space[0][1][2] = state.space[2][1][2];
	temp.space[0][2][2] = state.space[2][2][2];

	temp.space[4][0][2] = state.space[0][0][2];
	temp.space[4][1][2] = state.space[0][1][2];
	temp.space[4][2][2] = state.space[0][2][2];

	temp.space[5][0][2] = state.space[4][0][2];
	temp.space[5][1][2] = state.space[4][1][2];
	temp.space[5][2][2] = state.space[4][2][2];

	temp.space[2][0][2] = state.space[5][0][2];
	temp.space[2][1][2] = state.space[5][1][2];
	temp.space[2][2][2] = state.space[5][2][2];

	return temp;
}

State frontAntiClock(State state) {
	State temp;

	temp.space[1][0][1] = state.space[1][1][0];
	temp.space[1][1][0] = state.space[1][2][1];
	temp.space[1][2][1] = state.space[1][1][2];
	temp.space[1][1][2] = state.space[1][0][1];

	temp.space[1][0][0] = state.space[1][2][0];
	temp.space[1][2][0] = state.space[1][2][2];
	temp.space[1][2][2] = state.space[1][0][2];
	temp.space[1][0][2] = state.space[1][0][0];

	temp.space[5][0][2] = state.space[2][0][2];
	temp.space[5][1][2] = state.space[2][1][2];
	temp.space[5][2][2] = state.space[2][2][2];

	temp.space[2][0][2] = state.space[0][0][2];
	temp.space[2][1][2] = state.space[0][1][2];
	temp.space[2][2][2] = state.space[0][2][2];

	temp.space[0][0][2] = state.space[4][0][2];
	temp.space[0][1][2] = state.space[4][1][2];
	temp.space[0][2][2] = state.space[4][2][2];

	temp.space[4][0][2] = state.space[5][0][2];
	temp.space[4][1][2] = state.space[5][1][2];
	temp.space[4][2][2] = state.space[5][2][2];

	return temp;
}

State backClock(State state) {
	State temp;

	temp.space[3][0][1] = state.space[3][1][0];
	temp.space[3][1][0] = state.space[3][2][1];
	temp.space[3][2][1] = state.space[3][1][2];
	temp.space[3][1][2] = state.space[3][0][1];

	temp.space[3][0][0] = state.space[3][2][0];
	temp.space[3][2][0] = state.space[3][2][2];
	temp.space[3][2][2] = state.space[3][0][2];
	temp.space[3][0][2] = state.space[3][0][0];

	temp.space[5][0][0] = state.space[2][0][0];
	temp.space[5][1][0] = state.space[2][1][0];
	temp.space[5][2][0] = state.space[2][2][0];

	temp.space[2][0][0] = state.space[0][0][0];
	temp.space[2][1][0] = state.space[0][1][0];
	temp.space[2][2][0] = state.space[0][2][0];

	temp.space[0][0][0] = state.space[4][0][0];
	temp.space[0][1][0] = state.space[4][1][0];
	temp.space[0][2][0] = state.space[4][2][0];

	temp.space[4][0][0] = state.space[5][0][0];
	temp.space[4][1][0] = state.space[5][1][0];
	temp.space[4][2][0] = state.space[5][2][0];

	return temp;
}

State backAntiClock(State state) {
	State temp;

	temp.space[3][0][1] = state.space[3][1][2];
	temp.space[3][1][0] = state.space[3][0][1];
	temp.space[3][2][1] = state.space[3][1][0];
	temp.space[3][1][2] = state.space[3][2][1];

	temp.space[3][0][0] = state.space[3][0][2];
	temp.space[3][2][0] = state.space[3][0][0];
	temp.space[3][2][2] = state.space[3][2][0];
	temp.space[3][0][2] = state.space[3][2][2];

	temp.space[0][0][0] = state.space[2][0][0];
	temp.space[0][1][0] = state.space[2][1][0];
	temp.space[0][2][0] = state.space[2][2][0];

	temp.space[4][0][0] = state.space[0][0][0];
	temp.space[4][1][0] = state.space[0][1][0];
	temp.space[4][2][0] = state.space[0][2][0];

	temp.space[5][0][0] = state.space[4][0][0];
	temp.space[5][1][0] = state.space[4][1][0];
	temp.space[5][2][0] = state.space[4][2][0];

	temp.space[2][0][0] = state.space[5][0][0];
	temp.space[2][1][0] = state.space[5][1][0];
	temp.space[2][2][0] = state.space[5][2][0];

	return temp;
}

bool compareState(State currentState, State finalState)
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				if (currentState.space[i][j][k] != finalState.space[i][j][k])
					return false;
			}	
		}	
	}
	return true;
}

void printStack(stack<int> s)
{
	while (!s.empty())
	{
		cout << '\t' << s.top();
		s.pop();
	}
	cout << endl;
}

class Node {
public:
	State state;
	int prevMove;
	int depthLevel;
    Node * parent;
	vector<Node *> child;
	
	Node() {
		prevMove = 0;
		depthLevel = 0;
		parent = nullptr;
	}

	void generateChild() {
		
		Node * temp = new Node[1];

		temp->state = leftClock(this->state);
		temp->depthLevel = this->depthLevel + 1;
		temp->prevMove = 1;
		temp->parent = this;

		this->child.push_back(temp);

		temp->state = leftAntiClock(this->state);
		temp->prevMove = 2;
		this->child.push_back(temp);

		temp->state = rightClock(this->state);
		temp->prevMove = 3;
		this->child.push_back(temp);

		temp->state = rightAntiClock(this->state);
		temp->prevMove = 4;
		this->child.push_back(temp);

		temp->state = upClock(this->state);
		temp->prevMove = 5;
		this->child.push_back(temp);

		temp->state = upAntiClock(this->state);
		temp->prevMove = 6;
		this->child.push_back(temp);

		temp->state = downClock(this->state);
		temp->prevMove = 7;
		this->child.push_back(temp);

		temp->state = downAntiClock(this->state);
		temp->prevMove = 8;
		this->child.push_back(temp);

		temp->state = frontClock(this->state);
		temp->prevMove = 9;
		this->child.push_back(temp);

		temp->state = frontAntiClock(this->state);
		temp->prevMove = 10;
		this->child.push_back(temp);

		temp->state = backClock(this->state);
		temp->prevMove = 11;
		this->child.push_back(temp);

		temp->state = backAntiClock(this->state);
		temp->prevMove = 12;
		this->child.push_back(temp);



	}

	void setCurrState(State state) {
		this->state = state;
	}

	State getCurrState() {
		return this->state;
	}

	void setprevMove(int move) {
		this->prevMove = move;
	}

	int getprevMove() {
		return this->prevMove;
	}

	void setdepthLevel(int depth) {
		this->depthLevel = depth;
	}

	int getdepthLevel() {
		return this->depthLevel;
	}

	void setParent(Node * p) {
		this->parent = p;
	}

	Node * getParent() {
		return this->parent;
	}

	void addChild(Node * c)
	{
		this->child.push_back(c);
	}
     
};

void addChilds(Node * p, stack<Node *> &s)
{
	    // leftClock         1
		// leftAntiClock     2
		// rightClock        3
		// rightAntiClock    4
		// upClock           5
		// upAntiClock       6
		// downClock         7
		// downAntiClock     8
		// frontClock        9
		// frontAntiClock    10
		// backClock         11
		// backAntiClock     12
	
	Node * temp1 = new Node[1];
	temp1->state = leftClock(p->state);
	temp1->depthLevel = p->depthLevel + 1;
	temp1->parent = p;
	temp1->prevMove = 1;
	p->addChild(temp1);
	s.push(temp1);

	Node * temp4 = new Node[1];
	temp4->state = rightAntiClock(p->state);
	temp4->depthLevel = p->depthLevel + 1;
	temp4->parent = p;
	temp4->prevMove = 4;
	p->addChild(temp4);
	s.push(temp4);

	Node * temp3 = new Node[1];
	temp3->state = rightClock(p->state);
	temp3->depthLevel = p->depthLevel + 1;
	temp3->parent = p;
	temp3->prevMove = 3;
	p->addChild(temp3);
	s.push(temp3);

	Node * temp7 = new Node[1];
	temp7->state = downClock(p->state);
	temp7->depthLevel = p->depthLevel + 1;
	temp7->parent = p;
	temp7->prevMove = 7;
	p->addChild(temp7);
	s.push(temp7);

	Node * temp10 = new Node[1];
	temp10->state = frontAntiClock(p->state);
	temp10->depthLevel = p->depthLevel + 1;
	temp10->parent = p;
	temp10->prevMove = 10;
	p->addChild(temp10);
	s.push(temp10);

	Node * temp5 = new Node[1];
	temp5->state = upClock(p->state);
	temp5->depthLevel = p->depthLevel + 1;
	temp5->parent = p;
	temp5->prevMove = 5;
	p->addChild(temp5);
	s.push(temp5);

	Node * temp2 = new Node[1];
	temp2->state = leftAntiClock(p->state);
	temp2->depthLevel = p->depthLevel + 1;
	temp2->parent = p;
	temp2->prevMove = 2;
	p->addChild(temp2);
	s.push(temp2);

	Node * temp8 = new Node[1];
	temp8->state = downAntiClock(p->state);
	temp8->depthLevel = p->depthLevel + 1;
	temp8->parent = p;
	temp8->prevMove = 8;
	p->addChild(temp8);
	s.push(temp8);

	Node * temp12 = new Node[1];
	temp12->state = backAntiClock(p->state);
	temp12->depthLevel = p->depthLevel + 1;
	temp12->parent = p;
	temp12->prevMove = 12;
	p->addChild(temp12);
	s.push(temp12);

	Node * temp9 = new Node[1];
	temp9->state = frontClock(p->state);
	temp9->depthLevel = p->depthLevel + 1;
	temp9->parent = p;
	temp9->prevMove = 9;
	p->addChild(temp9);
	s.push(temp9);

	

	Node * temp6 = new Node[1];
	temp6->state = upAntiClock(p->state);
	temp6->depthLevel = p->depthLevel + 1;
	temp6->parent = p;
	temp6->prevMove = 6;
	p->addChild(temp6);
	s.push(temp6);

	Node * temp11 = new Node[1];
	temp11->state = backClock(p->state);
	temp11->depthLevel = p->depthLevel + 1;
	temp11->parent = p;
	temp11->prevMove = 11;
	p->addChild(temp11);
	s.push(temp11);

	
	
}

void printStackWithMoves(stack<int> s) {
		// leftClock         1
		// leftAntiClock     2
		// rightClock        3
		// rightAntiClock    4
		// upClock           5
		// upAntiClock       6
		// downClock         7
		// downAntiClock     8
		// frontClock        9
		// frontAntiClock    10
		// backClock         11
		// backAntiClock     12
	while (!s.empty())
	{
		int p = s.top();
		if (p == 1) {
			cout << "move Left ClockWise" << endl;
		}
		else if (p == 2) {
			cout << "move Left AntiClockWise" << endl;
		}
		else if (p == 3) {
			cout << "move Right ClockWise" << endl;
		}
		else if (p == 4) {
			cout << "move Right AntiClockWise" << endl;
		}
		else if (p == 5) {
			cout << "move Up ClockWise" << endl;
		}
		else if (p == 6) {
			cout << "move Up AntiClockWise" << endl;
		}
		else if (p == 7) {
			cout << "move Down ClockWise" << endl;
		}
		else if (p == 8) {
			cout << "move Down AntiClockWise" << endl;
		}
		else if (p == 9) {
			cout << "move Front ClockWise" << endl;
		}
		else if (p == 10) {
			cout << "move Front AntiClockWise" << endl;
		}
		else if (p == 11) {
			cout << "move Back ClockWise" << endl;
		}
		else if (p == 12) {
			cout << "move Back AntiClockWise" << endl;
		}
		s.pop();
	}
	cout << endl;
	

}

int magicFunction(int*** currentState, int*** finalState)
{
	int count = 0;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				if (currentState[i][j][k] == finalState[i][j][k])
					count++;
			}
		}
	}
	return count;
}

int main()
{
	int *** array;
	array = new int **[6];
	for (int i = 0; i < 6; i++)
	{
		array[i] = new int *[3];
		for (int j = 0; j < 3; j++)
		{
			array[i][j] = new int[3];
		}
	}

	State startState;
	State finalState;

	takeInput(startState, finalState);

	stack<Node *> mystack;
	Node * curr = new Node();
	curr->setCurrState(finalState);
	curr->state = leftAntiClock(curr->state);
	curr->state = rightAntiClock(curr->state);
	curr->state = upClock(curr->state);
	bool found = false;

	int depth = 30;

	mystack.push(curr);

	while (!mystack.empty())
	{
		if (compareState(curr->state, finalState))
		{
			found = true;
			break;
		}

		if (curr->depthLevel < depth)
		{
			addChilds(curr, mystack);
			curr = mystack.top();
			mystack.pop();
		}
		else
		{
			curr = mystack.top();
			mystack.pop();
		}
	}

	if (found)
	{
		cout << "Found!" << endl;
		stack<int> path;
		while (curr->parent != nullptr)
		{
			path.push(curr->prevMove);
			curr = curr->parent;
		}

		//printStack(path);
		cout << "The depth is: " << depth << endl;
		printStackWithMoves(path);
		//print(curr->curr);
	}
	else {
		cout << "Not Found" << endl;
	}

	return 0;
}
