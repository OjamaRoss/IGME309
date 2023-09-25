#include "AppClass.h"
void Application::InitVariables(void)
{
	////Change this to your name and email
	m_sProgrammer = "Alberto Bobadilla - labigm@rit.edu";
	vector3 v3Position(0.0f, 0.0f, 10.0f);
	vector3 v3Target = ZERO_V3;
	vector3 v3Upward = AXIS_Y;
	m_pCameraMngr->SetPositionTargetAndUpward(v3Position, v3Target, v3Upward);

	//Allocate the memory for the Meshes

	m_uMeshCount = 46;

	for (int i = 0; i < m_uMeshCount; i++) {

		MyMesh* newMesh = new MyMesh();
		meshHolder.push_back(newMesh);
		meshHolder[i]->GenerateCube(1.0f, C_BLACK);

	}
		
}
void Application::Update(void)
{
	//Update the system so it knows how much time has passed since the last call
	m_pSystem->Update();

	//Is the arcball active?
	ArcBall();

	//Is the first person camera active?
	CameraRotation();

	//Update Entity Manager
	m_pEntityMngr->Update();

	//Add objects to render list
	m_pEntityMngr->AddEntityToRenderList(-1, true);
}
void Application::Display(void)
{
	// Clear the screen
	ClearScreen();

	//Calculate the model, view and projection matrix
	matrix4 m4Projection = m_pCameraMngr->GetProjectionMatrix();
	matrix4 m4View = m_pCameraMngr->GetViewMatrix();

	static float timer = 0;
	static int clock = m_pSystem->GenClock(); 
	timer += static_cast<float>(m_pSystem->GetDeltaTime(clock));

	matrix4 moving = glm::translate(vector3(timer,0.0f,0.0f));
	//matrix4 moving = glm::translate(vector3(0.0f, 0.0f, 0.0f));

	int count = 0;

	//1
	meshHolder[count]->Render(m4Projection, m4View, glm::translate(moving, vector3(-3.0f, 3.0f, -10.0f))); count++;
	meshHolder[count]->Render(m4Projection, m4View, glm::translate(moving, vector3(3.0f, 3.0f, -10.0f))); count++;

	//2
	meshHolder[count]->Render(m4Projection, m4View, glm::translate(moving, vector3(-2.0f, 2.0f, -10.0f))); count++;
	meshHolder[count]->Render(m4Projection, m4View, glm::translate(moving, vector3(2.0f, 2.0f, -10.0f))); count++;

	//3
	meshHolder[count]->Render(m4Projection, m4View, glm::translate(moving, vector3(-3.0f, 1.0f, -10.0f))); count++;
	meshHolder[count]->Render(m4Projection, m4View, glm::translate(moving, vector3(-2.0f, 1.0f, -10.0f))); count++;
	meshHolder[count]->Render(m4Projection, m4View, glm::translate(moving, vector3(-1.0f, 1.0f, -10.0f))); count++;
	meshHolder[count]->Render(m4Projection, m4View, glm::translate(moving, vector3(0.0f, 1.0f, -10.0f))); count++;
	meshHolder[count]->Render(m4Projection, m4View, glm::translate(moving, vector3(1.0f, 1.0f, -10.0f))); count++;
	meshHolder[count]->Render(m4Projection, m4View, glm::translate(moving, vector3(2.0f, 1.0f, -10.0f))); count++;
	meshHolder[count]->Render(m4Projection, m4View, glm::translate(moving, vector3(3.0f, 1.0f, -10.0f))); count++;

	//4
	meshHolder[count]->Render(m4Projection, m4View, glm::translate(moving, vector3(-4.0f, 0.0f, -10.0f))); count++;
	meshHolder[count]->Render(m4Projection, m4View, glm::translate(moving, vector3(-3.0f, 0.0f, -10.0f))); count++;
	meshHolder[count]->Render(m4Projection, m4View, glm::translate(moving, vector3(-1.0f, 0.0f, -10.0f))); count++;
	meshHolder[count]->Render(m4Projection, m4View, glm::translate(moving, vector3(0.0f, 0.0f, -10.0f))); count++;
	meshHolder[count]->Render(m4Projection, m4View, glm::translate(moving, vector3(1.0f, 0.0f, -10.0f))); count++;
	meshHolder[count]->Render(m4Projection, m4View, glm::translate(moving, vector3(3.0f, 0.0f, -10.0f))); count++;
	meshHolder[count]->Render(m4Projection, m4View, glm::translate(moving, vector3(4.0f, 0.0f, -10.0f))); count++;

	//5
	meshHolder[count]->Render(m4Projection, m4View, glm::translate(moving, vector3(-5.0f, -1.0f, -10.0f))); count++;
	meshHolder[count]->Render(m4Projection, m4View, glm::translate(moving, vector3(-4.0f, -1.0f, -10.0f))); count++;
	meshHolder[count]->Render(m4Projection, m4View, glm::translate(moving, vector3(-3.0f, -1.0f, -10.0f))); count++;
	meshHolder[count]->Render(m4Projection, m4View, glm::translate(moving, vector3(-2.0f, -1.0f, -10.0f))); count++;
	meshHolder[count]->Render(m4Projection, m4View, glm::translate(moving, vector3(-1.0f, -1.0f, -10.0f))); count++;
	meshHolder[count]->Render(m4Projection, m4View, glm::translate(moving, vector3(0.0f, -1.0f, -10.0f))); count++;
	meshHolder[count]->Render(m4Projection, m4View, glm::translate(moving, vector3(1.0f, -1.0f, -10.0f))); count++;
	meshHolder[count]->Render(m4Projection, m4View, glm::translate(moving, vector3(2.0f, -1.0f, -10.0f))); count++;
	meshHolder[count]->Render(m4Projection, m4View, glm::translate(moving, vector3(3.0f, -1.0f, -10.0f))); count++;
	meshHolder[count]->Render(m4Projection, m4View, glm::translate(moving, vector3(4.0f, -1.0f, -10.0f))); count++;
	meshHolder[count]->Render(m4Projection, m4View, glm::translate(moving, vector3(5.0f, -1.0f, -10.0f))); count++;

	//6
	meshHolder[count]->Render(m4Projection, m4View, glm::translate(moving, vector3(-5.0f, -2.0f, -10.0f))); count++;
	meshHolder[count]->Render(m4Projection, m4View, glm::translate(moving, vector3(-3.0f, -2.0f, -10.0f))); count++;
	meshHolder[count]->Render(m4Projection, m4View, glm::translate(moving, vector3(-2.0f, -2.0f, -10.0f))); count++;
	meshHolder[count]->Render(m4Projection, m4View, glm::translate(moving, vector3(-1.0f, -2.0f, -10.0f))); count++;
	meshHolder[count]->Render(m4Projection, m4View, glm::translate(moving, vector3(0.0f, -2.0f, -10.0f))); count++;
	meshHolder[count]->Render(m4Projection, m4View, glm::translate(moving, vector3(1.0f, -2.0f, -10.0f))); count++;
	meshHolder[count]->Render(m4Projection, m4View, glm::translate(moving, vector3(2.0f, -2.0f, -10.0f))); count++;
	meshHolder[count]->Render(m4Projection, m4View, glm::translate(moving, vector3(3.0f, -2.0f, -10.0f))); count++;
	meshHolder[count]->Render(m4Projection, m4View, glm::translate(moving, vector3(5.0f, -2.0f, -10.0f))); count++;

	//7
	meshHolder[count]->Render(m4Projection, m4View, glm::translate(moving, vector3(-5.0f, -3.0f, -10.0f))); count++;
	meshHolder[count]->Render(m4Projection, m4View, glm::translate(moving, vector3(-2.0f, -3.0f, -10.0f))); count++;
	meshHolder[count]->Render(m4Projection, m4View, glm::translate(moving, vector3(2.0f, -3.0f, -10.0f))); count++;
	meshHolder[count]->Render(m4Projection, m4View, glm::translate(moving, vector3(5.0f, -3.0f, -10.0f))); count++;

	//8
	meshHolder[count]->Render(m4Projection, m4View, glm::translate(moving, vector3(-2.0f, -4.0f, -10.0f))); count++;
	meshHolder[count]->Render(m4Projection, m4View, glm::translate(moving, vector3(-1.0f, -4.0f, -10.0f))); count++;
	meshHolder[count]->Render(m4Projection, m4View, glm::translate(moving, vector3(1.0f, -4.0f, -10.0f))); count++;
	meshHolder[count]->Render(m4Projection, m4View, glm::translate(moving, vector3(2.0f, -4.0f, -10.0f))); count++;

	// draw a skybox
	m_pModelMngr->AddSkyboxToRenderList();

	//render list call
	m_uRenderCallCount = m_pModelMngr->Render();

	//clear the render list
	m_pModelMngr->ClearRenderList();

	//draw gui
	DrawGUI();
	
	//end the current frame (internally swaps the front and back buffers)
	m_pWindow->display();
}
void Application::Release(void)
{
	//Release meshes

	std::vector<MyMesh*> meshHolder;

	for (int i = 0; i < meshHolder.size(); i++) {

		if (meshHolder[i] != nullptr) {

			delete meshHolder[i];
			meshHolder[i] = nullptr;
	
		}
	
	}

	//release GUI
	ShutdownGUI();
}