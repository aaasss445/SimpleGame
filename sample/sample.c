#include<stdio.h>
#include"turbo.h"
#include<windows.h>
#include <time.h>
#include <stdlib.h>


#define TL 257
#define TR 258
#define BL 259
#define BR 260
#define V 261
#define H 262

//char arr[4][4] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };

int arr[8];
int cardNum[8];
int Default[8];
//int Default2[8];

void SetPosition() {
	gotoxy(0, 20);
}

void settextcolor(int foreground, int background) {
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void DrawCard(int x, int y) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			gotoxy(x * 9 + j, y * 5 + i);
			if (i == 0 && j == 0) {
				printf("%c", TL);
			}
			if (i == 0 && j == 8) {
				printf("%c", TR);
			}
			if (i == 4 && j == 0) {
				printf("%c", BL);
			}
			if (i == 4 && j == 8) {
				printf("%c", BR);
			}
			else if ((i == 0 || i == 4) && (j != 0 && j != 8)) {
				printf("%c", H);
			}
			if ((i != 0 && i != 4) && (j == 0 || j == 8)) {
				printf("%c", V);
			}
		}
	}
	gotoxy(x * 9 + 4, y * 5 + 2);
	//printf("%d", arr[y][x]);
}

void SelectedCard(int x, int y) {
	settextcolor(12, 0);
	DrawCard(x, y);
	settextcolor(15, 0);
}

void SelectingCard(int x, int y) {
	settextcolor(8, 0);
	DrawCard(x, y);
	settextcolor(15, 0);
}

void SelectingSelectedCard(int x, int y) {
	settextcolor(4, 0);
	DrawCard(x, y);
	settextcolor(15, 0);
}

int main(void) {
	//system("mode con:cols=36 lines=30");
	//setcursortype(NOCURSOR);
	//for (int i = 0; i < 500; i++) {
	//	printf("%d : %c\t", i, i);
	//	if (i % 4 == 3) {
	//		printf("\n");
	//	}
	//}
	int r1 = 0;
	//int r2 = 0;

	int i = 0;
	while (i <= 7) {										//카드설정						//8번째 까지		


		for (int D = 0; D < 8; D++) {						//1~8까지 카드값
			Default[D] = D + 1;
			//Default2[D] = D + 1;
		}

		int temp1 = 0;
		//int temp2 = 0;
		srand(time(NULL));
		for (int i = 0; i < 8; i++) {						//순서대로 됐으니까 랜덤으로 

			r1 = rand() % 8;

			temp1 = Default[i];
			Default[i] = Default[r1];
			Default[r1] = temp1;

		}

		for (int j = 0; j < 8; j++) {						//arr[i] == cardNum[i] == Default[j]

			arr[j] = Default[j];
			cardNum[j] = Default[j];

		}
		//srand(time(NULL));
		//for (int i = 0; i < 8; i++) {						//순서대로 됐으니까 랜덤으로 
		//	
		//	r2 = rand() % 8;
		//	temp2 = Default2[i];

		//	Default2[i] = Default2[r2];
		//	Default2[r2] = temp2;
		//	Default2.reverse();
		//}
		//for (int j = 0; j < 8; j++) {						//arr[i] == cardNum[i] == Default[j]
		//
		//	cardNum[j] = Default2[j];
		//}

	// arr[i]==cardNum[i]니까 cardNum[i]값을 섞으면 출력 x => arr[i]를 랜덤으로 섞고 cardNum[i]를 섞어야함
		//만약 


		if (arr[i] == cardNum[i]) {
			printf("arr카드 %d번째   %d   cardnum카드 %d번째   %d\n", i, arr[i], i + 8, cardNum[i]);
			i++;
		}
	}
	printf("\n\n카드 뒤집기!\n");																//--------시작----------
	printf("----------------------\n");
	printf("시도 가능 횟수는 30회입니다.\n\n");
	printf("원하는 카드 번호를 입력하세요!\n\n");
	//int duplicate1[30];							중복막기
	int card1 = 0, card2 = 0;
	int true1 = 0, true2 = 0;
	int chance = 0;
	while (chance != 30) {
		scanf_s("%d %d", &card1, &card2);


		//for (int i = 0; i < 30; i++) {														//중복입력 무효
		//	for (int j = 1; j < 30; j++) {
		//		if (duplicate1[i] == duplicate1[j]) {
		//			chance++;
		//			true1--;
		//			printf(" 이미 중복된 카드 번호입니다.\n 시도횟수 : %d \n\n 정답횟수 : %d\n\n", chance,true1);
		//		}
		//	}
		//}

		if (arr[card1] == cardNum[card2]) {					//정답
			printf("정답이에요~~~!\n\n");
			true1 += 1;
			chance++;
			printf("시도 횟수 : %d\n", chance);
			printf("정답 횟수 : %d\n\n", true1);
		}
		else if (arr[card1] != cardNum[card2]) {				//오답
			printf("틀렸네요~~~~^^\n\n\n 맞추고 싶은 카드번호를 입력해주세요\n");
			chance++;
			printf("시도 횟수 : %d\n정답 횟수 : %d\n\n", chance, true1);
		}

		/*if (true1==card1 || true2==card2)
		{
			printf("이미 맞춘 카드 번호입니다!\n\n\n 카드번호를 다시 입력해주세요. : ");
			scanf_s("%d %d", &card1, &card2);
		}
		if (true2 == 8) {
			break;
		}*/
	}
	printf(" 게임이 끝났습니다!");
}