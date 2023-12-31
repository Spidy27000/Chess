#ifndef PIECE_H
#define PIECE_H

#pragma once
#include "Vec2.h"
#include <unordered_map>
#include <string>
#include <vector>

struct Peice;

class mPeice
{
private:
	std::vector<Vec2> GetMoveInDirection(Vec2 dir,int color,Peice currBoard[][8]);

protected:
	std::unordered_map <std::string, Vec2> direction ;
	Vec2 pos;
	std::vector<Vec2> GetMoves(std::vector<std::string> directions,int color,Peice currBoard[][8]);	
	std::vector<Vec2> GetMoves(std::vector<Vec2> directions,int color,Peice currBoard[][8]);

	
public:
	mPeice(Vec2 pos,int color,int id);
	virtual ~mPeice(){};
	int id;
	std::vector<std::string> directions;
	std::vector<Vec2> dirs;

	bool hasMoved = false;

 	int color;
	virtual std::vector<Vec2> GetNormalMoves(Peice currBoard[][8]) = 0; 
	void SetPos(Vec2);
};

struct Peice{
	mPeice* peice;
};
#endif
