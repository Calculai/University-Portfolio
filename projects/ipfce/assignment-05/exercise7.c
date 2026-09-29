#include <stdbool.h>


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