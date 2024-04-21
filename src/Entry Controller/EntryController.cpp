#include "EntryController.h"

namespace godot
{
    void EntryController::_ready()
    {
        btn_quit = get_node<Button>("Button_Quit");
        if (btn_quit != nullptr)
            btn_quit->connect("pressed", Callable(this, "_on_button_quit_pressed"));

        btn_play = get_node<Button>("Button_Play");
        if (btn_play != nullptr)
            btn_play->connect("pressed", Callable(this, "_on_button_play_pressed"));
    }

    void EntryController::_on_button_play_pressed() const
    {
        get_tree()->change_scene_to_file("res://scenes/level_1.tscn");
    }

    void EntryController::_on_button_quit_pressed() const
    {
        get_tree()->quit();
    }

} // namespace godot
