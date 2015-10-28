#ifndef DECODE_H
#define DECODE_H
#include <tuple>

class Decode{
public:
	Decode() {
		cout << "Decode unit created" << endl;
		H_instr		= NULL;
		L_instrNum	= NULL;
		L_reg1		= NULL;
		L_reg2		= NULL;
		L_reg3		= NULL;
		L_imm		= NULL;
	}
	void onHigh(Fetch *f) {
		//get instr from fetch
		//H_instr = Fetch::getInstr();		
		H_instr = f->getInstr();
	}
	void onLow() {
		//decode the instruction
		L_instrNum = (H_instr & 0xF000) >> 12;
		L_reg1     = (H_instr & 0xF00 ) >>  8;
		L_reg2     = (H_instr & 0xF0  ) >>  4;
		L_reg3     = (H_instr & 0xF   );
		L_imm      = (H_instr & 0xFF  );
	}
	tuple<int, int, int, int, int> getValues() {
		return make_tuple(L_instrNum, L_reg1, L_reg2, L_reg3, L_imm);
	}

	
	~Decode() {}
protected:
private:
	int H_instr;
	int L_instrNum;
	int L_reg1;
	int L_reg2;
	int L_reg3;
	int L_imm;
};

#endif
