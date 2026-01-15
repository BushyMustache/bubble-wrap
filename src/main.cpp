#include <bn_core.h>
#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_keypad.h>

int main() {

    bn::core::init();
    bn::backdrop::set_color(bn::color(20,20,20));

    while(true) {
        int red = 0; int green = 0; int blue = 0;

        // Red Screen
        if (bn::keypad::a_pressed()) {
            red = 31;
            bn::backdrop::set_color(bn::color(red,green,blue));
        }

        // Green Screen
        if (bn::keypad::b_pressed()) {
            green = 31;
            bn::backdrop::set_color(bn::color(red,green,blue));
        }

        // Blue Screen
        if (bn::keypad::l_pressed()) {
            blue = 31;
            bn::backdrop::set_color(bn::color(red,green,blue));
        }

        // Default Screen
        if (bn::keypad::r_pressed()) {
            red = 20; green = 20; blue = 20;
            bn::backdrop::set_color(bn::color(red,green,blue));
        }

        // Yellow Screen
        if (bn::keypad::a_pressed() && bn::keypad::b_pressed()) {
            red = 31; green = 31; blue = 0;
            bn::backdrop::set_color(bn::color(red,green,blue));
        }

        // Pink Screen
        if (bn::keypad::a_pressed() && bn::keypad::l_pressed()) {
            red = 31; green = 0; blue = 31;
            bn::backdrop::set_color(bn::color(red,green,blue));
        }

        // Cyan Screen
        if (bn::keypad::b_pressed() && bn::keypad::l_pressed()) {
            red = 0; green = 31; blue = 31;
            bn::backdrop::set_color(bn::color(red,green,blue));
        }

        bn::core::update();
    }
}