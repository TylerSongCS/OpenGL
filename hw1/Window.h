#ifndef _WINDOW_H_
#define _WINDOW_H_

#ifdef __APPLE__
#define GLFW_INCLUDE_GLCOREARB
#include <OpenGL/gl3.h>
#else
#include <GL/glew.h>
#endif
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <vector>
#include <memory>

#include "Object.h"
#include "Cube.h"
#include "PointCloud.h"
#include "SceneGraph.hpp"
#include "Frustum.hpp"
#include "shader.h"
#include "Skybox.hpp"
#include "BezierCurve.hpp"
#include "ControlPoint.hpp"
#include "HandleBar.hpp"
#include "shader2.h"


class Window
{
public:
    struct Material {
        glm::vec3 ambient;
        glm::vec3 diffuse;
        glm::vec3 specular;
        GLfloat shininess;
    };
    static Material material;
    static float ambientStrength;
    static float diffuseStrength;
    static float specularStrength;
    static int isPhong;
    
    static glm::vec3 lightColor;
    

    static float interpFactor;
    
	static int width;
	static int height;
    
    static bool is_button_down;
    static glm::vec3 lastPoint;
    static glm::vec3 currPoint;
	static const char* windowTitle;

	static glm::mat4 projection;
	static glm::mat4 view;
	static glm::vec3 eye, center, up, light_pos;
    static GLuint program, skyboxShader, cubemapShader,bezierCurveShader, bezierHandleShader, projectionLoc, lightLoc, eyeLoc, lightColorLoc;

	static bool initializeProgram();
	static bool initializeObjects();
	static void cleanUp();
	static GLFWwindow* createWindow(int width, int height);
	static void resizeCallback(GLFWwindow* window, int width, int height);
	static void idleCallback();
	static void displayCallback(GLFWwindow*);
	static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
    static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
    static glm::vec3 trackBallMapping( float xpos, float ypos, int width, int height);
    static void setMaterial (int option, Geometry* obj);
    static void interpolate(glm::vec3 fromPos, glm::vec3 toPos, float weight);
    static int checkCurrentCtrl(int index);
    static void handleManipulate(glm::vec3 translateAmount);
};

#endif