struct logoINFO {
    unsigned width, height;
    char *body;
};

enum logoTYPE { none, debian, freebsd, tux, nixos, voidlinux, openbsd, ubuntu, logoNUM  };

struct logoINFO logoSET[logoNUM] = {
    {   // None
        0, 0, ""
    },
    {   // Debian
        10, 6, RED
        "  _____\n"
        " /  __ \\\n"
        "|  /    |\n"
        "|  \\___-\n"
        "-_\n"
        "  --_\n"
    },
    {   // FreeBSD
        14, 6, BOLD RED
        "/\\,-'''''-,/\\\n"
        "\\_)       (_/\n"
        "|           |\n"
        "|           |\n"
        " ;         ;\n"
        "  '-_____-'\n"
    },
    {   // Tux (Generic Linux)
        15, 7, BLUE
        "    .---.\n"
        "   /     \\\n"
        "   \\.@-@./\n"
        "   /`\\_/`\\\n"
        "  //  _  \\\\\n"
        " | \\     )|_\n"
        "/`\\_`>  <_/ \\\n"
        "\\__/'---'\\__/\n"
    },
    {   // NixOS
        14, 7, CYAN
        "  \\\\  \\\\ //\n"
        " ==\\\\__\\\\/ //\n"
        "   //   \\\\//\n"
        "==//     //==\n"
        " //\\\\___//\n"
        "// /\\\\  \\\\==\n"
        "  // \\\\  \\\\\n"
    },
    {   // Void Linux
        14, 7, GREEN
        "    _______\n"
        " _ \\______ -\n"
        "| \\  ___  \\ |\n"
        "| | /   \\ | |\n"
        "| | \\___/ | |\n"
        "| \\______ \\_|\n"
        " -_______\\\n"
    },
    {   // OpenBSD
        18, 7, YELLOW
        "       _____\n"
        "     \\-     -/\n"
        "  \\_/         \\\n"
        "  |        "BLUE"o o"YELLOW" |\n" 
        "  |_   <  )  3 |\n"       
        "  / \\         /\n"
        "     /-_____-\\\n"
    },
    {   // Ubuntu
        16, 6, RED
        "           _\n"
        "       ---(_)\n"
        "   _/  ---  \\\n"
        "  (_) |   |\n"
        "    \\  --- _/\n"
        "       ---(_)\n"
    }
};
