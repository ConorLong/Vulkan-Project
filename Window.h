#ifndef WINDOW_H
#define WINDOW_H

#include <GLFW/glfw3.h>

class Window
{
public:

	void initWindow(const int width, const int height);
	GLFWwindow* getWindowAddress() { return m_window; };
	
	Window();
	~Window();
	
private:
	 GLFWwindow* m_window;
};

#endif;