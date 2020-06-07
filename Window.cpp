#include "Window.h"
 

      
    Window::Window()
    {
               
      
    }

    void Window::initWindow(const int width, const int height)
    {
        glfwInit();

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        m_window = glfwCreateWindow(width, height, "Observatory", NULL, NULL);
      
       
    }
    Window::~Window()
    {
        glfwDestroyWindow(m_window);
        glfwTerminate();
    }

