/*
 * pre:  a contains numbers between 1..20
 * post: count[i] is equal to the numers af i+1 in a
 */
void count_1_to_20(int a[100][150], int count[20])
{
    for (int i = 0; i < 20; i++)
    {
        count[i]=0;
        for (int j = 0; j < 100; j++)
        {
            for (int k = 0; k < 150; k++)
            {
                if (a[j][k]==i+1)
                {
                    count[i]++;
                }
                
            }
            
        }
        
    }
    return;
}