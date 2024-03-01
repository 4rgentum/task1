#include <stdio.h>

int degree(int number, int digit);
int digit(int number);
/*void armstrong(int i);*/
void armstrong(int* begin, int* end);

int main() {
	int begin = 0, end = 0, arms_num = 0, flag = 1;
	while(flag == 1) {
		printf("Do you want to find Armstrong's numbers");
		printf("\n" "Print 1 if Yes, 0 if No" "\n");
		scanf("%d", &flag);
		if(flag == 1) {
			printf("\n" "Begin=");
			scanf("%d", &begin);
			printf("\n" "End=");
			scanf("%d", &end);
			/*for(int i = begin; i <= end; i++) {
				armstrong(i);
			}*/
			armstrong(&begin, &end);
		} else {
			break;
		}
	}
	return 0;
}

int digit(int number) {
	int digit = 0;
	while(number > 0) {
		digit += 1;
		number = number / 10;
	}
	return(digit);
}

int degree(int number, int digit) {
	int num = 1;
	for(int j = 1; j <= digit; j++) {
		num *= number;
	}
	return(num);
}

/*void armstrong(int i) {
	int dig = 0, number = 0, deg_num = 0, arms_num = 0, num = i;
	dig = digit(i);
	for(int k = 0; k < dig; k++) {
		number = i % 10;
		deg_num = degree(number, dig);
		arms_num += deg_num;
		i = i / 10;
	}
	if(arms_num == num) {
		printf("%d\n", arms_num);
	}
}*/

void armstrong(int* begin, int* end) {
	int dig = 0, number = 0;
	do {
		dig = digit(*begin);
		int deg_num = 0, arms_num = 0, num = *begin;
		for(int k = 0; k < dig; k++) {
			number = num % 10;
			deg_num = degree(number, dig);
			arms_num += deg_num;
			num = num / 10;
		}
		if(arms_num == *begin) {
			printf("%d\n", arms_num);
		}
		(*begin)++;
	} while((*end) - (*begin) >= 0);
}
