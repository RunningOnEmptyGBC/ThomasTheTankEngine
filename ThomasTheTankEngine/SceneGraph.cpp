#include "SceneGraph.h"

// Initialize our static unique objectID generator
int SceneGraph::nextObjectID = 0;

SceneGraph::SceneGraph()
{
}

SceneGraph::~SceneGraph()
{
}

void SceneGraph::PrintAllObjectData()
{
	std::map<int, BaseObjectClass*> m_ObjectsCopy  = m_Objects;
	std::map<int, BaseObjectClass*>::iterator it = m_ObjectsCopy.begin();
	for (it = m_ObjectsCopy.begin(); it != m_ObjectsCopy.end(); ++it) {
		std::cout << it->first << " => " << it->second->Name << '\n';
		it->second->PrintPos();
		it->second->PrintChildPos();
	}

}

void SceneGraph::AddtoSceneGraph(BaseObjectClass* object)
{
	m_Objects.insert(std::pair<int, BaseObjectClass*>(nextObjectID, object));
	object->IDNumber = nextObjectID;
	nextObjectID++;
	system("CLS");
	PrintAllObjectData();
}

void SceneGraph::RemoveFromSceneGraph(BaseObjectClass * object)
{
	m_Objects.erase(object->IDNumber);
}

void SceneGraph::Update()
{
	std::map<int, BaseObjectClass*>::iterator it = m_Objects.begin();
	for (it = m_Objects.begin(); it != m_Objects.end(); ++it) {
		it->second->Update();
	}
	//PrintAllObjectData();
}
