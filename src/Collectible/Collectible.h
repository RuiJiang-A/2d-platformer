
#ifndef COLLECTIBLE_CONTROLLER_H
#define COLLECTIBLE_CONTROLLER_H

#include <godot_cpp/classes/area2d.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/animated_sprite2d.hpp>

namespace godot
{
    /**
     * @class Collectible
     * @brief Represents a collectible item in a game that uses an Area2D for interaction detection.
     *
     * This class extends Area2D to manage collectible items in the game,
     * such as coins or power-ups, which can be collected by the player.
     */
    class Collectible : public Area2D
    {
    private:
        GDCLASS(Collectible, Area2D)

        AnimatedSprite2D *_animator; ///< Pointer to the animated sprite component of the collectible.

    protected:
        /**
         * Binds Godot methods to this class.
         * It specifically binds the body_entered signal to the _on_body_entered method.
         */
        static void _bind_methods()
        {
            ClassDB::bind_method(D_METHOD("_on_body_entered", "body"), &Collectible::_on_body_entered);
        }

    public:
#pragma region "The Big Fives"
        Collectible() : _animator(nullptr){};
        ~Collectible() = default;
#pragma endregion

#pragma region "Godot Callbacks"
        void _ready();
        void _on_body_entered(const Node2D *body);
    };
#pragma endregion
}
#endif