#include <bn_core.h>
#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_keypad.h>

int main() {

    bn::core::init();
    bn::backdrop::set_color(bn::color(31,20,20));

    while(true) {

        if (bn::keypad::a_pressed()) {
            bn::backdrop::set_color(bn::color(21,31,22));
        }

        if (bn::keypad::b_pressed()) {
            bn::backdrop::set_color(bn::color(25,20,31));
        }

        if (bn::keypad::a_pressed() && bn::keypad::b_pressed()) {
            bn::backdrop::set_color(bn::color(0,31,31));
        }

        bn::core::update();
    }
}