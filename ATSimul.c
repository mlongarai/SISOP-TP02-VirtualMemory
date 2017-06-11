#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

unsigned int TLB[16][2]; /* TLB with 16 entries. */
unsigned int PageTable[256]; /* Page Table with 256 entries */

int frame;
int listTLB = 0;

void page_table_init(unsigned int *pt){
    int i;
    for(i=0; i<256; i++){
        pt[i] = rand()%256;
    }
}

unsigned int next_address(){
    return rand()%65536;
}

int searchTLB(int page)
{
    int i;
    int match = -1;    
    for(i = 0; i < 16; i++) {
       
        if(TLB[i][0] == page){
           frame = TLB[i][1];
           match = 1;
           break;
         }    
       }
return match;
}

void preencheTLB(int frame, int page) 
{
   
        TLB[listTLB][0] = page;
        TLB[listTLB][1] = frame;
        listTLB = (listTLB + 1) % 16;
}


int searchPageTable(int page)
{
    frame = PageTable[page];
    preencheTLB(frame,page);
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

    //srand(time()); /* Initialize the random numbers generator. */
    memset(TLB, 0, sizeof(TLB)); /* Reset TLB */
    page_table_init(PageTable); /* Initial random page table. */
    int page, offset, answerTLB, RealAddress,answerPageTable, TLBFault;    
    
    for(i=0;i<numberAddr;i++){ 
        
        address = next_address();

        page = address >> 8;
        
        offset = address & 0XFF;

        answerTLB = searchTLB(page); 
                
        if(answerTLB == 0){ 
            
            RealAddress = frame << 8 || offset;
        
        } /* match TLB anwser */
        else{ /* TLB no anwser */
        
        TLBFault++;
        
        }
        searchPageTable(page);        
        RealAddress = RealAddress = frame << 8 || offset;              
        printf("Virtual Address [%d]\t - TLB %d\n",address ,TLBFault);
        }

    return 0;

}