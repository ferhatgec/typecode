// MIT License
//
// Copyright (c) 2021 Ferhat Geçdoğan All Rights Reserved.
// Distributed under the terms of the MIT License.
//

#include "include/typecode.hpp"

int main(int argc, char** argv) noexcept {
    if(argc < 2) {
        std::cout << "typecode - create unique code that introduce yourself\n"
                     "\n"
                     "Usage:\n" <<
                     argv[0] << " {typecode}\n";

        return 1;
    }

    std::string x = std::string(argv[1]);
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