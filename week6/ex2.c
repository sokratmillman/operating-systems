#include <stdio.h>

int main(void) {
  int bt[10]={0}, at[10]={0}, tat[10]={0},wt[10]={0}, ct[10]={0};
  int i, j, temp;
  int n, time=0;

  float totalTAT=0, totalWT=0;
  printf("Enter the number of processes(n<10): ");
  scanf("%d", &n);
  for (i = 0; i<n; i++){
    printf("Arrival time of process[%d] ", i+1);
    scanf("%d", &at[i]);
    printf("Burst time of process[%d] ", i+1);
    scanf("%d", &bt[i]);
  }
  for (i = 0; i<n; i++){//sorting by burst time
    for (j = i+1; j<n;j++){
      if (bt[i]>bt[j]){
        temp = at[i];
        at[i]=at[j];
        at[j]=temp;
        temp=bt[i];
        bt[i]=bt[j];
        bt[j]=temp;
      }
    }
  }
    for (i = 0; i<n; i++){//sorting by arrival time
    for (j = i+1; j<n;j++){
      if (at[i]>at[j]){
        temp = at[i];
        at[i]=at[j];
        at[j]=temp;
        temp=bt[i];
        bt[i]=bt[j];
        bt[j]=temp;
      }
    }
  }
  
  //the same as for FCFS as the jobs are arranged correctly
  
  
  for (i=0;i<n;i++){//ct is a moment in absolute when job is done
    if (at[i]>time) time = at[i];
    time+=bt[i];
    ct[i]+=time;
  }
  for (j=0; j<n; j++){
    tat[j]=ct[j]-at[j];
    totalTAT+=tat[j];
  }
  //waitng time = TAT - burst time
  for (i=0; i<n; i++){
    wt[i]=tat[i]-bt[i];
    totalWT+=wt[i];
  }

  double TTAT = totalTAT/n;
  double TWT = totalWT/n;

  printf("PID\t AT\t BT\t CT\t Tat\t WT\t \n \n \n");
  for (i=0; i<n; i++){
    printf("P%d\t %d\t %d\t %d\t %d\t %d\t \n", i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
  }
  printf("Average TAT: %f\n", TTAT);
  printf("Average WT: %f\n", TWT);
  return 0;
}
