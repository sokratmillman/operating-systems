#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(void){
  int i, j, cpn, min_ref, indic;
  int hit = 0, miss = 0; //counters of hits and misses
  FILE *filename;
  filename = fopen("input.txt", "r");

  int numofpages = 10;
  //it can be 10, 50, 100;
  //result for 10 = 10/990=0.010101
  //result for 50 = 51/949 = 0.053741
  //result for 100 = 93/907 = 0.102536

  int power = pow(2, 7);
  int pages[numofpages], refpage[numofpages];
  for (i = 0; i<numofpages;i++){
    pages[i] = -1; //page frames
    refpage[i]=0;//references of pages
  }

  while (!feof(filename)){
    fscanf(filename, "%d", &cpn);
  

  j=-1;
  for(i=0;i<numofpages;i++){
    if (cpn==pages[i]){//It means that hit happened
      hit++;
      j=i;
      break;
    }
  }

  if (j!=-1){//if hit happened, do right shift
    for (i=0; i<numofpages;i++){
      refpage[i]=refpage[i]/2;
    }
    refpage[j]+=power;
  }

  else{//pagefault
    miss++;
    min_ref=refpage[0];
    j=0;
    indic=1;
    for (i=0;i<numofpages;i++){
      if(pages[i]==-1&&indic){
        j=i;
        min_ref=0;
        indic=0;
      }
      if(refpage[i]<min_ref){
        min_ref=refpage[i];
        j=i;
      }
      refpage[i]=refpage[i]/2; //equal to right shift

    }

    pages[j]=cpn;
    refpage[j]=power;
  }
  }
  float ratio = (float)(hit)/(miss);
  printf("Hit/miss ratio = %d/%d = %f\n", hit, miss, ratio);
  return 0;

}
