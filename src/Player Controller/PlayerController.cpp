#include "PlayerController.h"

namespace godot
{
    void PlayerController::_ready()
    {
        _gravity = ProjectSettings::get_singleton()->get_setting("physics/2d/default_gravity", 0.0f);

        _animator = get_node<AnimatedSprite2D>("AnimatedSprite2D");
        if (_animator)
            _animator->play("Idle");
        else
            UtilityFunctions::print("There is no AnimatedSprite2D attached on the ", get_name());
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
        flip(horizontalInput);

        // "Flush"
        move_and_slide();
    }

    void PlayerController::jump()
    {
        Vector2 currentVelocity = get_velocity();
        currentVelocity.y = _jumpSpeed;
        set_velocity(currentVelocity);
        _animator->play("Jump");
    }

    void PlayerController::move(const double horizontalInput)
    {
        Vector2 currentVelocity = get_velocity();
        if (horizontalInput)
        {
            currentVelocity.x = horizontalInput * _horizontalSpeed;
            if (currentVelocity.y == 0)
                _animator->play("Walk");
        }
        else
        {
            currentVelocity.x = horizontalInput * _horizontalSpeed;
            _animator->play("Idle");
        }
        set_velocity(currentVelocity);
    }

    void PlayerController::flip(double horizontalInput)
    {
        bool wantToGoLeft = horizontalInput < 0;  // True if the input indicates moving left
        bool wantToGoRight = horizontalInput > 0; // True if the input indicates moving right

        Vector2 scale = get_scale();
        // Check if there's a need to flip based on current facing direction and input direction
        if ((_isFacingRight && wantToGoLeft) || (!_isFacingRight && wantToGoRight))
        {
            scale.x *= -1;                    // Multiply scale.x by -1 to flip while preserving any existing scale factor
            _isFacingRight = !_isFacingRight; // Toggle the facing direction
        }
        set_scale(scale); // Apply the updated scale to the player
    }

    void PlayerController::add_velocity(const real_t deltaX, const real_t deltaY)
    {
        Vector2 currentVelocity = get_velocity();
        currentVelocity.x += deltaX;
        currentVelocity.y += deltaY;
        set_velocity(currentVelocity);
    }

    real_t PlayerController::get_horizontal_speed() const
    {
        return _horizontalSpeed;
    }

    void PlayerController::set_horizontal_speed(const real_t value)
    {
        _horizontalSpeed = value;
    }

    real_t PlayerController::get_jump_speed() const
    {
        return _jumpSpeed;
    }

    void PlayerController::set_jump_speed(const real_t value)
    {
        _jumpSpeed = value;
    }
}