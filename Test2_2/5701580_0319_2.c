#include <stdio.h>
#include <time.h>
//13�� 21�ŵ������� ���ϴ� �ݺ��Լ� ����Լ�
double power_iter(double x, int n) {
	int i;
	double result = 1.0;

	for (i = 0; i < n; i++)
		result = result * x;
	return(result);
}

double power_rec(double x, int n) {
	if (n == 0) return 1;
	else if (n % 2 == 0) //n�� ¦���� ��
		return power_rec(x * x, n / 2);
	else //n�� Ȧ���� ��
		return x * power_rec(x * x, (n - 1) / 2);
}

int main() {
	clock_t start1, stop1, start2, stop2;
	double duration_iter, duration_rec;
	start1 = clock(); //�ݺ��Լ� ���� ����

	double result_iter = power_iter(13.0, 21);

	stop1 = clock(); //�ݺ��Լ� ���� ����

	start2 = clock(); //����Լ� ���� ����

	double result_rec = power_rec(13.0, 21);

	stop2 = clock(); //����Լ� ���� ����

	duration_iter = (double)(stop1 - start1) / CLOCKS_PER_SEC; //�ݺ��Լ� ���� �ð�
	duration_rec = (double)(stop2 - start2) / CLOCKS_PER_SEC; //����Լ� ���� �ð�

	printf("13�� 21�ŵ����� �ݺ��Լ��� = %f, ����Լ��� = %f\n", result_iter, result_rec);
	printf("�ݺ��Լ� ����ð� = %f, ����Լ� ����ð� = %f\n", duration_iter, duration_rec);
	
	return 0;
}