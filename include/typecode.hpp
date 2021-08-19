// MIT License
//
// Copyright (c) 2021 Ferhat Geçdoğan All Rights Reserved.
// Distributed under the terms of the MIT License.
//
// TypeCode - An interpreter that introduces you.
//
// An example code:
//  $%///*++;%////*++;///++++;///*++;///*+++;-%////*;$@/*+;+++;///;@
//
// Output:
//  Languages:
//      FlaScript
//      Gretea
//      C
//      C++
//      C++/CLI
//      Python
//
//  Branches:
//      Computer Science
//      Programming languages
//      Programming languages and compilers
//

#ifndef TYPECODE_TYPECODE_HPP
#define TYPECODE_TYPECODE_HPP

#include <iostream>
#include <vector>

enum Tokens : char {
    Lang = '$',
    Branch = '@',
    Push = '+',
    Push5 = '*',
    Push10 = '/',
    Push50 = '%',
    Push100 = '-',
    Print = ';'
};

class TypeCode {
    // taken from https://dzone.com/articles/big-list-256-programming
    std::vector<std::string> languages;

    // taken from https://www.quora.com/What-are-the-branches-of-computer-science
    std::vector<std::string> branches;

    std::string data;

    bool is_language, is_branch;

    unsigned stack;
public:
    std::vector<std::string> info_languages;
    std::vector<std::string> info_branches;
public:
    TypeCode() = default;
    ~TypeCode()= default;

    void init(const std::string file_data) noexcept {
        this->init_languages();
        this->init_branches();

        for(auto& ch : file_data) {
            // $+++++++;+++;$
            //
            // @+++++++++++++++;@

            switch(ch) {
                case Lang: {
                    this->is_language = !this->is_language;
                    break;
                }

                case Branch: {
                    this->is_branch = !this->is_branch;
                    break;
                }

                case Push: {
                    ++this->stack;
                    break;
                }

                case Push5: {
                    this->stack += 5;
                    break;
                }

                case Push10: {
                    this->stack += 10;
                    break;
                }

                case Push50: {
                    this->stack += 50;
                    break;
                }

                case Push100: {
                    this->stack += 100;
                    break;
                }

                case Print: {
                    if(this->is_branch && this->stack < this->branches.size()) {
                        this->info_branches.push_back(this->branches[this->stack]);
                    } else if(this->is_language && this->stack < this->languages.size()) {
                        this->info_languages.push_back(this->languages[this->stack]);
                    } this->stack = 0;
                    break;
                }
            }
        }
    }

    void init_languages() noexcept {
        this->languages = {
            "4th Dimension/4D",
            "ABAP",
            "ABC",
            "ActionScript",
            "Ada",
            "Agilent VEE",
            "Algol",
            "Alice",
            "Angelscript",
            "Apex",
            "APL",
            "AppleScript",
            "Arc",
            "Arduino",
            "ASP",
            "AspectJ",
            "Assembly",
            "ATLAS",
            "Augeas",
            "AutoHotkey",
            "AutoIt",
            "AutoLISP",
            "Automator",
            "Avenue",
            "Awk",
            "Bash",
            "(Visual) Basic",
            "bc",
            "BCPL",
            "BETA",
            "BlitzMax",
            "Boo",
            "Bourne Shell",
            "Bro",
            "C",
            "C Shell",
            "C#",
            "C++",
            "C++/CLI",
            "C-Omega",
            "Caml",
            "Ceylon",
            "CFML",
            "cg",
            "Ch",
            "CHILL",
            "CIL",
            "CL (OS/400)",
            "Clarion",
            "Clean",
            "Clipper",
            "Clojure",
            "CLU",
            "COBOL",
            "Cobra",
            "CoffeeScript",
            "ColdFusion",
            "COMAL",
            "Common Lisp",
            "Coq",
            "cT",
            "Curl",
            "D",
            "Dart",
            "DCL",
            "DCPU-16 ASM",
            "Delphi/Object Pascal",
            "DiBOL",
            "Dylan",
            "E",
            "eC",
            "Ecl",
            "ECMAScript",
            "EGL",
            "Eiffel",
            "Elixir",
            "Emacs Lisp",
            "Erlang",
            "Etoys",
            "Euphoria",
            "EXEC",
            "F#",
            "Factor",
            "Falcon",
            "Fancy",
            "Fantom",
            "Felix",
            "FlaScript",
            "Forth",
            "Fortran",
            "Fortress",
            "(Visual) FoxPro",
            "Gambas",
            "GNU Octave",
            "Go",
            "Google AppsScript",
            "Gosu",
            "Gretea",
            "Groovy",
            "Haskell",
            "haXe",
            "Heron",
            "HPL",
            "HyperTalk",
            "Icon",
            "IDL",
            "Inform",
            "Informix-4GL",
            "INTERCAL",
            "Io",
            "Ioke",
            "J",
            "J#",
            "JADE",
            "Java",
            "Java FX Script",
            "JavaScript",
            "JScript",
            "JScript.NET",
            "Julia",
            "Korn Shell",
            "Kotlin",
            "LabVIEW",
            "Ladder Logic",
            "Lasso",
            "Limbo",
            "Lingo",
            "Lisp",
            "Logo",
            "Logtalk",
            "LotusScript",
            "LPC",
            "Lua",
            "Lustre",
            "M4",
            "MAD",
            "Magic",
            "Magik",
            "Malbolge",
            "MANTIS",
            "Maple",
            "Mathematica",
            "MATLAB",
            "Max/MSP",
            "MAXScript",
            "MEL",
            "Mercury",
            "Mirah",
            "Miva",
            "ML",
            "Monkey",
            "Modula-2",
            "Modula-3",
            "MOO",
            "Moto",
            "MS-DOS Batch",
            "MUMPS",
            "NATURAL",
            "Nemerle",
            "Nim",
            "NQC",
            "NSIS",
            "Nu",
            "NXT-G",
            "Oberon",
            "Object Rexx",
            "Objective-C",
            "Objective-J",
            "OCaml",
            "Occam",
            "ooc",
            "Opa",
            "OpenCL",
            "OpenEdge ABL",
            "OPL",
            "Oz",
            "Paradox",
            "Parrot",
            "Pascal",
            "Perl",
            "PHP",
            "Pike",
            "PILOT",
            "PL/I",
            "PL/SQL",
            "Pliant",
            "PostScript",
            "POV-Ray",
            "PowerBasic",
            "PowerScript",
            "PowerShell",
            "Processing",
            "Prolog",
            "Puppet",
            "Pure Data",
            "Python",
            "Q",
            "R",
            "Racket",
            "REALBasic",
            "REBOL",
            "Revolution",
            "REXX",
            "RPG (OS/400)",
            "Ruby",
            "Rust",
            "S",
            "S-PLUS",
            "SAS",
            "Sather",
            "Scala",
            "Scheme",
            "Scilab",
            "Scratch",
            "sed",
            "Seed7",
            "Self",
            "Shell",
            "SIGNAL",
            "Simula",
            "Simulink",
            "Slate",
            "Smalltalk",
            "Smarty",
            "SPARK",
            "SPSS",
            "SQR",
            "Squeak",
            "Squirrel",
            "Standard ML",
            "Suneido",
            "SuperCollider",
            "TACL",
            "Tcl",
            "Tex",
            "thinBasic",
            "TOM",
            "Transact-SQL",
            "Turing",
            "TypeScript",
            "Vala/Genie",
            "VBScript",
            "Verilog",
            "VHDL",
            "VimL",
            "Visual Basic .NET",
            "WebDNA",
            "Whitespace",
            "X10",
            "xBase",
            "XBase++",
            "Xen",
            "XPL",
            "XSLT",
            "XQuery",
            "yacc",
            "Yorick",
            "Z shell",
        };
    }

    void init_branches() noexcept {
        this->branches = {
            "Human-computer interaction",
            "Data science",
            "Natural language processing",
            "Programming languages",
            "Software engineering",
            "Architecture and organization",
            "Cyber security",
            "Information management",
            "Networking and communication",
            "Computer graphics",
            "Platform-based development",
            "Graphics and visual computing",
            "Algorithms and complexity",
            "Parallel and distributed computing",
            "Intelligent systems",
            "Security and information assurance",
            "Computer Science",
            "Computer Engineering",
            "Information Systems",
            "New Media",
            "Information Technology (IT)",
            "Information Science",
            "Mathematical foundations.",
            "Algorithms and data structures.",
            "Artificial intelligence.",
            "Communication and security.",
            "Computer architecture.",
            "Computer graphics.",
            "Concurrent, parallel, and distributed systems.",
            "Databases.",
            "Programming languages and compilers",
            "Scientific computing",
            "Software engineering",
            "Theory of computing"
        };
    }
};

#endif // TYPECODE_TYPECODE_HPP
