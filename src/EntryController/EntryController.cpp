#include "EntryController.h"

namespace godot
{
    void EntryController::_ready()
    {
        button = get_node<Button>("Button_Quit");
        if (button == nullptr)
            return;

        button->connect("pressed", Callable(this, "_on_button_quit_pressed"));
    }

    void EntryController::_on_button_quit_pressed() const
    {
        get_tree()->quit();
    }

} // namespace godot
