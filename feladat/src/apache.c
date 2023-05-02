#include "apache.h"

void init_apache(Apache *apache)
{
    load_model(&(apache->model), "assets/models/apache.obj");
    apache->texture_id = load_texture("assets/textures/apacheBase.jpg");

    load_model(&(apache->rotor.rotorBack), "assets/models/rotorBack.obj");
    load_model(&(apache->rotor.rotorTop), "assets/models/rotorTop.obj");

    apache->pos.x = 0.0;
    apache->pos.y = 0.0;
    apache->pos.z = 0.0;

    apache->speed.x = 0.0;
    apache->speed.y = 0.0;
    apache->speed.z = 0.0;

    apache->rotor.pos.x = 0.0;
    apache->rotor.pos.y = 0.0;
    apache->rotor.pos.z = 0.0;

    apache->rotor.rotation.x = 0.0;
    apache->rotor.rotation.y = 0.0;
    apache->rotor.rotation.z = 0.0;

    apache->rotor.rotationSpeed.x = 0.0;
    apache->rotor.rotationSpeed.y = 0.0;
    apache->rotor.rotationSpeed.z = 0.0;

    apache->tilt.x = 0.0;
    apache->tilt.y = 0.0;
    apache->tilt.z = 0.0;

    apache->tiltSpeed.x = 0.0;
    apache->tiltSpeed.y = 0.0;
    apache->tiltSpeed.z = 0.0;

    apache->forward = false;
    apache->backward = false;
}

void set_apache_pos(Apache *apache, vec3 newPos)
{
    apache->pos.x += newPos.x;
    apache->pos.y += newPos.y;
    apache->pos.z += newPos.z;
}

void set_apache_speed(Apache *apache, double speed)
{
    apache->speed.y = -speed;
}

void set_apache_side_speed(Apache *apache, double speed)
{
    apache->speed.x = speed;
}

void set_apache_vertical_speed(Apache *apache, double speed)
{
    apache->speed.z = speed;
}

void move_apache(Apache *apache, double time)
{
    apache->pos.x += apache->speed.x * time;
    apache->pos.y += apache->speed.y * time;
    apache->pos.z += apache->speed.z * time;
}

void set_rotorTop_speed(Apache *apache, double speed)
{
    apache->rotor.rotationSpeed.y = speed;
}

void rotate_rotor(Apache *apache, double time)
{
    if (apache->rotor.rotation.z < 0)
    {
        apache->rotor.rotation.z += 360.0;
    }

    if (apache->rotor.rotation.z > 360.0)
    {
        apache->rotor.rotation.z -= 360.0;
    }

    if (apache->rotor.rotation.x < 0)
    {
        apache->rotor.rotation.x += 360.0;
    }

    if (apache->rotor.rotation.x > 360.0)
    {
        apache->rotor.rotation.x -= 360.0;
    }
    apache->rotor.rotation.y += apache->rotor.rotationSpeed.y * time * 50;
    apache->rotor.rotation.x += apache->rotor.rotationSpeed.x * time * 50;
}

void set_rotorBack_speed(Apache *apache, double speed)
{
    apache->rotor.rotationSpeed.x = speed;
}

void set_tilt_speed(Apache* apache, double speed)
{
    apache->tiltSpeed.x = speed;
}

void tilt_apache_forward(Apache *apache, double time, bool tilt)
{
    if (tilt)
    {
        if (apache->tilt.x < 30.0)
        {
            apache->tilt.x += time * apache->tiltSpeed.x * 12;
        }
    }
    else
    {
        if (apache->tilt.x > 0)
        {
            apache->tilt.x -= time * apache->tiltSpeed.x * -12;
        }
    }
}

void tilt_apache_backward(Apache *apache, double time, bool tilt)
{
    if (tilt)
    {
        if (apache->tilt.x > -30.0 && apache->tilt.x <= 0)
        {
            apache->tilt.x += time * apache->tiltSpeed.x * 12;
        }
    }
    else
    {
        if (apache->tilt.x < 0)
        {
            apache->tilt.x -= time * apache->tiltSpeed.x * 12;
        }
    }
    
}