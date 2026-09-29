#include <assert.h>

/*
 * Returns the index in list of the logest sequence of zeros in list, -1 if no zeros in list
 * pre: n>0, list[0...n-1] is defined
 */
int longest_seq(int list[], int n)
{
    assert(n > 0);
    int max_seq = 0;
    int location = -1;
    
    for (int i = 0; i < n; i++)
    {
        int current_seq = 0;
        if (list[i] == 0)
        {
            for (int j = i; j < n; j++)
            {
                current_seq++;
                if (list[i] != 0)
                {
                    break;
                }
                
            }
            
        }
        
        if (current_seq > max_seq)
        {
            max_seq = current_seq;
            location = i;
        }
        
    }
    
    return location;
}