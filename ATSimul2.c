#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* TLB with 16 entries. */
int TLB[16][2];

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

unsigned int buscaTLB(int pagina){
    
    for(int i =0; i <= 256; i++)
    {
      if(TLB[i][0] == pagina)
        return 1;    
    }    
    return 1;
}

unsigned int buscaPageTable(int pagina){
    
    for(int i =0; i <= 16; i++)
    {
      if(PageTable[i] == pagina)
        return 1;    
    }    
    return 1;
}

void adicionaTLB(pagina,frame){

    
}


int main(int argc, char **argv){
	int i, pagina, offset, answerTLB, enderecoReal,answerPageTable, TLBFault,frame,PageTableFault;
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
	memset(TLB, -1, sizeof(TLB));
	
	/* Initial random page table. */
	page_table_init(PageTable);
	
    for(i=0;i<numberAddr;i++){
        address = next_address();
        
        pagina = address >> 8;
        offset = address & 0XFF;

        answerTLB = buscaTLB(pagina); // procuro no tlb
                
        if(answerTLB){ // se achei no tlb
        
            enderecoReal = frame << 8 || offset;
                
            
        }
        else{ // se não achei no tlb
        TLBFault++; // TLB erro
    
        answerPageTable = buscaPageTable(pagina);        

            if(answerPageTable){
                    enderecoReal = enderecoReal = frame << 8 || offset;
                    adicionaTLB(pagina,frame); // coloco no TLB
            
                } else{
                    PageTableFault++;
                    
                    }

        }


    }
    
	
	return 0;
}
