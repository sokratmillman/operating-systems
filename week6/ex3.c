#include <stdio.h>
/*
For the same input it occurs that the completion time is the same, but for other algorithms totalTAT and totalWT is different
For other quantum time result and input may be different, so there will be some changes and the throughput will be more effective 
For used input the most effective (in terms of average WT and TAT)  algorithm is FCFS, less effective is SJF, the least effective is Round Robin, but total completion time doesn't differ
*/
int main(void) {
  int bt[10]={0}, at[10]={0}, tat[10]={0},wt[10]={0}, ct[10]={0}, lefttime[10]={0};
  int i, j, temp;
  int n, time=0;
  int TQ = 3;
  float totalTAT=0, totalWT=0;
  printf("Enter the number of processes(n<10): ");
  scanf("%d", &n);
  for (i = 0; i<n; i++){
    printf("Arrival time of process[%d] ", i+1);
    scanf("%d", &at[i]);
    printf("Burst time of process[%d] ", i+1);
    scanf("%d", &bt[i]);
  }

  for (i=0; i<n; i++){
    lefttime[i]=bt[i];
  }
  
  while(1){
    int num = 0;//check if there are incomplete jobs
    for(i=0; i<n; i++){
      if(lefttime[i]>0)
        num++;
    }
    if (num==0)
      break;
    //if there are jobs to complete 
    for(i=0; i<n;i++){
      if (lefttime[i]>0){//if not completable for one iteration
        if (lefttime[i]>TQ){
          time+=TQ; //time counter
          lefttime[i]-=TQ; //reduce by quantum time
          ct[i]=time; 
        }
        else{//if can be done in one iteration
          time+=lefttime[i];
          lefttime[i]=0;
          ct[i]=time;
        }
      }
    }
  }
  //like in the other algorithms turnarounstimes, waiting times
  //
  for (i=0; i<n; i++){
    tat[i]=ct[i]-at[i];
    totalTAT+=tat[i];
  }
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
