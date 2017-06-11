#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

unsigned int TLB[16][2]; /* TLB with 16 entries. */
unsigned int PageTable[256]; /* Page Table with 256 entries */

int frame;
int posCorrenteTLB = 0;

void page_table_init(unsigned int *pt){
    int i;
    for(i=0; i<256; i++){
        pt[i] = rand()%256;
    }
}

unsigned int next_address(){
    return rand()%65536;
}

int buscaTLB(int pagina)
{
    int i;
    int achei = -1;    
    for(i = 0; i < 16; i++) {
       
        if(TLB[i][0] == pagina){
           frame = TLB[i][1];
           achei = 1;
           break;
         }    
       }
return achei;
}

void preencheTLB(int frame, int pagina) 
{
   
        TLB[posCorrenteTLB][0] = pagina;
        TLB[posCorrenteTLB][1] = frame;
        posCorrenteTLB = (posCorrenteTLB + 1) % 16;
}


int buscaPageTable(int pagina)
{
    frame = PageTable[pagina];
    preencheTLB(frame,pagina);
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

    srand(time()); /* Initialize the random numbers generator. */
    memset(TLB, 0, sizeof(TLB)); /* Reset TLB */
    page_table_init(PageTable); /* Initial random page table. */
    int pagina, offset, answerTLB, enderecoReal,answerPageTable, TLBFault;    
    
    for(i=0;i<numberAddr;i++){ 
        
        address = next_address();

        pagina = address >> 8;
        
        offset = address & 0XFF;

        answerTLB = buscaTLB(pagina); 
                
        if(answerTLB == 0){ 
            
            enderecoReal = frame << 8 || offset;
        
        } /* match tlb anwser */
        else{ /* tlb no anwser */
        
        TLBFault++;
        
        }
        
        buscaPageTable(pagina);        

        enderecoReal = enderecoReal = frame << 8 || offset;
            
            printf("Endereço Virtual: %x\n", address);
            printf("\nEndereço Real: %x\n", enderecoReal);
            printf("TLB Fault:%d\n", TLBFault);                
        
        }

    return 0;

}