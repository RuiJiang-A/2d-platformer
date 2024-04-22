#include "Collectible.h"

namespace godot
{
    void Collectible::_ready()
    {
        this->connect("body_entered", Callable(this, "_on_body_entered"));

        _animator = get_node<AnimatedSprite2D>("AnimatedSprite2D");
        if (_animator)
            _animator->play("Idle");
        else
            UtilityFunctions::print("There is no AnimatedSprite2D attached on the ", get_name());
    }

    void Collectible::_on_body_entered(const Node2D *body)
    {
        StringName playerName = "Player Controller";
        if (body->get_name() == playerName)
            queue_free();
    }

}