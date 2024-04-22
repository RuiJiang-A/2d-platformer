#ifndef ENTRY_CONTROLLER_H
#define ENTRY_CONTROLLER_H

#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/scene_tree.hpp>
#include <godot_cpp/classes/button.hpp>

namespace godot
{
    /**
     * @class EntryController
     * @brief Manages entry screen interactions in a Godot game.
     *
     * This class extends Node2D to manage the main menu interactions,
     * such as responding to button presses for 'Play' and 'Quit'.
     */
    class EntryController : public Node2D
    {
        GDCLASS(EntryController, Node2D)

        Button *btn_quit; ///< Pointer to the quit button.
        Button *btn_play; ///< Pointer to the play button.

    protected:
        /**
         * Binds methods to Godot's scripting API.
         * This allows Godot to call these methods as callbacks when the associated events occur.
         */
        static void _bind_methods()
        {
            ClassDB::bind_method(D_METHOD("_on_button_play_pressed"), &EntryController::_on_button_play_pressed);
            ClassDB::bind_method(D_METHOD("_on_button_quit_pressed"), &EntryController::_on_button_quit_pressed);
        }

    public:
#pragma region "The Big Fives"
        EntryController() : btn_quit(nullptr), btn_play(nullptr) {}
        ~EntryController() = default;
#pragma endregion

#pragma region "Godot Callbacks"
        void _ready();
        void _on_button_play_pressed() const;
        void _on_button_quit_pressed() const;
#pragma endregion
    };
}

#endif