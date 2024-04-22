#ifndef CPPSCRIPT_REGISTER_TYPES_H
#define CPPSCRIPT_REGISTER_TYPES_H

#include <godot_cpp/core/class_db.hpp>

namespace godot
{
    void initialize_module(ModuleInitializationLevel p_level);
    void uninitialize_module(ModuleInitializationLevel p_level);
}
#endif // GDEXAMPLE_REGISTER_TYPES_H