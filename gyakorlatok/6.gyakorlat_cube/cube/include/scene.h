#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"

#include <obj/model.h>

typedef struct Scene
{
    Model cube;
    Model cat;
    Model deer;
    float rotation_speed;
    vec3 rotation;
    Material material;
    GLuint texture_id;
} Scene;

/**
 * Initialize the scene by loading models.
 */
void init_scene(Scene* scene);

/**
 * Set the lighting of the scene.
 */
void set_lighting();

/**
 * Set the current material.
 */
void set_material(const Material* material);

/**
 * Update the scene.
 */
void update_scene(Scene* scene);

/**
 * Render the scene objects.
 */
void render_scene(const Scene* scene);

/**
 * Draw the origin of the world coordinate system.
 */
void draw_origin();

/**
 * Sets the objects rotation speed
*/
void set_obj_rotation(Scene *scene, double speed);

/***
  Update objects rotation.
*/
void update_objects(Scene* scene, double time);


#endif /* SCENE_H */