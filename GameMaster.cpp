#include "GameMaster.h"

void GameMaster::run()
{
	
	Window testWindow;
	InitVulkan();
	testWindow.initWindow(1200, 800);

	//Check and list extensions 
	uint32_t extensionCount = 0;
	vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
	std::vector<VkExtensionProperties> extensions(extensionCount);
	vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());


	std::cout << extensionCount << " extensions supported\n";
	for (const auto& extension : extensions) {
		std::cout << '\t' << extension.extensionName << '\n';
	}

	while (!glfwWindowShouldClose(testWindow.getWindowAddress())) { glfwPollEvents(); }

}

void GameMaster::CreateInstance()
{

	//Creating Vulkan instance filling out template from struct type
	VkApplicationInfo appInfo{};
	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName = "Hello Triangle";
	appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.pEngineName = "No Engine";
	appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.apiVersion = VK_API_VERSION_1_0;

	//Creating info, one of the ingredients in our vkCreateInstance call later
	VkInstanceCreateInfo createInfo{};
	createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	createInfo.pApplicationInfo = &appInfo;

	uint32_t glfwExtensionCount = 0;
	const char** glfwExtensions;

	//This is how we get the required information to make a surface in our window, similar to SDL_surface or whatever it is
	glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

	createInfo.enabledExtensionCount = glfwExtensionCount;
	createInfo.ppEnabledExtensionNames = glfwExtensions;
	createInfo.enabledLayerCount = 0;

	VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);

	if (result != VK_SUCCESS) { std::cout << "instance creation unsuccessful" << std::endl; }else
		if (result == VK_SUCCESS) { std::cout << "Instance created successfully" << std::endl; }

	uint32_t extensionCount = 0;
	vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

	std::vector<VkExtensionProperties> extensions(extensionCount);
	vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());

	std::cout << "available extensions:\n";

	for (const auto& extension : extensions) {
		std::cout << '\t' << extension.extensionName << '\n';
	}
}

void GameMaster::InitVulkan()
{
	CreateInstance();
}

void GameMaster::CleanUp()
{
	vkDestroyInstance(instance, nullptr);

}
