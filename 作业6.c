#include <stdio.h>
#include <math.h>
#define peonum 80

double Average (double arr[],int i);// 求平均值需要用到原数组 arr[]，数组内数据实际个数 i
double Stdev (double arr[] , int i , double avg); // 求标准差需要用到原数组 arr[]，数组内数据实际个数 i，上一个函数算出来的平均值 avg 

int main (void){
	int i;
	double arr[peonum],average,standard_deviation;
	
	/* 用于输入数据，最多能输入80个数据，且每个数据只能在0~100之间，超出则视为输入结束 */
	 
	for(i = 0 ; i < peonum ; i++){
		scanf("%lf",&arr[i]);// 这里设定数组arr[]为double类型，所以要输入%lf的数据 
		if(arr[i] > 100 || arr[i] < 0){
			break;
		}
	}
	
	/* 专门用于保存计算数据的部分 */ 
	
	average =  Average(arr,i);
	standard_deviation = Stdev (arr , i , average);
	
	/* 最后的结果输出部分 */
	 
	printf("The average grade is %.2f.",average);
	putchar('\n'); //一个换行符'\n'，它也是个转义字符 
	printf("The standard deviation of grade is %.2f.", standard_deviation);
	return 0;
}

double Average (double arr[],int i){
	int j;
	double sum = 0;
	
	/* 对数组内数据进行求和操作 */
	 
	for(j = 0 ; j < i ; j++){
		sum += arr[j];
	}
	
	/* 返回和与个数的差，即平均值 */
	 
	return (sum / i);
}

double Stdev (double arr[] , int i , double avg){
	int j;
	double dif = 0 , sum = 0;
	
	/*
	为了减少计算量，先对数据与平均值作差，得到double类型的 dif 
	用double类型的 sum对差的平方进行累次求和
	直至实际数据的最后一个值退出循环 
	*/ 
	
	for(j = 0 ; j < i ; j++){
		dif = arr[j] - avg;
		sum += dif * dif;
	}
	
	/* 最后进行除法后开方，求出标准差 */
	 
	return sqrt(sum/i);
} 
