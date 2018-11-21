#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#define N 5

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int initiate_bingo (int (*bingom)[N], int (*bingoc)[N]){
	
	int num [N*N]; // �����ǿ� ���� �ٸ� ���ڸ� �ֱ� ���� �迭 ���� 
	int bingnum; // ���� �Լ��� ������ ����
	int n = 0, i = 0, j = 0;
	
	for(n = 0; n < N*N; n++){
		num[n] = n + 1;
	} // num �迭 ����
	
	for(i = 0; i < N; i++){
		for(j= 0; j < N; j++){
			bingnum = rand()%(N*N);
			
			if (num[bingnum] == 0)
			{
				j--;
			}
			else
			{
				bingom[i][j] = num[bingnum];
                num[bingnum] = 0; 
			}// ������ ���ڰ� ������ �װ��� �����ǿ� �����ϰ� �̿� �ش��ϴ� num �迭�� 0���� �ٲپ� �ߺ��� ���Ѵ� 
			}
		} // ����� ������  
	
	for(n = 0; n < N*N; n++){
		num[n] = n + 1;
	} // num �迭 ����
	
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			bingnum = rand()%(N*N);
			
			if (num[bingnum] == 0)
			{
				j--;
			}
			else
			{
				bingoc[i][j] = num[bingnum];
                num[bingnum] = 0;
			}
			}
		}// ��ǻ�� ������
		
	return 0;
}

int print_bingo(int (*bingom)[N], int (*bingoc)[N]){
	int i = 0, j = 0;
	
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			printf("|  %2d  |", bingom[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	for(i = 0; i < N; i++){
		for(j = 0; j< N; j++){
			printf("|  %2d  |", bingoc[i][j]); 
		}
		printf("\n");
	} // �ϼ��� ���α׷����� ���� ����  
	
	return 0;
}


int main(int argc, char *argv[]) {
	
	int bingo_me[N][N]={0};
    int bingo_com[N][N]={0};
    
    initiate_bingo(bingo_me, bingo_com);
    print_bingo(bingo_me, bingo_com);
    
	return 0;
}
