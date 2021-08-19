#include "include/typecode.hpp"

int main() noexcept {
    std::string x = "$%///*++;%////*++;///++++;///*++;///*+++;-%////*;$@/*+;+++;///;@?%++;?";

    TypeCode q;

    q.init(x);

    std::cout << "\x1b[0;93mLanguages\x1b[0m:\n";
    for(auto& language : q.info_languages) {
        std::cout << "  " + language << '\n';
    } std::cout << "\n\x1b[0;92mBranches\x1b[0m:\n";
    for(auto& branch : q.info_branches) {
        std::cout << "  " + branch << '\n';
    } std::cout << "\n\x1b[0;92mOperating Systems\x1b[0m:\n";
    for(auto& os : q.info_operating_systems) {
        std::cout << "  " + os << '\n';
    }
}