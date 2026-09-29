#include <stdio.h>
#include <stdbool.h>

bool is_jolly_jumper(const int seq[], int size);
void test_jolly(int seq[], int size);

int main(void){

    int a[4] = {1, 4, 2, 3};
    test_jolly (a, 4);

    int b[5] = {1, 4, 2, -1, -6};
    test_jolly (b, 5);

    int seq[15] = {1, 2, 4, 7, 11, 16, 22, 29, 37, 46, 56, 67, 79, 92, 106};
    test_jolly (seq, 15);
}

void test_jolly (int seq[], int size){
    
    bool check = is_jolly_jumper(seq, size);
    printf("%d\n",size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ",seq[i]);
    }
    printf("\n");
    if (check == true)
    {
        printf("Jolly\n");
        return;
    }

    printf("Not Jolly\n");
    
    return;    
}


bool is_jolly_jumper(const int seq[],int size) {
    int temp;
    bool diffs_found[50] = {false};
    bool all_true = true;
   
    
    for (int i = 1; i < size; i++)
    {
        temp = seq[i] - seq[i-1];
        if (temp < 0)
        {
            temp = -temp;
        }
        if (diffs_found[temp-1] == false)
        {
            diffs_found[temp-1] = true;
        }
        
    }
    
    for (int i = 0; i < size-1; i++) {
        if (!diffs_found[i]) {      // if any element is false
            all_true = false;
            break;          // no need to check further
        }
    }
    
    if (all_true == true)
    {
        return true;
    }
    
    
    return false;
}