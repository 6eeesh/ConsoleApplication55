#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Ability {
public:
    virtual void use() const = 0;
    virtual ~Ability() = default;
};

class Flight : public Ability {
public:
    void use() const override {
        cout << "Літання\n";
    }
};

class SuperStrength : public Ability {
public:
    void use() const override {
        cout << "Суперсила\n";
    }
};

class Good {
public:
    virtual void doGood() const = 0;
    virtual ~Good() = default;
};

class Evil {
public:
    virtual void doEvil() const = 0;
    virtual ~Evil() = default;
};

class SuperHero : public Good, public Evil {
protected:
    string race;
    vector<unique_ptr<Ability>> abilities;

public:
    SuperHero(const string& race) : race(race) {}

    void addAbility(unique_ptr<Ability> ability) {
        abilities.push_back(move(ability));
    }

    void doGood() const override {
        cout << "Виконую добро!\n";
    }

    void doEvil() const override {
        cout << "Виконую зло!\n";
    }

    void showAbilities() const {
        cout << "Мої здібності:\n";
        for (const auto& ability : abilities) {
            ability->use();
        }
    }

    virtual ~SuperHero() = default;
};

class Mystique : public SuperHero {
public:
    Mystique() : SuperHero("Мутант") {
        addAbility(make_unique<Flight>());
        addAbility(make_unique<SuperStrength>());
    }
};

int main() {
    setlocale (LC_ALL, "");
    Mystique mystique;
    mystique.doGood();
    mystique.showAbilities();

    return 0;
}
