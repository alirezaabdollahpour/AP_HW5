#include "cappuccino.h"
#include "espresso_based.h"
#include "ingredient.h"
#include "mocha.h"
#include "sub_ingredients.h"
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <gtest/gtest.h>
#include <iostream>

#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <iostream>

int main(void)
{
    using namespace ftxui;

    // Define the document
    // Element document = hbox({
    //     text("left") | border,
    //     text("middle") | border | flex,
    //     text("right") | border,
    // });
    Element document = vbox({ text("The window") | bold | color(Color::Blue),
        gauge(0.5)
            text("The footer") });
    // Add a border, by calling the `ftxui::border` decorator function.
    document = border(document);

    // Add another border, using the pipe operator.
    document = document | border.

                          // Add another border, using the |= operator.
                          document
        |= border auto screen = Screen::Create(
            Dimension::Full(), // Width
            Dimension::Fit(document) // Height
        );
    Render(screen, document);
    screen.Print();

    return EXIT_SUCCESS;
}