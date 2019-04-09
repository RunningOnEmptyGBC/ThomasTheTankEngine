#pragma once
#include <stdlib.h>  
#include <string> 
#include <stdio.h>
#include <iostream>
#include <vector>
#include "../GameEngine/ModelBase.h"
#include "DXapp.h"
//This class acts as the base for all object classes
//All objects should be dirived from this class

//Currently only supports one level of children,
//	once the MoveChildren function is functional it will support infinite levels

class BaseObjectClass
{
public:
	struct position {
	float x;
	float y;
	float z;
	};
	enum ObjectType { Player, Enemie, Projectile, Obstacle };
	std::string Name;
	ObjectType Type;
	position position;
	std::vector<BaseObjectClass*> Children;
	int IDNumber;
	//Model model;  //This is placeholder till real models are implimented
	
	BaseObjectClass();
	BaseObjectClass(DXapp * D3d, const wchar_t * Model, const wchar_t * Texture);
	BaseObjectClass(DXapp * D3d, const wchar_t Model, const wchar_t Texture);
	BaseObjectClass(std::string name);
	//Old Functions
	void setType(int type);
	void MoveChildren(int direction,int pos);
	void MoveRight(int direction);
	void MoveForward(int direction);
	void PrintPos();
	void PrintChildPos();

	//NewFunctions
	void Start();
	void Awake();
	void Update();
	void LateUpdate();

	ModelBase model;

	~BaseObjectClass();
};

