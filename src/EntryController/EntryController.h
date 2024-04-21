#ifndef ENTRY_CONTROLLER_H
#define ENTRY_CONTROLLER_H

#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/scene_tree.hpp>
#include <godot_cpp/classes/button.hpp>

namespace godot
{
    class EntryController : public Node2D
    {
        GDCLASS(EntryController, Node2D)

        Button *button = nullptr;

    protected:
        static void _bind_methods()
        {
            ClassDB::bind_method(D_METHOD("_on_button_quit_pressed"), &EntryController::_on_button_quit_pressed);
        }

    public:
        EntryController() = default;
        ~EntryController() = default;

        void _ready();
        void _on_button_quit_pressed() const;
    };
}

#endif