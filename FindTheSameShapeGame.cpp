#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <conio.h>

int playerMove(char*,char*);
int count(char,char*,int);
void mainListCreater(char*,int);
void drawBoard(char*,int);
void check(char*,char*,int,int,int&);

int main(){
	
	char tableList[] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
	char mainList[] = {'!','@','#','$','%','&','+','?','!','@','#','$','%','&','+','?'};
	
	int size = sizeof(mainList); // or sizeof(mainList)/sizeof(char) - char = 1byte;
	int first,second;
	int point = 0;
	
	mainListCreater(mainList,size);
	
	while(true){
		
		drawBoard(tableList,point);
		first = playerMove(mainList,tableList);
		drawBoard(tableList,point);
		second = playerMove(mainList,tableList);
		drawBoard(tableList,point);
		
		std::cout<<"Press a button to continue";
		getch();
		
		check(tableList,mainList,first,second,point);
		
		if(count(' ',tableList,size) == 0){
			break;
		}
	}
	
	drawBoard(tableList,point);
	
	return 0;
}
int playerMove(char *mainList,char *tableList){
	
	int playerChoose;
	
	do{
		std::cout<<"Please just enter a number (1-16): ";
		std::cin>>playerChoose;
		playerChoose--;
	}while(playerChoose < 0 || playerChoose > 15 || tableList[playerChoose] != ' ');
	
	tableList[playerChoose] = mainList[playerChoose];
	
	return playerChoose;
}
int count(char num,char *mainList,int size){
	
	int counter = 0;
	
	for(int i=0;i<size;i++){
		if(mainList[i] == num){
			counter++;
		}
	}
	return counter;
}
void mainListCreater(char *mainList,int size){
	
	srand(time(0));
	int a,b,temp;
	
	for(int i=0;i<size;i++){
		do{
			a = rand()%size;
			b = rand()%size;
		}while(a == b);
		
		temp = mainList[a];
		mainList[a] = mainList[b];
		mainList[b] = temp;
	}	
}
void drawBoard(char *tableList,int point){
	
	system("cls");
	
	std::cout<<"     |     |     |"<<"\n";
	std::cout<<"  "<<tableList[0]<<"  |  "<<tableList[1]<<"  |  "<<tableList[2]<<"  |  "<<tableList[3]<<"\n";
	std::cout<<"_____|_____|_____|_____"<<"\n";
	std::cout<<"     |     |     |"<<"\n";
	std::cout<<"  "<<tableList[4]<<"  |  "<<tableList[5]<<"  |  "<<tableList[6]<<"  |  "<<tableList[7]<<"\n";
	std::cout<<"_____|_____|_____|_____"<<"\n";
	std::cout<<"     |     |     |"<<"\n";
	std::cout<<"  "<<tableList[8]<<"  |  "<<tableList[9]<<"  |  "<<tableList[10]<<"  |  "<<tableList[11]<<"\n";
	std::cout<<"_____|_____|_____|_____"<<"\n";
	std::cout<<"     |     |     |"<<"\n";
	std::cout<<"  "<<tableList[12]<<"  |  "<<tableList[13]<<"  |  "<<tableList[14]<<"  |  "<<tableList[15]<<"\n";
	std::cout<<"     |     |     |     "<<"\n";
	std::cout<<"Your point: "<<point<<"\n";
		
}
void check(char *tableList,char *mainList,int first,int second,int &point){
	
	if(mainList[first] == mainList[second]){
		point++;
	}
	else{
		tableList[first] = ' ';
		tableList[second] = ' ';
		if(point > 0){
			point--;
		}
	}
}
