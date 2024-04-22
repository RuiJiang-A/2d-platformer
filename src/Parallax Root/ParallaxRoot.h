#ifndef PARALLAX_ROOT_CONTROLLER_H
#define PARALLAX_ROOT_CONTROLLER_H

#include <godot_cpp/classes/parallax_background.hpp>

namespace godot
{
    /**
     * @class ParallaxRoot
     * @brief Extends ParallaxBackground to control scrolling speed.
     *
     * ParallaxRoot class provides mechanisms to control the scrolling speed of a parallax background
     * in a Godot application. It inherits from ParallaxBackground.
     */
    class ParallaxRoot : public ParallaxBackground
    {
        GDCLASS(ParallaxRoot, ParallaxBackground);

        real_t _scrollSpeed; ///< Internal storage for the scrolling speed.

    protected:
        /**
         * Binds methods for accessing and modifying properties.
         * This method binds the getter and setter for the scroll speed property,
         * making it accessible and modifiable in the Godot editor and scripts.
         */
        static void _bind_methods()
        {
            // Scroll Speed
            ClassDB::bind_method(D_METHOD("get_scroll_speed"), &ParallaxRoot::get_scroll_speed);
            ClassDB::bind_method(D_METHOD("set_scroll_speed", "value"), &ParallaxRoot::set_scroll_speed);
            ClassDB::add_property("ParallaxRoot",
                                  PropertyInfo(Variant::FLOAT, "scroll speed", PROPERTY_HINT_RANGE, "0,100,1"), "set_scroll_speed", "get_scroll_speed");
        }

#pragma region "The Big Fives"
        ParallaxRoot() : _scrollSpeed(20) {}
        ~ParallaxRoot() = default;
#pragma endregion

#pragma region "Godot Callbacks"
    public:
        void _process(double delta) override;
#pragma endregion

#pragma region "Properties"
        [[nodiscard]] real_t get_scroll_speed() const;
        void set_scroll_speed(const real_t value);
#pragma endregion
    }; // namespace godot
}
#endif // PARALLAX_ROOT_CONTROLLER_H