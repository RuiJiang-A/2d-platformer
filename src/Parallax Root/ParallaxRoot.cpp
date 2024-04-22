#include "ParallaxRoot.h"

namespace godot
{
    /**
     * Processes frame updates for parallax scrolling.
     * This method updates the scroll offset based on the scroll speed and the frame's delta time.
     *
     * @param delta Time elapsed since the last frame in seconds.
     */
    void ParallaxRoot::_process(double delta)
    {
        // Update scroll offset x
        Vector2 scrollOffset = get_scroll_offset();
        scrollOffset.x -= _scrollSpeed * delta;
        set_scroll_offset(scrollOffset);
    }

    /**
     * Retrieves the current scrolling speed of the parallax background.
     *
     * @return Current scroll speed as a real number.
     */
    real_t ParallaxRoot::get_scroll_speed() const
    {
        return _scrollSpeed;
    }

    /**
     * Sets the scrolling speed of the parallax background.
     * This method updates the internal scroll speed to the provided value.
     *
     * @param value The new scroll speed to set.
     */
    void ParallaxRoot::set_scroll_speed(real_t value)
    {
        _scrollSpeed = value;
    }

} // namespace godot