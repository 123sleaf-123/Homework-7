#include <stdio.h>
#include <math.h>
#define peonum 80

double Average (double arr[],int i);// ��ƽ��ֵ��Ҫ�õ�ԭ���� arr[]������������ʵ�ʸ��� i
double Stdev (double arr[] , int i , double avg); // ���׼����Ҫ�õ�ԭ���� arr[]������������ʵ�ʸ��� i����һ�������������ƽ��ֵ avg 

int main (void){
	int i;
	double arr[peonum],average,standard_deviation;
	
	/* �����������ݣ����������80�����ݣ���ÿ������ֻ����0~100֮�䣬��������Ϊ������� */
	 
	for(i = 0 ; i < peonum ; i++){
		scanf("%lf",&arr[i]);// �����趨����arr[]Ϊdouble���ͣ�����Ҫ����%lf������ 
		if(arr[i] > 100 || arr[i] < 0){
			break;
		}
	}
	
	/* ר�����ڱ���������ݵĲ��� */ 
	
	average =  Average(arr,i);
	standard_deviation = Stdev (arr , i , average);
	
	/* ���Ľ��������� */
	 
	printf("The average grade is %.2f.",average);
	putchar('\n'); //һ�����з�'\n'����Ҳ�Ǹ�ת���ַ� 
	printf("The standard deviation of grade is %.2f.", standard_deviation);
	return 0;
}

double Average (double arr[],int i){
	int j;
	double sum = 0;
	
	/* �����������ݽ�����Ͳ��� */
	 
	for(j = 0 ; j < i ; j++){
		sum += arr[j];
	}
	
	/* ���غ�������Ĳ��ƽ��ֵ */
	 
	return (sum / i);
}

double Stdev (double arr[] , int i , double avg){
	int j;
	double dif = 0 , sum = 0;
	
	/*
	Ϊ�˼��ټ��������ȶ�������ƽ��ֵ����õ�double���͵� dif 
	��double���͵� sum�Բ��ƽ�������۴����
	ֱ��ʵ�����ݵ����һ��ֵ�˳�ѭ�� 
	*/ 
	
	for(j = 0 ; j < i ; j++){
		dif = arr[j] - avg;
		sum += dif * dif;
	}
	
	/* �����г����󿪷��������׼�� */
	 
	return sqrt(sum/i);
} 
