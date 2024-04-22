
#ifndef COLLECTIBLE_CONTROLLER_H
#define COLLECTIBLE_CONTROLLER_H

#include <godot_cpp/classes/area2d.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/animated_sprite2d.hpp>

namespace godot
{
    class Collectible : public Area2D
    {
    private:
        GDCLASS(Collectible, Area2D)

        AnimatedSprite2D *_animator;

    protected:
        static void _bind_methods()
        {
            ClassDB::bind_method(D_METHOD("_on_body_entered", "body"), &Collectible::_on_body_entered);
        }

    public:
        Collectible() : _animator(nullptr){};
        ~Collectible() = default;

        void _ready();
        void _on_body_entered(const Node2D *body);
    };
}
#endif