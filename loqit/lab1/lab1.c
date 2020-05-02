//
//  main.c
//  1
//
//  Created by Андрей Бобр on 14.02.1976.
//  Copyright © 2019 Андрей Бобр. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, const char * argv[]) {
   
    int m, c = 1;
    scanf("%d",&m);
    
    char str[30];
    while(number > m)
    {
        if(c%2)
        {
            str[30] = strcat(str,"111");
           
        }else
        {
            str[30] = strcat(str,"000");
        }
        
        c++;
        int number = 0,k = 1;
        
        for(int i = 30;i >= 0;i--)
        {
            if(str[i] == '1' || str[i] == '0')
            {
                number += k * (str[i] - 48);
                k *= 2;
            }
        }
        
     printf("%s %d\n",str,number);
    }
    return 0;
}

