#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* TLB with 16 entries. */
unsigned int TLB[16][2];

/* Page Table with 256 entries */
unsigned int PageTable[256];


/**
 * @brief Initialize the page table with random frame numbers.
 * 
 * @param pt Page table pointer.
 */
void page_table_init(unsigned int *pt){
	int i;
	for(i=0; i<256; i++){
		pt[i] = rand()%256;
	}
}

/**
 * @brief Generates a random virtual address.
 * 
 * @return VA.
 */
unsigned int next_address(){
	return rand()%65536;
}


int main(int argc, char **argv){
	int i;
	unsigned int address;
	int numberAddr = 0;
	
	if(argc < 2){
		printf("Usage: ./%s <number of addresses>\n", argv[0]);
		return 0;
	}
	
	numberAddr = atoi(argv[1]);

	/* Initialize the random numbers generator. */
	srand(time());
	
	/* Reset TLB */
	memset(TLB, 0, sizeof(TLB));
	
	/* Initial random page table. */
	page_table_init(PageTable);
	
	for(i=0;i<numberAddr;i++){
		address = next_address();
		
		/* WRITE YOUR TRANSLATION CODE HERE!! */
	}
	
	return 0;
}
