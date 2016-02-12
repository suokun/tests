/*
 * test.c
 *
 *  Created on: Oct 2, 2015
 *     
 */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>


static unsigned char my_buf[20];

int main()
{
	srand((unsigned)time(0));

	unsigned char x;
	unsigned char data[10];
	int i, n;

	int copy_number = 0;


	for(n = 0; n < 10; n++) {

		//generate data array
		for(i = 0; i < 10; i++) {
			x = (unsigned char)(rand() % 256);
			data[i] = x;
		}

		//print data array
		printf("data: ");
		for(i = 0; i < 10; i++) {
			printf("%u, ", data[i]);
		}
		printf("\n");

		//把data数组从第4个数开始算，连续4个数copy到my_buf
		memcpy(my_buf + copy_number * sizeof(unsigned char), data + 3 * sizeof(unsigned char), 4 * sizeof(unsigned char));
		copy_number = copy_number + 4;


		if(copy_number >= 20) {
			//1: write to local disk
			printf("my_buf:");
			for(i = 0; i < 20; i++) {
				printf("%u, ", my_buf[i]);
			}
			//2: clean all data in buffer
			memset(my_buf, '\0', sizeof(my_buf) * sizeof(unsigned char));
			//3: copy number set to 0
			copy_number = 0;
			printf("\n\n\n");
		}
	}

	return 0;
}




