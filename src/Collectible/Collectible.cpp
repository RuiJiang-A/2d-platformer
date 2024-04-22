#include "Collectible.h"

namespace godot
{
    /**
     * Initializes the collectible by setting up the animation and connecting signals.
     * This method retrieves and starts the animation, and connects the body_entered signal to handle collection.
     */
    void Collectible::_ready()
    {
        this->connect("body_entered", Callable(this, "_on_body_entered"));

        _animator = get_node<AnimatedSprite2D>("AnimatedSprite2D");
        if (_animator)
            _animator->play("Idle");
        else
            UtilityFunctions::print("There is no AnimatedSprite2D attached on the ", get_name());
    }

    /**
     * Handles interaction when a body enters the collectible's area.
     * It checks if the entering body is the player and if so, frees the collectible.
     *
     * @param body The node representing the body that entered the collectible.
     */
    void Collectible::_on_body_entered(const Node2D *body)
    {
        StringName playerName = "Player Controller";
        if (body->get_name() == playerName)
            queue_free();
    }

}