#pragma once
class OpenGLSystem
{
public:
	// window size and update rate (60 fps)
	static const int width = 434;
	static const int height = 200;
	static const int interval = 1000 / 60;
public:
	OpenGLSystem() {};
	~OpenGLSystem() {};
};