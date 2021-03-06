#include "pixel.h"

/* Structures */
typedef struct
{
    double x;
    double y;
    double z;
} Vector;

/* Ray of 'light' */
typedef struct
{
    Vector position;
    Vector direction;
} Ray;

typedef struct
{
    Vector position;
    double intensity;
} Light;

/* Enumertions for different entity types
 * maybe extend beyond spheres in the future?
 */
enum t_object
{
    t_null, //No object assigned
    t_sphere,
    t_plane
};

typedef struct
{
    int r;
    int g;
    int b;
} Color;

typedef struct
{
    enum t_object type;
    void *object;
    Color color;
    double reflection;
    double transparency;
} Object;

typedef struct
{
    Vector position;
    double radius;
} Sphere;

typedef struct
{
    //Distance from origo
    Vector position;
    //Orientation
    Vector normal;
} Plane;

/* Components of a scene */
typedef struct
{
    int screenX;
    int screenY;

    int fov;

    Vector cameraPosition;
    Vector cameraDirection;

    int lightCount;
    Light *lights;

    int objectCount;
    Object *objects;

} Scene;

void rt_initScene();
void rt_printScene();
void rt_setCameraPosition();
void rt_setCameraDirection();
void rt_setLightCount(int count);
void rt_setObjectCount(int count);
void rt_cleanup();
void rt_setLight(int num, Light *light);
void rt_setObject(int num, Object *obj);
void rt_setResolution(int w, int h);
void rt_setFov(int fov);

void rt_vectorSubstract(Vector *v1, Vector *v2, Vector *result);
void rt_vectorAdd(Vector *v1, Vector *v2, Vector *result);
void rt_vectorMultiply(Vector *v1, double scalar, Vector *result);
double rt_dotProduct(Vector *v1, Vector *v2);
void rt_vectorNormalize(Vector *v,Vector *result);
double rt_vectorLength(Vector *v);

void rt_surfaceNormal(Object *object, Vector *pointHit, Vector *normalHit);
double rt_intersect(Ray *ray,Object *object);
double rt_illumination(Vector *pointHit, Vector *normalHit);
Color rt_trace(Ray *ray, int recursions);
void rt_renderScene(Pixel *pixels);
