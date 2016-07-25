int singleNumber(int A[], int n)  
{  
    int one = 0, two = 0;  
    for (int i = 0; i < n; i++)  
    {  
        two |= A[i] & one;//two 积累值  
        one ^= A[i];//one不断求反  
        int t = one & two;//第三次的时候one和two都保留了该位的值  
        one &= ~t;//清零出现三次的该位的值  
        two &= ~t;  
    }  
    return one;  
}  


int singleNumberII_36(int A[], int n)  
{  
    int ans = 0;  
    for (int i = 0; i < 32; i++)   
    {  
        int c = 0, d = 1<<i;  
        for (int j = 0; j < n; j++)  
            if (A[j] & d) c++;  
  
        if (c%3) ans |= d;  
    }  
    return ans;  
}  

