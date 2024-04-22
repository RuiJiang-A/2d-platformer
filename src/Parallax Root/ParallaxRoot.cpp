#include "ParallaxRoot.h"

namespace godot
{
    void ParallaxRoot::_process(double delta)
    {
        // Update scroll offset x
        Vector2 scrollOffset = get_scroll_offset();
        scrollOffset.x -= _scrollSpeed * delta;
        set_scroll_offset(scrollOffset);
    }

    real_t ParallaxRoot::get_scroll_speed() const
    {
        return _scrollSpeed;
    }

    void ParallaxRoot::set_scroll_speed(real_t value)
    {
        _scrollSpeed = value;
    }

}