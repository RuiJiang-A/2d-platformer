#include "EntryController.h"

namespace godot
{
    /**
     * Prepares the entry screen by setting up button interactions.
     * This method connects the 'pressed' signal of the buttons to their respective handler methods.
     */
    void EntryController::_ready()
    {
        btn_quit = get_node<Button>("Button_Quit");
        if (btn_quit != nullptr)
            btn_quit->connect("pressed", Callable(this, "_on_button_quit_pressed"));

        btn_play = get_node<Button>("Button_Play");
        if (btn_play != nullptr)
            btn_play->connect("pressed", Callable(this, "_on_button_play_pressed"));
    }

    /**
     * Handles the press event of the play button.
     * This method changes the current scene to the first level of the game.
     */
    void EntryController::_on_button_play_pressed() const
    {
        get_tree()->change_scene_to_file("res://scenes/level_1.tscn");
    }

    /**
     * Handles the press event of the quit button.
     * This method triggers the application to close.
     */
    void EntryController::_on_button_quit_pressed() const
    {
        get_tree()->quit();
    }

} // namespace godot
