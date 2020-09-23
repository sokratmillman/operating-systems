#include <stdio.h>

int main(void) {
  int n, i, j, k;
  int totalTAT=0, totalWT=0;
  int time = 0;
  int arrtime[10], burtime[10], turartime[10], wtime[10], ct[10];

  printf("Enter the number of processes(n<10): ");
  scanf("%d", &n);
  for (i = 0; i<n; i++){
    printf("Arrival time of process[%d] ", i+1);
    scanf("%d", &arrtime[i]);
    printf("Burst time of process[%d] ", i+1);
    scanf("%d", &burtime[i]);
  }

  for (i=0;i<n;i++){
    if (arrtime[i]>time)
      {time=arrtime[i];
      time+=burtime[i];
      ct[i]=time;}//if the process is not ready yet
    else{
      time+=burtime[i];
      ct[i]=time;
    }//moment in time at which process is done
  }
  //turn around time is a difference between completion and arrival time
  for (j=0; j<n; j++){
    turartime[j]=ct[j]-arrtime[j];
    totalTAT+=turartime[j];
  }
  //waitng time = TAT - burst time
  for (k=0; k<n; k++){
    wtime[k]=turartime[k]-burtime[k];
    totalWT+=wtime[k];
  }
  double TTAT = totalTAT/n;
  double TWT = totalWT/n;

  printf("PID\t AT\t BT\t CT\t Tat\t WT\t \n \n \n");
  for (i=0; i<n; i++){
    printf("P%d\t %d\t %d\t %d\t %d\t %d\t \n", i+1, arrtime[i], burtime[i], ct[i], turartime[i], wtime[i]);
  }
  printf("Average TAT: %f\n", TTAT);
  printf("Average WT: %f\n", TWT);
  return 0;
}
