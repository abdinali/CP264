/*
--------------------------------------------------
Project: cp264oc-a1q3
File:    quadratic.c
Author:  Abdinasir Ali
Version: 2023-05-20
--------------------------------------------------
*/

#include <stdio.h>
#include <math.h>

#define EPSILON 1e-6

int main(int argc, char* argv[])
{
  float a, b, c, d, x1, x2;

  if (argc < 2) {
     printf("argument input:missing\n");
  } else {
    int n = sscanf(argv[1], "%f,%f,%f", &a, &b, &c);
    if (n != 3) {
      printf("input:invalid\n");
    } else {
       printf("(%.2f)x^2+(%.2f)x+(%.2f)=0: ", a, b, c);
      if (fabs(a) < EPSILON) {
        printf("not a quadratic equation\n");
      } else {
    	d = (b*b) - 4*a*c;
        if (d == 0) {
        	// 2. b2 - 4ac = 0
        	x1 = -b / (2 * a);
        	x2 = x1;
        	printf("%.2f %.2f\n", x1, x2);
        } else if (d < 0) {
        	// 3. b2 - 4ac < 0
        	float real = -b / (2 * a);
        	float complex = sqrt(-d) / (2 * a);
        	printf("%.2f+%.2fi, %.2f-%.2fi\n", real, complex, real, complex);
        } else if (d > 0) {
        	// 4. b2 - 4ac > 0
        	x1 = (-b + sqrt(d)) / (2 * a);
        	x2 = (-b - sqrt(d)) / (2 * a);
        	printf("%.2f, %.2f\n", x1, x2);
        }

      }
    }
  }
  return 0;
}
