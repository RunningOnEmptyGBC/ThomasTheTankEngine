#include "SceneGraph.h"

// Initialize our static unique objectID generator
int SceneGraph::nextObjectID = 0;
int SceneGraph::bufferNextObjectID = 0;
bool New = false;

SceneGraph::SceneGraph()
{
}

SceneGraph::~SceneGraph()
{
}

void SceneGraph::PrintAllObjectData()
{
	system("CLS");
	std::map<int, BaseObjectClass*>::iterator it = m_Objects.begin();
	for (it = m_Objects.begin(); it != m_Objects.end(); ++it) {
		std::cout << it->first << " => " << it->second->Name << '\n';
		it->second->PrintPos();
		it->second->PrintChildPos();
	}
	
}

void SceneGraph::AddtoSceneGraph(BaseObjectClass* object)
{
	std::cout << object->Name;
	m_ObjectsBuffer.insert(std::pair<int, BaseObjectClass*>(bufferNextObjectID, object));
	object->IDNumber = bufferNextObjectID;
	bufferNextObjectID++;
	//PrintAllObjectData();
	New = true;
}0

void SceneGraph::RemoveFromSceneGraph(BaseObjectClass * object)
{
	m_Objects.erase(object->IDNumber);
}

void SceneGraph::Update()
{

	//PrintAllObjectData();
	std::map<int, BaseObjectClass*>::iterator it = m_Objects.begin();
	for (it = m_Objects.begin(); it != m_Objects.end(); ++it) {
		it->second->Update();
	}
	//PrintAllObjectData();
	if(New)
		EmptyBuffer();
}
void SceneGraph::Start()
{
	std::map<int, BaseObjectClass*>::iterator it = m_Objects.begin();
	for (it = m_Objects.begin(); it != m_Objects.end(); ++it) {
		it->second->Start();
	}
	//PrintAllObjectData();
}

void SceneGraph::EmptyBuffer()
{
	std::map<int, BaseObjectClass*>::iterator it = m_ObjectsBuffer.begin();
	//m_Objects.clear();
	nextObjectID = 0;
	for (it = m_ObjectsBuffer.begin(); it != m_ObjectsBuffer.end(); ++it) {
		it->second->IDNumber = nextObjectID;
		nextObjectID++;
		m_Objects.insert(std::pair<int, BaseObjectClass*>(nextObjectID, it->second));
		
	}
	//TODO: Figure Out how to Remove from Buffer without crashing
	m_ObjectsBuffer.clear();
	bufferNextObjectID = 0; 
	PrintAllObjectData();
	New = false;
}
