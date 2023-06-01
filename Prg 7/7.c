#include <stdio.h>
#include <stdlib.h>

void ssr() {
  int i, j, bt[10], n, pt[10], wt[10], tt[10], t, k;
  float at, aw, w1 = 0.0, t1 = 0.0;
  printf("enter no of jobs :\n");
  scanf("%d", & n);
  printf("enter burst time :\n");
  for (i = 0; i < n; i++)
    scanf("%d", & bt[i]);
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      if (bt[i] < bt[j]) {
        t = bt[i];
        bt[i] = bt[j];
        bt[j] = t;
      }

  wt[0] = 0;
  for (i = 0; i < n; i++) {
    wt[i + 1] = bt[i] + wt[i];
    tt[i] = wt[i] + bt[i];
    w1 = w1 + wt[i];
    t1 = t1 + tt[i];
  }
  aw = w1 / n;
  at = t1 / n;
  printf("\n bt\t wt\t tt\n");
  for (i = 0; i < n; i++)
    printf("\n %d\t %d\t %d\n", bt[i], wt[i], tt[i]);
  printf("aw=%f\nat=%f\n", aw, at);
}


void rr() {
  int s[10], st[10], p[10], n, i, j, w[10], t[10], tq, tst = 0, w1 = 0;
  float tt = 0.0, tw = 0.0, aw, at;
  printf("enter the no of process :\n");
  scanf("%d", & n);
  printf("enter the time quantum :\n");
  scanf("%d", & tq);
  printf("enter the  process and burst time \n");
  for (i = 0; i < n; i++)
    scanf("%d %d", & p[i], & s[i]);
  for (i = 0; i < n; i++) {
    st[i] = s[i];
    tst = tst + s[i];
  }
  for (j = 0; j < tst; j++)
    for (i = 0; i < n; i++)
      if (s[i] > tq) {
        s[i] = s[i] - tq;
        w1 = w1 + tq;
        t[i] = w1;
        w[i] = t[i] - st[i];
      }
  else if (s[i] != 0) {
    w1 = w1 + tq;
    t[i] = w1;
    w[i] = t[i] - st[i];
    s[i] = s[i] - tq;
  }
  for (i = 0; i < n; i++) {
    tw = tw + w[i];
    tt = tt + t[i];
  }
  aw = tw / n;
  at = tt / n;
  printf("\nprocess\t bt\t wt\t tt\n");
  for (i = 0; i < n; i++)
    printf("\n %d\t %d\t %d\t %d\n", p[i], st[i], w[i], t[i]);
  printf("\naw=%f\nat=%f\n", aw, at);
}

int main() {
  int choice;
  printf("enter the choice :");
  scanf("%d", & choice);
  switch (choice) {
  case 1:
    ssr();
    break;
  case 2:
    rr();
    break;
  case 3:
    exit(0);
    return 0;
  }
}
