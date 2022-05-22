#include "espresso_based.h"

std::vector<Ingredient*>& EspressoBased::get_ingredients()
{
    return ingredients;
}

EspressoBased::EspressoBased()
    : ingredients {}
    , name {}
{
}

EspressoBased::~EspressoBased()
{
    for (const auto& i : ingredients)
        delete i;
    ingredients.clear();
}

// copy constructor of EspressoBased
EspressoBased::EspressoBased(const EspressoBased& esp)
    : ingredients {}
    , name { esp.name }
{
    for (const auto& i : esp.ingredients) {
        if (i->get_name() == "Suagr")
            ingredients.push_back(new Sugar { i->get_units() });

        if (i->get_name() == "Water")
            ingredients.push_back(new Water { i->get_units() });

        if (i->get_name() == "Cinnamon")
            ingredients.push_back(new Cinnamon { i->get_units() });

        if (i->get_name() == "Espresso")
            ingredients.push_back(new Espresso { i->get_units() });

        if (i->get_name() == "MilkFoam")
            ingredients.push_back(new MilkFoam { i->get_units() });

        if (i->get_name() == "Milk")
            ingredients.push_back(new Milk { i->get_units() });

        if (i->get_name() == "Cookie")
            ingredients.push_back(new Cookie { i->get_units() });

        if (i->get_name() == "Chocolate")
            ingredients.push_back(new Chocolate { i->get_units() });
    }
}

// operator= for EspressoBased
void EspressoBased::operator=(const EspressoBased& esp)
{
    for (auto& i : ingredients)
        delete i;
    ingredients.clear();

    for (const auto& i : esp.ingredients) {
        if (i->get_name() == "Suagr")
            ingredients.push_back(new Sugar { i->get_units() });

        if (i->get_name() == "Water")
            ingredients.push_back(new Water { i->get_units() });

        if (i->get_name() == "Cinnamon")
            ingredients.push_back(new Cinnamon { i->get_units() });

        if (i->get_name() == "Espresso")
            ingredients.push_back(new Espresso { i->get_units() });

        if (i->get_name() == "MilkFoam")
            ingredients.push_back(new MilkFoam { i->get_units() });

        if (i->get_name() == "Milk")
            ingredients.push_back(new Milk { i->get_units() });

        if (i->get_name() == "Cookie")
            ingredients.push_back(new Cookie { i->get_units() });

        if (i->get_name() == "Chocolate")
            ingredients.push_back(new Chocolate { i->get_units() });
    }
}

void EspressoBased::brew()
{

    using namespace std::chrono_literals;
    int iterator { 0 };
    auto title = ftxui::vbox({ ftxui::text(" Dear Customer!,your" + this->get_name() + " is brewing :") | ftxui::borderDouble
        | ftxui::color(ftxui::Color::RedLight) });
    auto title_screen = ftxui::Screen::Create(ftxui::Dimension::Fit(title), ftxui::Dimension::Fit(title));
    ftxui::Render(title_screen, title);
    title_screen.Print();
    std::cout << std::endl;

    auto sp = ftxui::spinner(21, iterator) | ftxui::bold | ftxui::color(ftxui::Color::BlueLight);
    auto document = ftxui::vbox(std::move(sp)) | ftxui::center;
    auto screen = ftxui::Screen::Create(ftxui::Dimension::Full(), ftxui::Dimension::Fit(document));
    Render(screen, document);
    screen.Print();

    for (const auto& i : ingredients) {
        iterator++;
        ftxui::Element document = ftxui::hbox({ ftxui::text(std::to_string(iterator) + "." + "brewing " + i->get_name() + " for " + std::to_string(i->get_units()) + " units") | ftxui::border | ftxui::color(ftxui::Color::RedLight) });

        auto screen1 = ftxui::Screen::Create(
            ftxui::Dimension::Full(),
            ftxui::Dimension::Fit(document));
        ftxui::Render(screen1, document);
        screen1.Print();
        std::string reset_position;
        for (float percentage = 0.0; percentage <= 1.01f; percentage += 0.01f) {
            std::string brewed = std::to_string(int(percentage * 100)) + "/100";
            auto gauge_document = ftxui::hbox({
                ftxui::text("brewing: ") | ftxui::color(ftxui::Color::Magenta),
                ftxui::gauge(percentage) | ftxui::flex | ftxui::color(ftxui::Color::Magenta),
                ftxui::text(" " + brewed) | ftxui::color(ftxui::Color::Magenta),
            });
            auto gauge_screen = ftxui::Screen(100, 1);
            ftxui::Render(gauge_screen, gauge_document);
            std::cout << reset_position;
            gauge_screen.Print();
            reset_position = gauge_screen.ResetPosition();
            // screen.Print();
            std::this_thread::sleep_for(i->get_units() * 0.01s);
        }
        std::cout << std::endl;
    }
    // auto footer = ftxui::vbox({ ftxui::text(" Your " + this->get_name() + " is brewed ") | ftxui::borderDouble
    //     | ftxui::color(ftxui::Color::MagentaLight) });
    // auto footer_screen = ftxui::Screen::Create(ftxui::Dimension::Fit(footer), ftxui::Dimension::Fit(footer));
    // ftxui::Render(footer_screen, footer);
    // footer_screen.Print();

    for (int index = 0; index < 50; ++index) {
        std::string reset_position;
        std::random_device seeder;
        std::default_random_engine red { seeder() };
        std::default_random_engine green { seeder() };
        std::default_random_engine blue { seeder() };

        // std::uniform_int_distribution<int> distribution(100, 255);
        // auto R { distribution(red) };

        auto x = ftxui::spinner(21, index) | ftxui::bold | ftxui::color(ftxui::Color::BlueLight);
        auto document = ftxui::vbox(std::move(x)) | ftxui::center;
        auto screen = ftxui::Screen::Create(ftxui::Dimension::Full(), ftxui::Dimension::Fit(document));
        Render(screen, document);
        std::cout << reset_position;
        screen.Print();
        reset_position = screen.ResetPosition();
        std::this_thread::sleep_for(0.1s);
    }

    ftxui::Element document1 = ftxui::hbox({ ftxui::text("your coffe is ready!") | ftxui::border | ftxui::color(ftxui::Color::RedLight) });
    auto screen3 = ftxui::Screen::Create(
        ftxui::Dimension::Full(),
        ftxui::Dimension::Fit(document1));
    ftxui::Render(screen3, document1);
    screen3.Print();
    std::this_thread::sleep_for(0.1s);
}