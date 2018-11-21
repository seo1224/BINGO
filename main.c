#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#define N 5
#define M 3

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
	
	//for(i = 0; i < N; i++){
		//for(j = 0; j< N; j++){
			//printf("|  %2d  |", bingoc[i][j]); }
		//printf("\n");} // 완성된 프로그램에서 지울 것임  
	
	return 0;
}

int get_number_byMe(int (*bingom)[N], int (*bingoc)[N]){
	
	int count = 0;
    int num = 0; // 입력된 수를 가리키는 변수 
    int i = 0, j = 0, k = 0, l = 0; // 반복문을 위한 변수 
    
    printf("당신의 선택 : ");
    scanf("%d", &num);
    
    if(num<=N*N && num>=1){
    	for(i = 0; i<N; i++){
    		for(j = 0; j<N; j++){
    			if(bingom[i][j] == num || bingoc[i][j] == num){
    				for(k = 0; k < N; k++){
    					for(l = 0; l < N; l++){
    						if(bingom[k][l]==num){
    							bingom[k][l] = -1;}
    						if(bingoc[k][l]==num){
    							bingoc[k][l] = -1;}	
						}
					} // 배열을 한 칸씩 확인하면서 입력된 숫자를 -1로 바꿈  
				}
				else {
					count++;} 
			}
		}
	}
	else {
		printf("빙고 범위를 넘어선 숫자 입니다. 다시 입력해 주세요\n");
		get_number_byMe(bingom, bingoc); // 빙고 숫자의 범위를 넘어서 숫자를 입력할 경우 다시 처음으로 돌아가게 만듬  
	}
	if(count == N*N ){
		printf("이미 입력한 숫자 입니다. 다시 입력해 주세요\n");
        count = 0;
        get_number_byMe(bingom, bingoc); // count가 N*N이 될 경우는 배열을 확인할 때 겹치는 숫자가 없었다는 뜻이므로 그 숫자는 이미 입력된 숫자임을 알 수 있음  
	}
	
	return 0;
}

int get_number_byCom(int (*bingom)[N], int(*bingoc)[N]){
	
    int count = 0;
    int num = 0;
    int i = 0, j = 0, k = 0, l = 0;
    
    num = rand()%(N*N); // 컴퓨터가 랜덤으로 숫자를 출력하게 만듬 
    
    if(num<=N*N && num>=1){
    	for(i = 0; i<N; i++){
    		for(j = 0; j<N; j++){
    			if(bingom[i][j] == num || bingoc[i][j] == num){
    				for(k = 0; k < N; k++){
    					for(l = 0; l < N; l++){
    						if(bingom[k][l]==num){
    							bingom[k][l] = -1;}
    						if(bingoc[k][l]==num){
    							bingoc[k][l] = -1;}	
						}
					}
				}
				else {
					count++;}
			}
		}
	}
	else {
		get_number_byCom(bingom, bingoc);
	}
    if(count == N*N ){
    	count = 0;
        get_number_byCom(bingom, bingoc); 
    } // 방식은 get_number_byMe와 동일  
     
    printf("컴퓨터의 선택 : %d\n", num);
    
    return 0;
} // get_number 함수와 process_bingo 함수를 합침 

int count_bingome(int (*bingom)[N]){
	
	int countx = 0; // 가로 빙수를 세기 위한 변수  
    int county = 0; // 세로 빙수를 세기 위한 변수
    int countzone = 0, countztwo = 0; // countzone은 왼쪽 위- 오른쪽 아래 대각선(왼-오 대각선)을 의미하고 countztwo는 오른쪽 위 - 윈쪽 아래 대각선(오-왼 대각선)을 의미한다  
    int countbingome = 0; // 총 빙고의 수를 의미하는 변수  
    int i = 0, j = 0, k = 0, l = 0, m = 0, n = 0;
    
    for(i = 0; i < N; i++){
    	for(j =0; j< N; j++){
    		if(bingom[i][j] == -1)
			{
    			countx++;
			} //빙고판에 -1로 표현된 칸이 있으면 countx가 1 추가되는 if문  
    	}
		if(countx==N){
			countbingome++;}
		countx = 0;//  가로 한 줄에 N개의 countx가 존재하면 빙고의 개수가 추가된다는 것을 의미하는 if문  
	} // 가로 빙고를 찾아내기 위한 for문  
	
	for(k = 0; k < N; k++){
    	for(l =0; l < N; l++){
    		if(bingom[l][k] == -1)
			{
    			county++;
			}
    	}
		if(county==N){
			countbingome++;}
		county = 0;
	}// 세로 빙고를 찾아내기 위한 for문, 방식은 가로 빙고 찾는 방법과 동일  
	
	for(m = 0; m < N; m++){
		if(bingom[m][m] == -1){
			countzone++;} // bingm [n][n]은 왼-오 대각선을 의미 
	}
	if(countzone == N)
		countbingome++;
		countzone = 0;
    //왼-오 대각선 빙고를 찾아내기 위한 for문과 if문 
	 
    for(n = 0; n < N; n++){
		if(bingom[n][N-n-1] == -1){
			countztwo++;}// bingm [n][N-n-1]은 왼-오 대각선을 의미 
	}
	if(countztwo == N)
		countbingome++;
		countztwo = 0;
	//오-윈 대각선 빙고를 찾아내기 위한 for문과 if문 
// 사용자 빙고판에 빙고가 몇 개인지 세는 함수
	return countbingome;
}

int count_bingocom(int (*bingoc)[N]){
	
	int countx = 0;
    int county = 0;
    int countzone = 0, countztwo = 0; // countzone은 왼쪽 위- 오른쪽 아래 대각선을 의미하고 countztwo는 오른쪽 위 - 윈쪽 아래 대각선을 의미한다  
    int countbingocom = 0;
    int i = 0, j = 0, k = 0, l = 0, m = 0, n = 0;
    
    for(i = 0; i < N; i++){
    	for(j =0; j< N; j++){
    		if(bingoc[i][j] == -1)
				countx++;
			}
		if(countx == N){
			countbingocom++;}
		countx = 0;
	}
	
	for(k = 0; k < N; k++){
    	for(l = 0; l < N; l++){
    		if(bingoc[l][k] == -1)
			    county++;
    	}
		if(county==N){
			countbingocom++;}
		county = 0;
	}
	
	for(m = 0; m < N; m++){
		if(bingoc[m][m] == -1){
			countzone++;}
	}
	if(countzone == N)
		countbingocom++;
	countzone = 0;
    
    for(n = 0; n < N; n++){
		if(bingoc[n][N-n-1] == -1){
			countztwo++;}
	}
	if(countztwo == N)
		countbingocom++;
	countztwo = 0;
		
// 사용자 빙고판에 빙고가 몇 개인지 세는 함수, 방식은 count_bingome 와 동일  
	return countbingocom;
}


int main(int argc, char *argv[]) {
	
	int bingo_me[N][N]={0};  
    int bingo_com[N][N]={0}; 
    // 빙고판 초기화  
    int turn = 1; // 몇번째 턴에 승부가 결정되는지 명시하기 위한 변수  

    srand(time(NULL)); // 난수를 최기화 시키는 함수  

    initiate_bingo(bingo_me, bingo_com);
    print_bingo(bingo_me, bingo_com);
   
    while(count_bingome(bingo_me) != M || count_bingocom(bingo_com) != M){
    	
    	get_number_byMe(bingo_me, bingo_com);
    	print_bingo(bingo_me, bingo_com);
        printf("현재 빙고의 개수는 당신이 %d개, 컴퓨터가 %d개 이며 %d 턴째입니다.\n", count_bingome(bingo_me), count_bingocom(bingo_com),turn);
        turn++;
        
    if(count_bingome(bingo_me)==M || count_bingocom(bingo_com)==M){
        break;} // 사용자의 턴에서 M을 만족하는 경우를 대비한다  

        get_number_byCom(bingo_me, bingo_com);
        print_bingo(bingo_me, bingo_com);
	    printf("현재 빙고의 개수는 당신이 %d개, 컴퓨터가 %d개 이며 %d 턴째입니다.\n", count_bingome(bingo_me), count_bingocom(bingo_com),turn);
        turn++;
   } // 두 빙고판중 하나가 빙고의 개수 M을 만족할 때까지 {}를 반복하는 while문 
   
    if(count_bingome(bingo_me) == M || count_bingocom(bingo_com) == M){
    	if(count_bingome(bingo_me) == M && count_bingocom(bingo_com) != M){
            printf("이 turn에서 당신의 승리!");
            }// 사용자의 빙고판만 M을 만족하는 경우 
        if(count_bingocom(bingo_com) == M && count_bingome(bingo_me) != M){
            printf("이 turn에서 컴퓨터의 승리!");
            }// 컴퓨터의 빙고판만 M을 만족하는 경우 
        if(count_bingome(bingo_me) == M && count_bingocom(bingo_com) == M){
        	printf("이 turn에서 무승부!");
		}// 둘다 M을 만족하는 경우 
      }   

    return 0;
}
