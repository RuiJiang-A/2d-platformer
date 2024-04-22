#include "register_types.h"

#include "./Entry Controller/EntryController.h"
#include "./Player Controller/PlayerController.h"
#include "./Parallax Root/ParallaxRoot.h"

#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

namespace godot
{
    void initialize_module(ModuleInitializationLevel p_level)
    {
        if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE)
        {
            return;
        }
        ClassDB::register_class<EntryController>();
        ClassDB::register_class<PlayerController>();
        ClassDB::register_class<ParallaxRoot>();
    }

    void uninitialize_module(ModuleInitializationLevel p_level)
    {
        if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE)
        {
            return;
        }
    }

    extern "C"
    {
        // Initialization.
        GDExtensionBool GDE_EXPORT cppscript_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, const GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization)
        {
            godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

            init_obj.register_initializer(initialize_module);
            init_obj.register_terminator(uninitialize_module);
            init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

            return init_obj.init();
        }
    }
}