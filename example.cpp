#include "include/typecode.hpp"

int main() noexcept {
    std::string x = "$%///*++;%////*++;///++++;///*++;///*+++;-%////*;$@/*+;+++;///;@";

    TypeCode q;

    q.init(x);

    std::cout << "\x1b[0;93mLanguages\x1b[0m:\n";
    for(auto& languages : q.info_languages) {
        std::cout << "  " + languages << '\n';
    } std::cout << "\n\x1b[0;92mBranches\x1b[0m:\n";
    for(auto& branches : q.info_branches) {
        std::cout << "  " + branches << '\n';
    }
}