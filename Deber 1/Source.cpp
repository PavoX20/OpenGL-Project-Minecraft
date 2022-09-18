#include <GLFW/glfw3.h>

int main(void) 
{
    GLFWwindow* window;// instanciamos el objeto windows

    /* Initialize the library */
    if (!glfwInit()) //comprobamos que la librearía si inicializa con éxito
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);  // Le da identidad el objeto window en una ventana con el contexto de opengl
    if (!window)// si es que el objeto window es falso (dió error) se termina glfw y termina el programa lanzando un -1 de error
    {
        glfwTerminate();//termina la ventana glfw
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window); //hace el cozntexto de un objeto window llamandolo desde el hilo actual

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))//mantiene la ventana abierta hasta que el usuario cierra la ventana
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);//Punto de renderizado

        /* Swap front and back buffers */
        glfwSwapBuffers(window);//intercambiar entre buffers frontal y posterior

        /* Poll for and process events */
        glfwPollEvents();//procesa los aquellos eventos que estan en cola
    }

    glfwTerminate();//termina el proceso glfw
    return 0;
}