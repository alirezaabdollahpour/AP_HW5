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

// int main(void)
// {
//     using namespace ftxui;

//     // Define the document
//     // Element document = hbox({
//     //     text("left") | border,
//     //     text("middle") | border | flex,
//     //     text("right") | border,
//     // });
//     Element document = vbox({ text("The window") | bold | color(Color::Blue),
//         gauge(0.5)
//             text("The footer") });

//     // Add a border, by calling the `ftxui::border` decorator function.
//     document = border(document);

//     // Add another border, using the pipe operator.
//     document = document | border.

//                           // Add another border, using the |= operator.
//                           document
//         |= border
//             Render(screen, document);
//     screen.Print();

//     return EXIT_SUCCESS;
// }

int main(int argc, char** argv)
{
    if (false) // make false to run unit-tests
    {
        // debug section

    } else {
        ::testing::InitGoogleTest(&argc, argv);
        std::cout << "RUNNING TESTS ..." << std::endl;
        int ret { RUN_ALL_TESTS() };
        if (!ret)
            std::cout << "<<<SUCCESS>>>" << std::endl;
        else
            std::cout << "FAILED" << std::endl;
    }
    return 0;
}