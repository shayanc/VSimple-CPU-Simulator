#ifndef FETCH_H
#define FETCH_H

class Fetch{
public:
	Fetch() {H_instr = NULL; L_instr = NULL; cout<< "Fetch unit created" <<endl;}
	
	//Perform high/low stages
	void onHigh() {H_instr = prog[pc++];}
	void onLow() {L_instr = H_instr;}
	/*Return instruction for decode to use*/
	int getInstr() {return L_instr; }
	
	~Fetch() {}
protected:
private:
	int H_instr;
	int L_instr;
};

#endif