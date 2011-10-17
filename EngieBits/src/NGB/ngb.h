/*
 * EngieBits (NGB) Video Game Engine
 * Version: 0.1
 *
 * Copyright (c) 2011 Dennis Lawter. All rights reserved.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * DENNIS LAWTER BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef NGB_H_
#define NGB_H_

/*
 * ----------------------------------------------------------------
 * Basic type definitions
 * ----------------------------------------------------------------
 */

#define NGB_TRUE 1
#define NGB_FALSE 0

typedef int NGBboolean;
typedef unsigned int NGBuint;
typedef int NGBint;
typedef float NGBfloat;
typedef double NGBdouble;

/*
 * ----------------------------------------------------------------
 * Simple data structures provided by engine
 * ----------------------------------------------------------------
 */

//Linked List
struct NGBLL_NODE {
	void *content;
	struct NGBLL_NODE *next;
	struct NGBLL_NODE *last;
}typedef NGBLL_NODE;

struct NGBLL {
	struct NGBLL_NODE *head;
	struct NGBLL_NODE *tail;
	NGBuint size;
}typedef NGBLL;

NGBLL* ngbLL_create(void);
void ngbLL_insertFront(NGBLL* list, void* newhead);
void ngbLL_insertBack(NGBLL* list, void* newtail);
void* ngbLL_removeFront(NGBLL* list);
void* ngbLL_removeBack(NGBLL* list);
void* ngbLL_peakFront(NGBLL* list);
void* ngbLL_peakBack(NGBLL* list);
void ngbLL_insertAt(NGBLL* list, NGBuint key, void* newnode);
void* ngbLL_removeAt(NGBLL* list, NGBuint key);
void* ngbLL_peakAt(NGBLL* list, NGBuint key);
void ngbLL_toArray(NGBLL* list, void* array, int* size);
void ngbLL_destroy(NGBLL* list);

//Dynamic Array

struct NGBDA {
	void* data;
	NGBuint size;
	NGBuint capacity;
}typedef NGBDA;

NGBDA* ngbDA_create(void);
void ngbDA_set(NGBDA* dynarr, NGBuint key, void* value);
void* ngbDA_get(NGBDA* dynarr, NGBuint key);
void ngbDA_destroy(NGBDA* dynarr);

//Associative Array

struct NGBAA {
	NGBDA* keys;
	NGBDA* values;
}typedef NGBAA;

NGBAA* ngbAA_create(void);
void ngbAA_set(NGBAA* assarr, char* key, void* value);
void* ngbAA_get(NGBAA* assarr, char* key);
void ngbAA_destroy(NGBAA* assarr);

//Hash Table

struct NGBHT {
	NGBLL* buckets;
}typedef NGBHT;

NGBHT* ngbHT_create(void);
void ngbHT_insert(char* key, void* data);
void* ngbHT_get(char* key);
char ngbHT_hash(char* key);
void ngbHT_destroy(void);

/*
 * ----------------------------------------------------------------
 * Main engine
 * ----------------------------------------------------------------
 */

struct NGBkeyListener {
	NGBboolean altf4;
	NGBboolean keys[512];
}typedef NGBkeyListener;

struct NGBvertex {
	double x;
	double y;
	double z;
}typedef NGBvertex;
typedef NGBvertex NGBvector;
typedef NGBvertex NGBrotation;
typedef NGBvertex NGBpoint;

struct NGBhitBox {
	NGBpoint origin;
	NGBpoint oppositeCorner;
}typedef NGBhitBox;

struct NGBcamera {
	NGBpoint position;
	NGBrotation rotation;
	NGBboolean threeDimensional;
	int fieldOfView;
}typedef NGBcamera;

struct NGB2DphysicsObject {
	NGBpoint position;
	NGBpoint centroid;
	NGBboolean isSolid;
	double mass;
	double coefficientOfFriction;
	NGBvector velocity;
	NGBvector acceleration;
	NGBvector jerk;
	NGBuint* bitMask;
}typedef NGBphysicsObject;

struct NGBdrawable2D {
	NGBpoint origin;
	double width;
	double height;
	int spriteTexture;
	NGBboolean isVisible;
	NGBphysicsObject physics;
}typedef NGBdrawable2D;

struct NGBdrawable3D {
	NGBpoint origin;
	int vertexBuffer;

	int numBoxes;
}typedef NGBdrawable3D;

void ngbInit(int* argc, char** argv, NGBboolean doubleBuffer);
int ngbInitWindowCentered(char* title, int w, int h);
int ngbInitWindowAtPosition(char* title, int x, int y, int w, int h);
void ngbInitGraphics(void);
NGBkeyListener* ngbInitKeyListener(NGBboolean altf4);
void ngbUpdateFunc(void(*func)(int));

void ngbMainLoop(void);

#endif