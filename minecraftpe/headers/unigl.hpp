#ifndef UNIGL_H
#define UNIGL_H
#include <mcpe_types.h>
#ifdef USEGLES
#ifdef __APPLE__
	#include <OpenGLES/ES1/gl.h>
	#include <OpenGLES/ES1/glext.h>
#else
	#include <GLES/gl.h>
	#include <EGL/egl.h>
	#include <GLES/glext.h>
#endif

	void gluPerspective(GLfloat fovy, GLfloat aspect, GLfloat znear, GLfloat zfar);
#else

#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/glu.h>

void initGlFuncs();
extern void (*glDeleteBuffers)(GLsizei n, const GLuint* buffers);
extern void (*glGenBuffers)(GLsizei n, GLuint* buffers);
extern void (*glBindBuffer)(GLenum target, GLuint buffer);
extern void (*glBufferData)(GLenum target, GLsizeiptr size, const void* data, GLenum usage);

#endif

int glhUnProjectf(float winx, float winy, float winz, float* modelview, float* projection, int* viewport, float* objectCoordinate);

#endif
