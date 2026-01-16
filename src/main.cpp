#include <bn_core.h>
#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_keypad.h>
#include <bn_sprite_ptr.h>
#include <bn_sprite_items_dot.h>
#include <bn_log.h>
#include <bn_vector.h>

int main() {

    bn::core::init();
    bn::backdrop::set_color(bn::color(20,20,20));

    bn::vector<bn::sprite_ptr, 40> circles = {};

    /*  TOP OF SQUARE   */
    for (int x = -50; x <= 50; x += 10) {
        bn::sprite_ptr myCircle = bn::sprite_items::dot.create_sprite(x, -30);
        BN_LOG("top value", x);
        circles.push_back(myCircle);
    }

    /*  LEFT OF SQUARE  */
    for (int y = -20; y <= 20; y += 10) {
        bn::sprite_ptr myCircle = bn::sprite_items::dot.create_sprite(-50, y);
        BN_LOG("left value", y);
        circles.push_back(myCircle);
    }

    /*  RIGHT OF SQUARE  */
    for (int y = -20; y <= 20; y += 10) {
        bn::sprite_ptr myCircle = bn::sprite_items::dot.create_sprite(50, y);
        BN_LOG("right value", y);
        circles.push_back(myCircle);
    }

    /*  BOTTOM OF SQUARE  */   
    for (int x = -50; x <= 50; x += 10) {
        bn::sprite_ptr myCircle = bn::sprite_items::dot.create_sprite(x, 30);
        BN_LOG("bottom value", x);
        circles.push_back(myCircle);
    }

    /*  EYES  */
    bn::sprite_ptr myCircle1 = bn::sprite_items::dot.create_sprite(-30, -10);
    bn::sprite_ptr myCircle2 = bn::sprite_items::dot.create_sprite(30, -10);

    /*  SMILE  */
    bn::sprite_ptr myCircle3 = bn::sprite_items::dot.create_sprite(-30, 10);
    bn::sprite_ptr myCircle4 = bn::sprite_items::dot.create_sprite(-20, 10);
    bn::sprite_ptr myCircle5 = bn::sprite_items::dot.create_sprite(-10, 10);
    bn::sprite_ptr myCircle6 = bn::sprite_items::dot.create_sprite(0, 10);
    bn::sprite_ptr myCircle7 = bn::sprite_items::dot.create_sprite(10, 10);
    bn::sprite_ptr myCircle8 = bn::sprite_items::dot.create_sprite(20, 10);
    bn::sprite_ptr myCircle9 = bn::sprite_items::dot.create_sprite(30, 10);

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

        // Orange Screen
        if (bn::keypad::a_pressed() && bn::keypad::b_pressed()) {
            red = 31; green = 20; blue = 0;
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