/*
--------------------------------------------------
Project: cp264oc-a1q2
File:    overflow.c
Author:  Abdinasir Ali
Version: 2023-05-20
--------------------------------------------------
*/

#include <stdio.h>

int main(int argc, char *args[]){
    int i, n = 0, sum = 0, b=1, p=1, is_overflow = 0;
    if (argc > 2) {
        sscanf(args[1],"%d",&b);
        sscanf(args[2],"%d",&n);

        if (b >=1 && n >= 0) {
        	for (int i = 0; i < n; i++) {
        		if (p * b < p || sum + p * b < sum) {
        			is_overflow = 1;
        			break;
        		}
        		p *= b;
        		sum += p;
        	}
        	sum++;
        	if (is_overflow) {
        		printf("powersum(%d %d):overflow\n", b, n);
        	} else {
        		printf("powersum(%d %d):%d", b, n, sum);
        	}
        }
        else {
           printf("invalid argument\n");
        }
    }
    else {
        printf("arguments:b>0 n>0\n");
    }

   return 0;
}
