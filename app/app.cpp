#include "app.h"
#include <algorithm>

namespace vsite::oop::v4
{
    std::string cockroach::species() const { return "cockroach"; }
    unsigned cockroach::legs() const { return 6; }

    std::string tarantula::species() const { return "tarantula"; }
    unsigned tarantula::legs() const { return 8; }

    std::string sparrow::species() const { return "sparrow"; }
    unsigned sparrow::legs() const { return 2; }

    std::string leg_counter::add_animal(animal* a) {
        total_legs += a->legs();
        return a->species();
    }

    unsigned leg_counter::legs() const {
        return total_legs;
    }

    std::shared_ptr<animal> animal_factory(int code) {
        switch (code) {
        case 1: return std::make_shared<cockroach>();
        case 2: return std::make_shared<sparrow>();
        case 3: return std::make_shared<tarantula>();
        default: return nullptr;
        }
    }

}