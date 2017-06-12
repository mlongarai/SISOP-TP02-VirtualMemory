#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

/* TLB with 16 entries. */
int TLB[16][2];

/* Page Table with 256 entries */
unsigned int PageTable[256];

/* Used for TLB entries */
unsigned int page,
			 tlbIndex,
			 frame = 0;


/**
 * @brief Initialize the page table with random frame numbers.
 *
 * @param pt Page table pointer.
 */
void page_table_init(unsigned int *pt){
	int i;
	for(i=0; i<256; i++){
		pt[i] = rand()%256; //8 bits
	}
}

/**
 * @brief Initialize the TLB.
 *
 * @param t TLB pointer.
 */
void tlb_init(int t[16][2]){
	int i;
	for(i=0; i<16; i++){
		t[i][0] = -1;
        t[i][1] = -1;
	}
}


/**
 * @brief Generates a random virtual address.
 *
 * @return VA.
 */
unsigned int next_address(){
	return rand()%65536; //16 bits
}
/**
 * @brief Feed TLB with frame and page.
 *
 * @param frame, page.
 */
void feedTlb(int frame, int page){

	TLB[tlbIndex][0] = page;
	TLB[tlbIndex][1] = frame;
	tlbIndex = (tlbIndex + 1) % 16;
}


/**
 * @brief Search the page on TLB
 *
 * @return Return hit case page is in TLB
 */

int TLBsearch(int page)
{
    int hit = 0;
    for(int i = 0; i < 16; i++) {

        if(TLB[i][0] == page){
           frame = TLB[i][1];
           hit = 1;
           break;
         }
       }
return hit;
}

int main(int argc, char **argv){
	int i, offset, phisicalAddress, tlbmiss=0, tlbhit = 0;
	unsigned int address;
	int numberAddr = 0;

	if(argc < 2){
		printf("Usage: ./%s <number of addresses>\n", argv[0]);
		return 0;
	}

	numberAddr = atoi(argv[1]);

	/* Initialize the random numbers generator. */
	srand(time(NULL));

	/* Reset TLB */
	tlb_init(TLB);
	int RealAddress, frame;
	/* Initial random page table. */
	page_table_init(PageTable);

	for(i=0;i<numberAddr;i++){

		address = next_address();
		page = address >> 8; // pega os 8 bits mais significativos do endereço.
		offset = address & 0xFF; // Pega os 8 bits menos significativos do endereço.

        if (TLBsearch(page) == 1)
		{
           phisicalAddress = (frame << 8) | offset;
           tlbhit++;
           
		}
		else
		{
        	tlbmiss++;
            feedTlb(PageTable[frame],page);
            phisicalAddress = (frame << 8) | offset;

		}
        printf("Virtual Address [%d] - Phisical Address [%d] - TLBHit [%d] -TLBMiss [%d]\n",address,phisicalAddress ,tlbhit,tlbmiss);
        
	}

	return 0;
}
