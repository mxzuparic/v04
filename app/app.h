#pragma once
#include <string>
#include <memory>

namespace vsite::oop::v4
{
    class animal {
    public:
        virtual ~animal() = default;
        virtual std::string species() const = 0;
        virtual unsigned legs() const = 0;
    };

    class insect : public animal {
    public:
        unsigned legs() const override { return 6; }
    };

    class spider : public animal {
    public:
        unsigned legs() const override { return 8; }
    };

    class bird : public animal {
    public:
        unsigned legs() const override { return 2; }
    };

    class cockroach : public insect {
    public:
        std::string species() const override;
    };

    class tarantula : public spider {
    public:
        std::string species() const override;
    };

    class sparrow : public bird {
    public:
        std::string species() const override;
    };

    class leg_counter {
        unsigned total_legs = 0;
    public:
        std::string add_animal(animal* a);
        unsigned legs() const;
    };

    std::shared_ptr<animal> animal_factory(int code);
}