#pragma once

#include <stdio.h>
#include "../Source/BaseObjectClass.h"
#include "iostream"
#include <map>
#include <list>
#include <iterator>
class SceneGraph
{
public:
	SceneGraph();
	~SceneGraph();

public:
	void PrintAllObjectData();
	void AddtoSceneGraph(BaseObjectClass* object);
	void RemoveFromSceneGraph(BaseObjectClass* object);
	void Update();
	void Start();
	void EmptyBuffer();
private:
	std::map<int, BaseObjectClass*> m_ObjectsBuffer;
	std::map<int, BaseObjectClass*> m_Objects;
	static int nextObjectID;
	static int bufferNextObjectID;
};


