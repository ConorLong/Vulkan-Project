
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>
#include <iostream>


#include "GameMaster.h"
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>


int main()
{
	GameMaster game;
	
	try {
		game.run();
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;

}