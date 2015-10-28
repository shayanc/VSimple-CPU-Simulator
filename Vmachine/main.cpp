/*	16-bit VIRTUAL MACHINE */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bitset>
#include "Head.h"

/*EXECUTION UNITS*/
#include "Fetch.h"
#include "Decode.h"
#include "Execute.h"


Fetch *fetch;
Decode *decode;
Execute *execute;


void run() {
	while (running) {
		if (clock==HIGH) {
			print_cycles();
			fetch->onHigh();
			decode->onHigh(fetch);
			execute->onHigh(decode);

			clock = LOW;
		}  else {
			
			fetch->onLow();
			decode->onLow();
			execute->onLow();
			//one whole clock cycle completed
			cycles++;
			clock = HIGH;
		}
	}
	showRegs();
}

int main() {
	
	fetch	= new Fetch();
	decode	= new Decode();
	execute = new Execute();

	cout << "=========START OF PROGRAM===========" << endl;
	run();
	cout << "=========END OF PROGRAM=============" << endl;
	return 0;
}