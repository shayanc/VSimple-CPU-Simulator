#define NUM_REGS 4
#define MEMORY_SIZE 1024

using namespace std;

int regs [NUM_REGS];
int mem	[MEMORY_SIZE];

enum ISET {
	HALT=15, LOADI=1, ADDR=2, ADDI=3, CMP=4, 
	LD=5, LDC=6, B=7, J=8, BLTH=9
};

enum CLOCK { HIGH, LOW };

CLOCK clock = HIGH;
int cycles = 0;

int prog[] = { 0x1064, 0x11C8, 0x2201, 0xF000 };
int pc = 0; 		/*program counter - used in fetch*/
int running = 1; 	/*the VM runs until this flag becomes 0 */


/*DEBUG VARIABLES*/
int SHOW_REGISTERS = 1;


/*Display content of all registers*/
void showRegs()
{
	if (SHOW_REGISTERS == 1) {
		int i;
		printf( "regs = " );
		for( i=0; i<NUM_REGS; i++ )
			printf( "%04X ", regs[ i ] );
		printf( "\n");
	}
}


void print_cycles() {printf("Cycle: %d\t", cycles);}

