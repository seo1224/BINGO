#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#define N 5

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int initiate_bingo (int (*bingom)[N], int (*bingoc)[N]){
	
	int num [N*N]; // 빙고판에 각각 다른 숫자를 넣기 위한 배열 선언 
	int bingnum; // 랜덤 함수를 적용할 변수
	int n = 0, i = 0, j = 0;
	
	for(n = 0; n < N*N; n++){
		num[n] = n + 1;
	} // num 배열 정의
	
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
			}// 임의의 숫자가 뽑히면 그것을 빙고판에 적용하고 이에 해당하는 num 배열을 0으로 바꾸어 중복을 피한다 
			}
		} // 사용자 빙고판  
	
	for(n = 0; n < N*N; n++){
		num[n] = n + 1;
	} // num 배열 정의
	
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
		}// 컴퓨터 빙고판
		
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
	} // 완성된 프로그램에서 지울 것임  
	
	return 0;
}


int main(int argc, char *argv[]) {
	
	int bingo_me[N][N]={0};
    int bingo_com[N][N]={0};
    
    initiate_bingo(bingo_me, bingo_com);
    print_bingo(bingo_me, bingo_com);
    
	return 0;
}
