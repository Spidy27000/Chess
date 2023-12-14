#pragma once
#include "Peice.h"
#include "setting.h"
#include "Vec2.h"
#include <iostream>


class Rook : public mPeice {
public:
	Rook(Vec2 pos, int color) :mPeice(pos, color, peices::rook){
		this->directions = {"north","south","east","west"}; 
		this->color = color; 
	}
	
	~Rook(){};
	std::vector<Vec2> GetNormalMoves(Peice currBoard[][8]) override {
		return GetMoves(this->directions, this->color ,currBoard);
	}

};
class Bishop : public mPeice {
public:
	Bishop(Vec2 pos, int color) :mPeice(pos, color, peices::bishop){
		this->directions = {"north-east","south-west","south-east","north-west"}; 
		this->color = color; 
	}
	
	~Bishop(){};
	std::vector<Vec2> GetNormalMoves(Peice currBoard[][8]) override {
		return GetMoves(this->directions, this->color ,currBoard);
	}
	
	
};
class Qween : public mPeice {
public:
	Qween(Vec2 pos, int color) :mPeice(pos, color, peices::qween){
		this->directions = {"north-east","south-west","south-east","north-west","north","south","east","west"}; 
		this->color = color; 
	}
	
	~Qween(){};
	std::vector<Vec2> GetNormalMoves(Peice currBoard[][8]) override {
		return GetMoves(this->directions, this->color ,currBoard);
	}
		
	
};
class Knight : public mPeice {
public:
	Knight(Vec2 pos, int color) :mPeice(pos, color, peices::knight){
		this->color = color;
		this->dirs = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}}; 
	}
	
	~Knight(){};
	std::vector<Vec2> GetNormalMoves(Peice currBoard[][8]) override {
		return GetMoves(this->dirs,this->color,currBoard);
	}
};
class Pawn : public mPeice {
public:
	Pawn(Vec2 pos, int color) :mPeice(pos, color, peices::pawn){
		this->color = color; 
	}
	
	~Pawn(){};
	std::vector<Vec2> GetNormalMoves(Peice currBoard[][8]) override {
		std::vector<Vec2> validMove{};
		Vec2 tempPos = this->pos;
		Vec2 dirY ;
		if (this -> color == peices::black){
			dirY = {0,1};
		}
		else {
			dirY = {0,-1};
		}


		
		tempPos += dirY;
		 
		if(((tempPos.x >= 0 ) && (tempPos.x <=7 )&& (tempPos.y >= 0 ) && (tempPos.y <=7 )) &&
		 	(currBoard[tempPos.x][tempPos.y].peice->color == 0 )) {

			validMove.push_back(tempPos); 
			
			tempPos += dirY;

			if (((tempPos.x >= 0 ) && (tempPos.x <=7 )&& (tempPos.y >= 0 ) && (tempPos.y <=7 ) ) && 
				(!hasMoved) && 
				(currBoard[tempPos.x][tempPos.y].peice->color == 0)){
				validMove.push_back(tempPos); 
			}

		}
		tempPos = this->pos;
		Vec2 dirX[2]= {{1,0},{-1,0}};
		for (int i = 0 ;i<2;i++){
			tempPos+= dirY+dirX[i];
			if (((tempPos.x >= 0 ) && (tempPos.x <=7 )&& (tempPos.y >= 0 ) && (tempPos.y <=7 )) &&
			 	currBoard[tempPos.x][tempPos.y].peice->color != this->color &&
				currBoard[tempPos.x][tempPos.y].peice->color !=0 ){
				validMove.push_back(tempPos);
			}
			tempPos += dirY*-1+ dirX[i] *-1;
		}
	
		return validMove;
	}

	
};
class King : public mPeice {
public:
	King(Vec2 pos, int color) :mPeice(pos, color, peices::king){
		this->color = color; 
		this->dirs = {{1,0},{1,0},{0,1},{0,-1},{1,1},{1,1},{-1,-1},{1,-1}};
	}
	
	~King(){};
	std::vector<Vec2> GetNormalMoves(Peice currBoard[][8]) override {
		return GetMoves(this->dirs,this->color,currBoard);
	}
	
};

class NonePeice : public mPeice {
public:
	NonePeice(Vec2 pos) :mPeice(pos,0, peices::none){
		this->id = 0;
	}
	~NonePeice(){};
	std::vector<Vec2> GetNormalMoves(Peice currBoard[][8]) override {
		return{};
	}
};

