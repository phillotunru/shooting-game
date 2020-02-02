#include<bits/stdc++.h>
#include <fstream>
#include <algorithm>
#include <conio.h>
#include<windows.h>

#include <stdio.h>
#include <iostream>
#include <conio.h>
using namespace std;
const int mapSize = 20;
int pos_x, pos_y, mapp[mapSize+10][mapSize+10];
void PlAY();
void update();
void move(char c);
void printMap();
void initMap();
bool kapal(int x, int y);

void PLAY(){
	int cnt = 1;
	initMap();
	while(true){
		if (kbhit()){
			char temp = getch();
			move(temp);
		}	
		if (cnt) mapp[pos_x][pos_y] = 2;
		update();
		system("cls");
		printMap();
		_sleep(5);
	}
}
bool kapal(int x, int y){
	if (x==pos_x){
		if (abs(pos_y-y)<=1) return true;
	}
	if (y==pos_y && x == pos_x-1) return true;
	return false;
}
void update(){
	for (int i = 0; i < mapSize; i++){
		for (int j = 0; j < mapSize; j++){
			if (mapp[i][j]==2){
				mapp[i][j] = 0;
				if (i>1){
					if (mapp[i-1][j]==3) mapp[i-1][j] = 0; else mapp[i-1][j] = 2;
				}
			}
		}
	}
}
void move(char c){
//	assert(0);
	if (c=='a'){
		if (pos_y > 2)pos_y--;
	}
	if (c=='d'){
		if (pos_y < mapSize-3) pos_y++;
	}
	if (c=='w'){
		if (pos_x > 2)pos_x--;
	}
	if (c=='s'){
		if (pos_x < mapSize-2) pos_x++;
	}
	return;
}
void printMap(){
	for (int i = 0; i < mapSize; i++){
		for (int j = 0; j < mapSize; j++){
			if (kapal(i, j)){
				putchar('O');
			}
			else if (mapp[i][j]==1) putchar('#');
			else if (mapp[i][j]==2) putchar('*');
			else if (mapp[i][j]==3) putchar('#');
			else putchar(' ');
		}
		putchar('\n');
	}
}
void initMap(){
	pos_x = mapSize-2;
	pos_y = mapSize/2;
	for (int i = 0; i < mapSize; i++)
		for (int j = 0; j < mapSize; j++)
			mapp[i][j] = 1;
	for (int i = 1; i < mapSize-1; i++)
		for (int j = 1; j < mapSize-1; j++)
			mapp[i][j] = 0;
	for (int i = 1; i < mapSize/2; i++)
		for (int j = 1; j < mapSize-1; j++)
			mapp[i][j] = 3;
	return;
	
}
int main(){
	PLAY();
}
