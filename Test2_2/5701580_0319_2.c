#include <stdio.h>
#include <time.h>
//13의 21거듭제곱을 구하는 반복함수 재귀함수
double power_iter(double x, int n) {
	int i;
	double result = 1.0;

	for (i = 0; i < n; i++)
		result = result * x;
	return(result);
}

double power_rec(double x, int n) {
	if (n == 0) return 1;
	else if (n % 2 == 0) //n이 짝수일 때
		return power_rec(x * x, n / 2);
	else //n이 홀수일 때
		return x * power_rec(x * x, (n - 1) / 2);
}

int main() {
	clock_t start1, stop1, start2, stop2;
	double duration_iter, duration_rec;
	start1 = clock(); //반복함수 측정 시작

	double result_iter = power_iter(13.0, 21);

	stop1 = clock(); //반복함수 측정 종료

	start2 = clock(); //재귀함수 측정 시작

	double result_rec = power_rec(13.0, 21);

	stop2 = clock(); //재귀함수 측정 종료

	duration_iter = (double)(stop1 - start1) / CLOCKS_PER_SEC; //반복함수 실행 시간
	duration_rec = (double)(stop2 - start2) / CLOCKS_PER_SEC; //재귀함수 실행 시간

	printf("13의 21거듭제곱 반복함수값 = %f, 재귀함수값 = %f\n", result_iter, result_rec);
	printf("반복함수 실행시간 = %f, 재귀함수 실행시간 = %f\n", duration_iter, duration_rec);
	
	return 0;
}