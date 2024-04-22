#include "PlayerController.h"

namespace godot
{
    void PlayerController::_ready()
    {
        UtilityFunctions::print("Player ready");
        _gravity = ProjectSettings::get_singleton()->get_setting("physics/2d/default_gravity", 0.0f);
        UtilityFunctions::print("Current gravity: ", _gravity);
    }

    void PlayerController::_physics_process(double delta)
    {
        add_gravity(delta);
        handle_input();
    }

    void PlayerController::add_gravity(const double delta)
    {
        if (is_on_floor())
            return;

        add_velocity(0, _gravity * delta);
        UtilityFunctions::print("Current Velocity ", get_velocity());
    }

    void PlayerController::handle_input()
    {
        // Handle Jump
        bool jumpButtonPressed = Input::get_singleton()->is_action_just_pressed("ui_accept");
        if (jumpButtonPressed && is_on_floor())
            jump();

        // Handle Horizontal Movement
        double horizontalInput = Input::get_singleton()->get_axis("ui_left", "ui_right");
        move(horizontalInput);

        // "Flush"
        move_and_slide();
    }

    void PlayerController::jump()
    {
        Vector2 currentVelocity = get_velocity();
        currentVelocity.y = _jumpSpeed;
        set_velocity(currentVelocity);
    }

    void PlayerController::move(const double horizontalInput)
    {
        Vector2 currentVelocity = get_velocity();
        if (horizontalInput)
            currentVelocity.x = horizontalInput * _horizontalSpeed;
        else
            currentVelocity.x = horizontalInput * _horizontalSpeed;
        set_velocity(currentVelocity);
    }

    void PlayerController::add_velocity(const real_t deltaX, const real_t deltaY)
    {
        Vector2 currentVelocity = get_velocity();
        currentVelocity.x += deltaX;
        currentVelocity.y += deltaY;
        set_velocity(currentVelocity);
    }

}