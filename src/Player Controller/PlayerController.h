#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include <godot_cpp/classes/project_settings.hpp>
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/character_body2d.hpp>

namespace godot
{
    class PlayerController : public CharacterBody2D
    {
    private:
        GDCLASS(PlayerController, CharacterBody2D);

        real_t _horizontalSpeed;
        real_t _jumpSpeed;
        real_t _gravity;

        void add_gravity(double delta);
        void handle_input();
        void add_velocity(const real_t deltaX, const real_t deltaY);
        void move(const double horizontalInput);
        void jump();

    protected:
        static void _bind_methods()
        {
        }

    public:
        PlayerController() : _horizontalSpeed(200), _jumpSpeed(-200){};
        ~PlayerController() = default;

        void _ready();
        void _physics_process(double delta) override;
    };
}

#endif