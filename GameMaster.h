#ifndef GAMEMASTER_H
#define GAMEMASTER_H

#define GLFW_INCLUDE_VULKAN


#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>

#include "Window.h"

class GameMaster
{
public:

	void run();

private:

	VkInstance instance;


	void CreateInstance();
	void InitVulkan();
	void GameLoop();
	void CleanUp();

};
#endif;
