#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include <godot_cpp/classes/project_settings.hpp>
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/character_body2d.hpp>
#include <godot_cpp/classes/animated_sprite2d.hpp>

namespace godot
{
    class PlayerController : public CharacterBody2D
    {
    private:
        GDCLASS(PlayerController, CharacterBody2D);

        bool _isFacingRight;

        real_t _horizontalSpeed;
        real_t _jumpSpeed;
        real_t _gravity;

        AnimatedSprite2D *_animator;

        void add_gravity(double delta);
        void handle_input();
        void add_velocity(const real_t deltaX, const real_t deltaY);
        void move(const double horizontalInput);
        void flip(const double horizontalInput);
        void jump();

    protected:
        static void _bind_methods()
        {
            // Horizontal Speed
            ClassDB::bind_method(D_METHOD("get_horizontal_speed"), &PlayerController::get_horizontal_speed);
            ClassDB::bind_method(D_METHOD("set_horizontal_speed", "value"), &PlayerController::set_horizontal_speed);
            ClassDB::add_property("PlayerController",
                                  PropertyInfo(Variant::FLOAT, "horizontal speed", PROPERTY_HINT_RANGE, "0,1000,10"), "set_horizontal_speed", "get_horizontal_speed");

            // Jump Speed
            ClassDB::bind_method(D_METHOD("get_jump_speed"), &PlayerController::get_jump_speed);
            ClassDB::bind_method(D_METHOD("set_jump_speed", "value"), &PlayerController::set_jump_speed);
            ClassDB::add_property("PlayerController",
                                  PropertyInfo(Variant::FLOAT, "jump speed", PROPERTY_HINT_RANGE, "-1000,0,10"), "set_jump_speed", "get_jump_speed");
        }

    public:
#pragma region "The Big Fives"
        PlayerController() : _horizontalSpeed(200), _jumpSpeed(-300), _isFacingRight(true){};
        ~PlayerController() = default;
#pragma endregion

#pragma region "Godot Callbacks"
        void _ready();
        void _physics_process(double delta) override;
#pragma endregion

#pragma region "Properties"
        [[nodiscard]] real_t get_horizontal_speed() const;
        void set_horizontal_speed(const real_t value);

        [[nodiscard]] real_t get_jump_speed() const;
        void set_jump_speed(const real_t value);
#pragma endregion
    };
}

#endif