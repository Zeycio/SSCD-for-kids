#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void FIFO(char[], char[], int, int);
void lru(char[], char[], int, int);
int findLRU(int[], int);

int main() {
    int ch, YN = 1, i, l, f;
    char F[10], s[25];
    
    printf("\nEnter the number of empty Frames: ");
    scanf("%d", &f);
    
    for (i = 0; i < f; i++)
        F[i] = -1; // initializing frames

    do {
        printf("Enter the string: ");
        scanf("%s", s);
        l = strlen(s);
        
        printf("\n\n**** MENU *****\n\n");
        printf("\n1. FIFO\n2. LRU\n3. EXIT");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        
        switch (ch) {
            case 1:
                for (i = 0; i < f; i++) {
                    F[i] = -1;
                }
                FIFO(s, F, l, f);
                break;
            case 2:
                for (i = 0; i < f; i++) {
                    F[i] = -1;
                }
                lru(s, F, l, f);
                break;
            case 3:
                exit(0);
        }
        
        printf("\n\nTo continue, enter 1. To exit, enter 0: ");
        scanf("%d", &YN);
    } while (YN == 1);
    
    return 0;
}

void FIFO(char s[], char F[], int l, int f) {
    int i, j = 0, k, flag = 0, cnt = 0;
    
    printf("\n\n\tPAGE\tFRAMES\tFAULTS");
    
    for (i = 0; i < l; i++) {
        flag = 0;
        
        for (k = 0; k < f; k++) {
            if (F[k] == s[i])
                flag = 1;
        }
        
        if (flag == 0) {
            printf("\n\t %c\t", s[i]);
            F[j] = s[i];
            j = (j + 1) % f; // Circularly increment j
            
            for (k = 0; k < f; k++) {
                if (F[k] == -1)
                    printf(" ");
                else
                    printf("%c", F[k]);
            }
            
            printf("\tPage-Fault %d", cnt);
            cnt++;
        } else {
            printf("\n\t %c\t", s[i]);
            
            for (k = 0; k < f; k++) {
                if (F[k] == -1)
                    printf(" ");
                else
                    printf("%c", F[k]);
            }
            
            printf("\tNo page fault");
        }
    }
}

void lru(char s[], char F[], int l, int f) {
    int faults = 0, counter = 0, flag1 = 0, flag2 = 0, i, j, pos, lru[10];
    
    printf("\n\nPAGE\tFRAMES\tFAULTS");
    
    for (i = 0; i < l; i++) {
        flag1 = flag2 = 0;
        printf("\n%c\t", s[i]);
        
        for (j = 0; j < f; j++) {
            if (F[j] == s[i]) {
                counter++;
                lru[j] = counter;
                flag1 = flag2 = 1;
                break;
            }
        }
        
        if (flag1 == 0) {
            for (j = 0; j < f; j++) {
                if (F[j] == -1) {
                    counter++;
                    faults++;
                    F[j] = s[i];
                    lru[j] = counter;
                    flag2 = 1;
                    break;
                }
            }
        }
        
        if (flag2 == 0) {
            pos = findLRU(lru, f);
            counter++;
            faults++;
            F[pos] = s[i];
            lru[pos] = counter;
        }
        
        for (int k = 0; k < f; k++) {
            if (F[k] == -1)
                printf(" ");
            else
                printf("%c", F[k]);
        }
        
        if (flag1 == 0 || flag2 == 0)
            printf("\tPage-fault %d", faults);
        else
            printf("\tNo page fault");
    }
}

int findLRU(int lru[], int n) {
    int i, minimum = lru[0], pos = 0;
    
    for (i = 1; i < n; ++i) {
        if (lru[i] < minimum) {
            minimum = lru[i];
            pos = i;
        }
    }
    
    return pos;
}

