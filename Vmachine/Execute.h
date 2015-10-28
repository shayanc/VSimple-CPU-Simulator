#ifndef EXECUTE_H
#define EXECUTE_H

class Execute {
public:
	Execute() {
		instrNum	= NULL;
		reg1		= NULL;
		reg2		= NULL;
		reg3		= NULL;
		imm			= NULL;
		cout << "Execute unit created" << endl;
	};
	~Execute() {};
	void onHigh(Decode *decode) {
		tie(instrNum, reg1, reg2, reg3, imm) = decode->getValues();
//		printf(" %d %d %d %d\n", instrNum, reg1, reg2, reg3);
		execute();
		
	};
	void onLow() {};

protected:
private:
	int instrNum;
	int reg1;
	int reg2;
	int reg3;
	int imm;

	/*Evaluate the last decoded instruction*/
	void execute() {
		switch( instrNum ) {
			case 0:
				break;
		
			case HALT:
			  /* halt */
			  printf( "HALT\n" );
			  running = 0;
			  break;
			case LOADI:
			  /* loadi */
			  printf( "LOADI r%d #%d\n", reg1, imm );
			  regs[ reg1 ] = imm;
			  break;
			case ADDR:
			  /* add */
			  printf( "ADDR r%d r%d r%d\n", reg1, reg2, reg3 );
			  regs[ reg1 ] = regs[ reg2 ] + regs[ reg3 ];
			  break;
		}
	}	
};

#endif
