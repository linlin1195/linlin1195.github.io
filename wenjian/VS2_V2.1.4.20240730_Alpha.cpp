/*
VS2:Monsters' Revenge
Copyright (C) 2024 Bintree Development Team
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
*/
/**
 * VS2: Monsters' Revenge
 * @since V2.1.4.20240730_Alpha
 * @author Bintree Development Team
 */

#define mini(x, y) (((x) < (y)) ? (x) : (y))
#define maxi(x, y) (((x) > (y)) ? (x) : (y))
#ifdef _WIN32
#include <conio.h>
#endif
#include <cstddef>
#ifdef _WIN32
#include <io.h>
#endif
#include <fstream>
#include <random>
#include <sstream>
#ifdef _WIN32
#include <windows.h>
#endif

namespace settings
{
#ifdef _WIN32
    constexpr char PATH[] = R"(C:\Users\Public\Documents\VS2\)";
#else
    constexpr char PATH[] = "/opt/vs2/";
#endif
    constexpr char TITLE[] = "VS2:Monsters' Reverge";
    constexpr char HACKER[] = "YOU ARE A DIRTY HACKER";
    constexpr unsigned short LOGO_HEIGHT = 7;
    constexpr unsigned short LOGO_WIDTH = 53;
    constexpr char LOGO[LOGO_HEIGHT][LOGO_WIDTH] = {
        R"(      ________________________________________)",
        R"(    _/_                                      _\_)",
        R"( __/__/         VS2:Monsters' Revenge        \__\__)",
        R"(| < < |            Version 2.7.30            | > > |)",
        R"( --\--\           English language           /--/--)",
        R"(    -\-                                      -/-)",
        R"(      ----------------------------------------)"
    };
    constexpr char NAMING_TABLE[6][26] = {
        "A B C D E F G H I J K L M",
        "N O P Q R S T U V W X Y Z",
        "a b c d e f g h i j k l m",
        "n o p q r s t u v w x y z",
        "1 2 3 4 5 6 7 8 9 0 - _ +",
        "Backspace Confirm"
    };
    constexpr unsigned short MAX_WORLD_HEIGHT = 100;
    constexpr unsigned short MAX_WORLD_WIDTH = 100;
    constexpr std::size_t MAX_NAME_LENGTH = 20;
    constexpr unsigned short MAX_WEAPONS_NUM = 9;
    constexpr unsigned short INFO_NUM = 3;
} // namespace settings

char tmp[10500];

namespace file
{
    inline bool exfile(const char* filename)
    {
        memset(tmp, 0, sizeof(tmp));
        sprintf(tmp, "%s%s", settings::PATH, filename);
        return access(tmp, 0) == 0;
    }

    inline void mkfile(const char* filename)
    {
        if (exfile(filename)) return;
        memset(tmp, 0, sizeof(tmp));
#ifdef _WIN32
        sprintf(tmp, "type nul>%s%s", settings::PATH, filename);
#else
        sprintf(tmp, "touch %s%s", settings::PATH, filename);
#endif
        system(tmp);
    }

    inline void rmfile(const char* filename)
    {
        if (!exfile(filename)) return;
        memset(tmp, 0, sizeof(tmp));
#ifdef _WIN32
        sprintf(tmp, "del %s%s", settings::PATH, filename);
#else
        sprintf(tmp, "rm -f %s%s", settings::PATH, filename);
#endif
        system(tmp);
    }

    inline char* rdfile(const char* filename)
    {
        memset(tmp, 0, sizeof(tmp));
        sprintf(tmp, "%s%s", settings::PATH, filename);
        return tmp;
    }

    inline void mkdir(const char* dirname)
    {
        memset(tmp, 0, sizeof(tmp));
        sprintf(tmp, "mkdir %s", dirname);
        system(tmp);
    }
} // namespace file

namespace player 
{
    enum Direction 
	{
        UP, LEFT, DOWN, RIGHT, LUP, LDOWN, RDOWN, RUP
    };

    enum Color 
	{
        BLACK, RED, GREEN, YELLOW, BLUE, PURPLE, SKYBLUE, WHITE
    };

    class Player 
	{
        public:
            Player();
            ~Player();
            inline void naming(const char* _name);
            inline void setColor(Color _color);
            inline char* getColor() const;
            inline void move(Direction _direction, unsigned short height, unsigned short width);
            inline void teleport(unsigned short _x, unsigned short _y);
            inline bool getWeapon(char weapon);
            bool attack(char weapon);
            inline unsigned short getX() const;
            inline unsigned short getY() const;
            inline bool hit(short hurt);
            inline bool islive() const;
            inline short gethp() const;
            inline const char* getWeapons() const;
            inline const char* getName() const;
        private:
            char* name;
            Direction direction;
            Color color;
            unsigned short x, y;
            short hp;
            char* weapons;
            int weaponsNum;
            int fastNum;
            int speed;
            int rmdFast;
    };
} // namespace player

namespace world 
{
    class World 
	{
        public:
            World();
            ~World();
            void setSize(short _height, short _width);
            bool load();
            inline void naming(const char* name);
            inline void putWeapon(char who, char weapon);
            inline void pushinfo(const char* info);
            void showWorld();
            char* serialization(char* msg);
        private:
            char** infos;
            char** sekai;
            short height, width;
            player::Player* aid;
            player::Player* hmn;
    };
} // namespace world

namespace bfsp 
{
	
} // namespace bfsp

namespace vs2 
{
    world::World sekai;
    inline void wait(int ms);
    inline int init();
    int run();
} // namespace vs2

namespace cli 
{
#ifdef _WIN32
    HANDLE hOutput;
#endif
    inline int init();
    inline int getKey();
    inline void setTitle(const char* title);
    inline void clearConsole();
    void setCursorPosition(short row, short col);
    inline unsigned short getConsoleWidth();
    inline unsigned short getConsoleHeight(); 
    inline unsigned short getMid(int height);
    inline unsigned short getCol(int strLen);
    void delayPrint(const char* str, int ms);
    void printStr(short row, short col, const char* str);
    void showlogo();
    bool confirm();
    inline char* charToStr(char ch, char* str);
    char* naming(char* name);
} // namespace cli

namespace distribution 
{
    std::random_device rd;
    std::mt19937 gen(rd());
    inline int init();
    int randInt(int minval, int maxval);
} // namespace distribution

namespace player 
{
    Player::Player() 
	{
        name = static_cast<char*>(malloc(settings::MAX_NAME_LENGTH));
        memset(name, '\0', sizeof(name));
        direction = DOWN;
        x = y = 0;
        hp = 100;
        weapons = static_cast<char*>(malloc(settings::MAX_WEAPONS_NUM));
        memset(weapons, '\0', sizeof(weapons));
        weaponsNum = 0;
        fastNum = 0;
        speed = 200;
        rmdFast = 0;
    }

    Player::~Player() 
	{
        free(name);
        free(weapons);
        name = nullptr;
        weapons = nullptr;
    }

    inline void Player::naming(const char* _name) 
	{
        memcpy(name, _name, strlen(_name));
    }

    inline void Player::setColor(Color _color)
    {
        color = _color;
    }

    inline char* Player::getColor() const
    {
        memset(tmp, 0, sizeof(tmp));
        sprintf(tmp, "\033[3%dm", int(color));
        return tmp;
    }

    inline void Player::move(const Direction _direction, const unsigned short height, const unsigned short width) 
	{
        switch (direction = _direction) 
		{
            case UP: 
			{
                if (x) x--;
                break;
            }
            case LEFT: 
			{
                if (y) y--;
                break;
            }
            case DOWN: 
			{
                if (x < height - 1) x++;
                break;
            }
            case RIGHT: 
			{
                if (y < width - 1) y++;
                break;
            }
            case LUP: 
			{
                move(LEFT, height, width);
                move(UP, height, width);
                break;
            }
            case LDOWN: 
			{
                move(LEFT, height, width);
                move(DOWN, height, width);
                break;
            }
            case RDOWN: 
			{
                move(RIGHT, height, width);
                move(DOWN, height, width);
                break;
            }
            case RUP: 
			{
                move(RIGHT, height, width);
                move(UP, height, width);
                break;
            }
        }
    }

    inline void Player::teleport(const unsigned short _x, const unsigned short _y) 
	{
        x = _x;
        y = _y;
    }

    inline bool Player::getWeapon(const char weapon) 
	{
        if (weaponsNum == settings::MAX_WEAPONS_NUM) return false;
        weapons[weaponsNum++] = weapon;
        return true;
    }

    bool Player::attack(const char weapon) 
	{
        for (int i = 0; i < weaponsNum; i++)
            if (weapons[i] == weapon) 
			{
                for (int j = i + 1; j < weaponsNum; j++)
                    weapons[j - 1] = weapons[j];
                weaponsNum--;
                return true;
            }
        return false;
    }

    inline unsigned short Player::getX() const 
	{
        return x;
    }

    inline unsigned short Player::getY() const 
	{
        return y;
    }

    inline bool Player::hit(const short hurt) 
	{
        if (islive()) hp -= hurt;
        return islive();
    }

    inline bool Player::islive() const 
	{
        return hp > 0;
    }

    inline short Player::gethp() const 
	{
        return hp;
    }

    inline const char* Player::getWeapons() const 
	{
        return weapons;
    }

    inline const char* Player::getName() const 
	{
        return name;
    }
} // namespace player

namespace world 
{
    World::World() 
	{
        aid = (player::Player*) malloc(sizeof(player::Player));
        hmn = (player::Player*) malloc(sizeof(player::Player));
        new(aid) player::Player();
        new(hmn) player::Player();
        aid->setColor(player::RED);
        hmn->setColor(player::BLUE);
        aid->naming("monsiend");
        sekai = (char**) malloc(sizeof(char*) * settings::MAX_WORLD_HEIGHT);
        for (int i = 0; i < settings::MAX_WORLD_HEIGHT; i++) 
		{
            sekai[i] = (char*) malloc(settings::MAX_WORLD_WIDTH);
            memset(sekai[i], '.', sizeof(sekai[i]));
        }
        sekai[0][0] = 'v';
        infos = (char**) malloc(sizeof(char*) * settings::INFO_NUM);
        for (int i = 0; i < settings::INFO_NUM; i++) 
		{
            infos[i] = (char*) malloc(settings::MAX_WORLD_WIDTH);
            memset(infos[i], '\0', sizeof(infos[i]));
        }
    }
    
    World::~World() 
	{
        for (int i = 0; i < settings::MAX_WORLD_HEIGHT; i++)
            free(sekai[i]);
        free(sekai);
        for (int i = 0; i < settings::INFO_NUM; i++)
            free(infos[i]);
        free(infos);
        delete aid;
        delete hmn;
        aid = hmn = NULL;
        sekai = infos = NULL;
    }

    void World::setSize(short _height, short _width) 
	{
        height = _height;
        width = _width;
        aid->teleport(height - 1, width - 1);
        sekai[height - 1][width - 1] = '^';
    }

    bool World::load() 
	{
        std::ifstream is;
        is.open(file::rdfile("file"));
        int idx = 0;
        memset(tmp, '\0', sizeof(tmp));
        short hx, hy, ax = -1, ay = -1;
        short hhp, ahp;
        char c = is.get();
        while (c != '\n') 
		{
            if (idx > settings::MAX_NAME_LENGTH)
                return false;
            tmp[idx++] = c;
            c = is.get();
        }
        naming(tmp);
        is >> height >> width >> hx >> hy >> hhp >> ahp;
        if (height < 5 || width < 5)
            return false;
        if (hx < 0 || hy < 0 || hx >= height || hy >= width)
            return false;
        if (hhp > 100 || ahp > 100)
            return false;
        for (int i = 0; i < height; i++)
            for (int j = 0; j < width; j++) 
			{
                is >> sekai[i][j];
                if (sekai[i][j] == '.')
                    sekai[i][j] = ' ';
                if ((sekai[i][j] == '^' || sekai[i][j] == '<' || sekai[i][j] == 'v' || sekai[i][j] == '>') && i != hx && j != hy)
                    ax = i, ay = j;
            }
        if (sekai[hx][hy] != '^' && sekai[hx][hy] != '<' && sekai[hx][hy] != 'v' && sekai[hx][hy] != '>') return false;
        if (ax == -1 || ay == -1)
            return false;
        hmn->teleport(hx, hy);
        aid->teleport(ax, ay);
        int x;
        is >> x;
        while (x--) 
		{
            c = is.get();
            if (!hmn->getWeapon(c))
                return false;
        }
        is >> x;
        while (x--) 
		{
            c = is.get();
            if (!aid->getWeapon(c))
                return false;
        }
        return true;
    }

    inline void World::naming(const char* name) 
	{
        if (strlen(name) >= settings::MAX_NAME_LENGTH) 
		{
            file::mkfile("hacker1");
            exit(0);
        }
        hmn->naming(name);
    }

    inline void World::putWeapon(char who, char weapon) 
	{
        if (who == 'H') 
		{
            if (hmn->attack(weapon))
                sekai[hmn->getX()][hmn->getY()] = weapon;
        } 
		else 
		{
            if (aid->attack(weapon))
                sekai[aid->getX()][aid->getY()] = weapon;
        }
    }

    inline void World::pushinfo(const char* info) 
	{
        memcpy(infos[0], infos[1], settings::MAX_WORLD_WIDTH);
        memcpy(infos[1], infos[2], settings::MAX_WORLD_WIDTH);
        memcpy(infos[2], info, strlen(info));
        memset(infos[2] + strlen(info), '\0', settings::MAX_WORLD_WIDTH - strlen(info));
    }

    void World::showWorld() 
	{
        int ltx = hmn->getX() - cli::getMid(0);
        int lty = hmn->getY() - cli::getCol(0);
        if (ltx < 0) ltx = 0;
        if (lty < 0) lty = 0;
        short ch = cli::getConsoleHeight() - settings::INFO_NUM - 1;
        short cw = cli::getConsoleWidth();
        cli::clearConsole();
        cli::printStr(ch, 0, "Infos ");
        for (int i = 6; i < cw; i++) printf("-");
        for (int i = 0; i < settings::INFO_NUM; i++)
            cli::printStr(ch + 1 + i, 0, infos[i]);
        cli::setCursorPosition(0, 0);
        for (int i = 0; i < mini(ch, height); i++)
            for (int j = 0; j < mini(cw, width); j++) 
			{
                if (i == aid->getX() && j == aid->getY())
                    printf("%s", aid->getColor());
                if (i == hmn->getX() && j == hmn->getX())
                    printf("%s", hmn->getColor());
                if (sekai[i][j] != '.') printf("%c", sekai[i][j]);
                else printf(" ");
                if ((i == aid->getX() && j == aid->getY()) || (i == hmn->getX() && j == hmn->getX()))
                    printf("\033[0m");
                if (i != mini(ch, height) - 1 && j == mini(cw, width) - 1) printf("\n");
            }
    }

    char* World::serialization(char* msg) 
	{
        std::stringstream ss;
        ss << hmn->getName() << '\n';
        ss << height << ' ' << width << ' ' << hmn->getX() << ' ' << hmn->getY() << ' ' << hmn->gethp() << ' ' << aid->gethp() << '\n';
        for (int i = 0; i < height; i++)
            for (int j = 0; j < width; j++) 
			{
                ss << sekai[i][j];
                if (j == width - 1) ss << '\n';
            }
        ss << strlen(hmn->getWeapons()) << ' ' << hmn->getWeapons() << '\n';
        ss << strlen(aid->getWeapons()) << ' ' << aid->getWeapons() << '\n';
        memcpy(msg, ss.str().c_str(), ss.str().length());
        return msg;
    }
} // namespace world

namespace vs2 {
    inline void wait(int ms)
    {
#ifdef _WIN32
        Sleep(ms);
#else
        usleep(ms);
#endif
    }

    inline int init() { return cli::init() | distribution::init(); }

    /******** RUN VS2 ********/
    int run() 
	{
        CONSOLE_CURSOR_INFO cinfo;
        GetConsoleCursorInfo(cli::hOutput, &cinfo);
        cinfo.bVisible = false;
        SetConsoleCursorInfo(cli::hOutput, &cinfo);
        if (!file::exfile("file"))
            file::mkdir(settings::PATH);
        cli::setTitle(settings::TITLE);
        cli::clearConsole();
        if (file::exfile("hacker1")) 
		{
            cli::setTitle(settings::HACKER);
            printf("blue-peace2013: ");
            cli::delayPrint("You're a CHEAPTER...", 50);
            vs2::wait(1000);
            file::rmfile("hacker1");
            file::mkfile("hacker2");
            exit(0);
        }
        if (file::exfile("hacker2")) 
		{
            cli::setTitle(settings::HACKER);
            printf("blue-peace2013: ");
            cli::delayPrint("......", 200);
            vs2::wait(5000);
            file::rmfile("hacker2");
            file::mkfile("hacker3");
            exit(0);
        }
        if (file::exfile("hacker3")) 
		{
            cli::setTitle(settings::HACKER);
            printf("blue-peace2013: ");
            cli::delayPrint("......", 200);
            vs2::wait(1000);
            file::rmfile("hacker3");
            file::mkfile("hacker4");
            exit(0);
        }
        if (file::exfile("hacker4")) 
		{
            cli::setTitle(settings::HACKER);
            printf("blue-peace2013: ");
            cli::delayPrint("I think you realize that.", 50);
            vs2::wait(2000);
            cli::setCursorPosition(0, 16);
            printf("                                        ");
            cli::setCursorPosition(0, 16);
            cli::delayPrint("We can even consume each other forever.", 50);
            vs2::wait(3000);
            cli::setCursorPosition(0, 16);
            printf("                                        ");
            cli::setCursorPosition(0, 16);
            cli::delayPrint("But I'm unblocking you anyway.", 50);
            vs2::wait(5000);
            cli::setCursorPosition(0, 16);
            printf("                                        ");
            cli::setCursorPosition(0, 16);
            cli::delayPrint("You know what you did...", 50);
            vs2::wait(2000);
            cli::setCursorPosition(0, 16);
            printf("                                        ");
            cli::setCursorPosition(0, 16);
            cli::delayPrint("I wish you wouldn't do that again.", 50);
            vs2::wait(2000);
            cli::setCursorPosition(0, 16);
            printf("                                        ");
            cli::setCursorPosition(0, 16);
            file::rmfile("file");
            vs2::wait(2000);
            cli::delayPrint("I've clear your bad file.", 50);
            file::rmfile("hacker4");
            exit(0);
        }
        choiceStart:;
        cli::clearConsole();
        cli::showlogo();
        cli::printStr(cli::getMid(settings::LOGO_HEIGHT + 5) + 9, cli::getCol(10), " New Game ");
        cli::printStr(cli::getMid(settings::LOGO_HEIGHT + 5) + 10, cli::getCol(11), " Read File ");
        cli::printStr(cli::getMid(settings::LOGO_HEIGHT + 5) + 11, cli::getCol(16), " Playing Method ");
        cli::printStr(cli::getMid(settings::LOGO_HEIGHT + 5) + 12, cli::getCol(6), " Exit ");
        int minChoice = 1;
        if (file::exfile("Cpp_King") && file::exfile("linlin1195") && file::exfile("fzt123F")) 
		{
            cli::printStr(cli::getMid(settings::LOGO_HEIGHT + 5) + 8, cli::getCol(12), "Authors Home");
            minChoice = 0;
        }
        int oldchoice = minChoice, choice = minChoice;
        SetConsoleTextAttribute(cli::hOutput, FOREGROUND_INTENSITY | 4);
        switch (choice) 
		{
            case 0: 
			{
                cli::printStr(cli::getMid(settings::LOGO_HEIGHT + 5) + 8, cli::getCol(14), "[Authors Home]");
                break;
            }
            case 1: 
			{
                cli::printStr(cli::getMid(settings::LOGO_HEIGHT + 5) + 9, cli::getCol(10), "[New Game]");
                break;
            }
            case 2: 
			{
                cli::printStr(cli::getMid(settings::LOGO_HEIGHT + 5) + 10, cli::getCol(11), "[Read File]");
                break;
            }
            case 3: 
			{
                cli::printStr(cli::getMid(settings::LOGO_HEIGHT + 5) + 11, cli::getCol(16), "[Playing Method]");
                break;
            }
            case 4: 
			{
                cli::printStr(cli::getMid(settings::LOGO_HEIGHT + 5) + 12, cli::getCol(6), "[Exit]");
                break;
            }
        }
        SetConsoleTextAttribute(cli::hOutput, FOREGROUND_INTENSITY | 7);
        int key;
        int pos;
        int oldpos;
        bool dir;
        while (true) 
		{
            oldchoice = choice;
            key = cli::getKey();
            switch (key) 
			{
                case 'w': case 'W': case 72: 
				{
                    if (--choice < minChoice)
                        choice = 4;
                    break;
                }
                case 's': case 'S': case 80: 
				{
                    if (++choice > 4)
                        choice = minChoice;
                    break;
                }
                case 13: 
				{
                    goto choiceEnd;
                }
            }
            switch (oldchoice) 
			{
                case 0: 
				{
                    cli::printStr(cli::getMid(settings::LOGO_HEIGHT + 5) + 8, cli::getCol(14), " Authors Home ");
                    break;
                }
                case 1: 
				{
                    cli::printStr(cli::getMid(settings::LOGO_HEIGHT + 5) + 9, cli::getCol(10), " New Game ");
                    break;
                }
                case 2: 
				{
                    cli::printStr(cli::getMid(settings::LOGO_HEIGHT + 5) + 10, cli::getCol(11), " Read File ");
                    break;
                }
                case 3: 
				{
                    cli::printStr(cli::getMid(settings::LOGO_HEIGHT + 5) + 11, cli::getCol(16), " Playing Method ");
                    break;
                }
                case 4: 
				{
                    cli::printStr(cli::getMid(settings::LOGO_HEIGHT + 5) + 12, cli::getCol(6), " Exit ");
                    break;
                }
            }
            SetConsoleTextAttribute(cli::hOutput, FOREGROUND_INTENSITY | 4);
            switch (choice) 
			{
                case 0: 
				{
                    cli::printStr(cli::getMid(settings::LOGO_HEIGHT + 5) + 8, cli::getCol(14), "[Authors Home]");
                    break;
                }
                case 1: 
				{
                    cli::printStr(cli::getMid(settings::LOGO_HEIGHT + 5) + 9, cli::getCol(10), "[New Game]");
                    break;
                }
                case 2: 
				{
                    cli::printStr(cli::getMid(settings::LOGO_HEIGHT + 5) + 10, cli::getCol(11), "[Read File]");
                    break;
                }
                case 3: 
				{
                    cli::printStr(cli::getMid(settings::LOGO_HEIGHT + 5) + 11, cli::getCol(16), "[Playing Method]");
                    break;
                }
                case 4: 
				{
                    cli::printStr(cli::getMid(settings::LOGO_HEIGHT + 5) + 12, cli::getCol(6), "[Exit]");
                    break;
                }
            }
            SetConsoleTextAttribute(cli::hOutput, FOREGROUND_INTENSITY | 7);
        }
        choiceEnd:;
        cli::clearConsole();
        switch (choice) 
		{
            case 0: 
			{
                printf("???????\n\n?????????????????????谢???!\n\n(?????娴??????????hacker???(doge)\n????UT????(?????????????????UT??");
                return 0;
            }
            case 1: 
			{
                file::rmfile("file");
                file::mkfile("file");
                cli::clearConsole();
                int key;
                int hb = 0, wb = 0;
                short height = 0, width = 0;
                cli::printStr(0, cli::getCol(18), "Input world height");
                memset(tmp, '\0', sizeof(tmp));
                while (true) 
				{
                    key = cli::getKey();
                    if (key >= '0' && key <= '9') 
					{
                        height = height * 10 + key - '0';
                        tmp[hb++] = key;
                    } 
					else if (key == 8) 
					{
                        if (hb) tmp[hb--] = '\0';
                        height /= 10;
                    }
                    cli::printStr(cli::getMid(0), cli::getCol(6), "      ");
                    if (hb) cli::printStr(cli::getMid(0), cli::getCol(hb), tmp);
                    else cli::printStr(cli::getMid(0), cli::getCol(1), "0");
                    if (key == 13) break;
                }
                cli::clearConsole();
                vs2::wait(1000);
                cli::printStr(0, cli::getCol(17), "Input world width");
                memset(tmp, '\0', sizeof(tmp));
                while (true) 
				{
                    key = cli::getKey();
                    if (key >= '0' && key <= '9') 
					{
                        width = width * 10 + key - '0';
                        tmp[wb++] = key;
                    } 
					else if (key == 8) 
					{
                        if (wb) tmp[wb--] = '\0';
                        width /= 10;
                    }
                    cli::printStr(cli::getMid(0), cli::getCol(6), "      ");
                    if (wb) cli::printStr(cli::getMid(0), cli::getCol(wb), tmp);
                    else cli::printStr(cli::getMid(0), cli::getCol(1), "0");
                    if (key == 13) break;
                }
                height = maxi(height, 5);
                width = maxi(width, 5);
                sekai.setSize(height, width);
                sekai.naming(cli::naming(tmp));
                if (tmp[0] == 'f' && tmp[1] == 'z' && tmp[2] == 't' && tmp[3] == '1' && tmp[4] == '2' && tmp[5] == '3' && tmp[6] == 'F' && tmp[7] == '\0')
                    file::mkfile("fzt123F");
                if (tmp[0] == 'l' && tmp[1] == 'i' && tmp[2] == 'n' && tmp[3] == 'l' && tmp[4] == 'i' && tmp[5] == 'n' && tmp[6] == '1' && tmp[7] == '1' && tmp[8] == '9' && tmp[9] == '5' && tmp[10] == '\0')
                    file::mkfile("linlin1195");
                if (tmp[0] == 'C' && tmp[1] == 'p' && tmp[2] == 'p' && tmp[3] == '_' && tmp[4] == 'K' && tmp[5] == 'i' && tmp[6] == 'n' && tmp[7] == 'g' && tmp[8] == '\0')
                    file::mkfile("Cpp_King");
                cli::clearConsole();
                std::ofstream os(file::rdfile("file"));
                memset(tmp, '\0', sizeof(tmp));
                os << sekai.serialization(tmp);
                os.close();
                break;
            }
            case 2: 
			{
                if (!sekai.load()) 
				{
                    file::mkfile("hacker1");
                    exit(0);
                }
                cli::showlogo();
                cli::printStr(cli::getMid(settings::LOGO_HEIGHT + 5) + 8, cli::getCol(15), "Loading file...");
                vs2::wait(2000);
                cli::clearConsole();
                cli::showlogo();
                cli::printStr(cli::getMid(settings::LOGO_HEIGHT + 5) + 8, cli::getCol(21), "Loading CLI module...");
                vs2::wait(2000);
                cli::clearConsole();
                cli::showlogo();
                cli::printStr(cli::getMid(settings::LOGO_HEIGHT + 5) + 8, cli::getCol(6), "Done!");
                vs2::wait(1000);
                cli::clearConsole();
                cli::printStr(cli::getMid(0), cli::getCol(1), "3");
                vs2::wait(1000);
                cli::printStr(cli::getMid(0), cli::getCol(1), "2");
                vs2::wait(1000);
                cli::printStr(cli::getMid(0), cli::getCol(1), "1");
                vs2::wait(1000);
                cli::printStr(cli::getMid(0), cli::getCol(1), "0");
                cli::clearConsole();
                goto gameStart;
                break;
            }
            case 3: 
			{
                printf("You choose [Playing Method]");
                goto choiceStart;
                break;
            }
            case 4: 
			{
                exit(0);
                break;
            }
        }
        vs2::wait(2000);
        cli::clearConsole();
        cli::showlogo();
        cli::printStr(cli::getMid(settings::LOGO_HEIGHT + 5) + 8, cli::getCol(21), "Loading CLI module...");
        vs2::wait(2000);
        cli::clearConsole();
        cli::showlogo();
        cli::printStr(cli::getMid(settings::LOGO_HEIGHT + 5) + 8, cli::getCol(6), "Done!");
        vs2::wait(1000);
        cli::clearConsole();
        cli::setCursorPosition(0, 0);
        cli::delayPrint("Once upon a time, there were two tribes, humans and monsters...\n", 50);
        vs2::wait(1000);
        cli::delayPrint("They have always helped each other, the world is very peaceful\n", 50);
        vs2::wait(1000);
        cli::delayPrint("Until one day, the humans attacked the monsters...\n", 50);
        vs2::wait(1000);
        cli::delayPrint("Only one monster child escaped, and none of the others survived...\n", 50);
        vs2::wait(1000);
        cli::delayPrint("The monster child hid in the cave, looked out at the sea of people outside the cave\n", 50);
        vs2::wait(200);
        cli::delayPrint("Made up his mind to take revenge.\n\n\n", 50);
        vs2::wait(2000);
        cli::delayPrint("You fell into this cave, and now you have to fight him... Did you?", 50);
        vs2::wait(2000);
        cli::clearConsole();
        cli::showlogo();
        cli::printStr(cli::getConsoleHeight() - (cli::getMid(0) >> 1), cli::getCol(28), "Press any key to start game.");
        cli::getKey();
        vs2::wait(1000);
        cli::clearConsole();
        cli::printStr(cli::getConsoleHeight() - 3, cli::getCol(3), "___");
        cli::printStr(cli::getConsoleHeight() - 2, cli::getCol(3), "|v|");
        cli::printStr(cli::getConsoleHeight() - 1, cli::getCol(3), "| |");
        cli::setCursorPosition(0, 0);
        printf("* ");
        cli::delayPrint("Your courage will not allow you to retreat.", 50);
        oldpos = cli::getConsoleHeight() - 2;
        pos = cli::getConsoleHeight() - 2;
        dir = false;
        while (pos != cli::getConsoleHeight()) 
		{
            key = cli::getKey();
            oldpos = pos;
            switch (key) {
                case 'w': case 'W': case 72: 
				{
                    dir = true;
                    if (pos > cli::getConsoleHeight() - 2) pos--;
                    break;
                }
                case 's': case 'S': case 80: 
				{
                    dir = false;
                    pos++;
                    break;
                }
            }
            cli::printStr(oldpos, cli::getCol(1), " ");
            if (pos != cli::getConsoleHeight()) 
			{
                if (dir)
                    cli::printStr(pos, cli::getCol(1), "^");
                else
                    cli::printStr(pos, cli::getCol(1), "v");
            }
        }
        cli::clearConsole();
        gameStart:;
        sekai.pushinfo("This is first Info!!!");
        sekai.showWorld();
        vs2::wait(100);
        sekai.pushinfo("Second!!");
        sekai.showWorld();
        vs2::wait(100);
        sekai.pushinfo("Thirst!");
        sekai.showWorld();
        vs2::wait(100);
        sekai.pushinfo("Replace");
        sekai.showWorld();
        vs2::wait(2000);
        return 0;
    }
} // namespace vs2

namespace cli 
{
    inline int init()
    {
        hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
        return 0;
    }

    inline int getKey()
    {
        int key = _getch();
        if (key == 0 || key == 0xe0)
            key = _getch();
        return key;
    }

    inline void setTitle(const char* title)
    {
#ifdef _WIN32
        SetConsoleTitleA(title);
#else
        printf("\033]0;%s\007", title);
#endif
    }

    inline void clearConsole()
    {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
    }

    inline unsigned short getConsoleWidth()
    {
#ifdef _WIN32
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(hOutput, &csbi);
        return csbi.srWindow.Right - csbi.srWindow.Left + 1;
#else
        struct winsize w;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
        return w.ws_row;
#endif
    }

    inline unsigned short getConsoleHeight()
    {
#ifdef _WIN32
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(hOutput, &csbi);
        return csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
#else
        struct winsize w;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
        return w.ws_col;
#endif
    }

    void setCursorPosition(short row, short col) 
	{
        COORD pos;
        pos.X = col;
        pos.Y = row;
        SetConsoleCursorPosition(hOutput, pos);
    }

    inline unsigned short getMid(int height) 
	{
        return (cli::getConsoleHeight() - height) >> 1;
    }

    inline unsigned short getCol(int strLen) 
	{
        return (cli::getConsoleWidth() - strLen) >> 1;
    }

    void delayPrint(const char* str, int ms) 
	{
        for (int i = 0; i < strlen(str); i++) 
		{
            printf("%c", str[i]);
            if (str[i] != ' ')
                vs2::wait(ms);
            if (str[i] == ',')
                vs2::wait(200 - ms);
        }
    }

    void printStr(short row, short col, const char* str) 
	{
        setCursorPosition(row, col);
        printf("%s", str);
    }

    void showlogo() 
	{
        unsigned short logoCol = getCol(settings::LOGO_WIDTH);
        CONSOLE_CURSOR_INFO cinfo;
        GetConsoleCursorInfo(hOutput, &cinfo);
        cinfo.bVisible = false;
        SetConsoleCursorInfo(hOutput, &cinfo);
        for (int i = 0; i < 7; i++)
            printStr(cli::getMid(settings::LOGO_HEIGHT + 5) + i, logoCol, settings::LOGO[i]);
    }

    bool confirm() 
	{
        cli::clearConsole();
        printStr(0, getCol(8), "Confirm?");
        bool choice = false;
        SetConsoleTextAttribute(hOutput, FOREGROUND_INTENSITY | 4);
        printStr(getMid(0), (getCol(0) - 5) >> 1, "[Yes]");
        SetConsoleTextAttribute(hOutput, FOREGROUND_INTENSITY | 7);
        printStr(getMid(0), ((getCol(0) - 4) >> 1) + getCol(0), "[No]");
        while (true) 
		{
            int key = getKey();
            switch (key) 
			{
                case 13: 
				{
                    return !choice;
                    break;
                }
                default: 
				{
                    SetConsoleTextAttribute(hOutput, FOREGROUND_INTENSITY | 7);
                    if (choice)
                        printStr(getMid(0), ((getCol(0) - 4) >> 1) + getCol(0), "[No]");
                    else
                        printStr(getMid(0), (getCol(0) - 5) >> 1, "[Yes]");
                    choice = !choice;
                    SetConsoleTextAttribute(hOutput, FOREGROUND_INTENSITY | 4);
                    if (choice)
                        printStr(getMid(0), ((getCol(0) - 4) >> 1) + getCol(0), "[No]");
                    else
                        printStr(getMid(0), (getCol(0) - 5) >> 1, "[Yes]");
                    break;
                }
            }
        }
        return false;
    }

    inline char* charToStr(char ch, char* str) 
	{
        str[0] = ch;
        str[1] = '\0';
        return str;
    }

    char* naming(char* name) 
	{
        namingStart:;
        cli::clearConsole();
        char tmp[2];
        memset(name, 0, sizeof(name));
        printStr(0, getCol(16), "Input your name.");
        printStr(cli::getMid(settings::LOGO_HEIGHT + 5) + 13, getCol(50), "Press the arrow keys or wasd to control the cursor");
        printStr(cli::getMid(settings::LOGO_HEIGHT + 5) + 14, getCol(36), "Press [Enter] to enter the character");
        printStr(cli::getMid(settings::LOGO_HEIGHT + 5) + 15, getCol(39), "The name must be less than ");
        printStr(cli::getMid(settings::LOGO_HEIGHT + 5) + 15, getCol(39) + 27, charToStr(settings::MAX_NAME_LENGTH / 10 + '0', tmp));
        printStr(cli::getMid(settings::LOGO_HEIGHT + 5) + 15, getCol(39) + 28, charToStr(settings::MAX_NAME_LENGTH % 10 + '0', tmp));
        printStr(cli::getMid(settings::LOGO_HEIGHT + 5) + 15, getCol(39) + 29, " in length");
        for (int i = 0; i < 6; i++)
            printStr(cli::getMid(settings::LOGO_HEIGHT + 5) + i, getCol(strlen(settings::NAMING_TABLE[0])), settings::NAMING_TABLE[i]);
        int oldx = 0, oldy = 0;
        int x = 0, y = 0;
        int idx = 0;
        SetConsoleTextAttribute(hOutput, FOREGROUND_INTENSITY | 4);
        printStr(cli::getMid(settings::LOGO_HEIGHT + 5), getCol(strlen(settings::NAMING_TABLE[0])), "A");
        SetConsoleTextAttribute(hOutput, FOREGROUND_INTENSITY | 7);
        while (true) 
		{
            for (int i = 0; i < settings::MAX_NAME_LENGTH; i++)
                printStr(1, getCol(settings::MAX_NAME_LENGTH) + i, " ");
            printStr(1, getCol(idx), name);
            int key = getKey();
            oldx = x;
            oldy = y;
            switch (key) 
			{
                case 'a': case 'A': case 75: 
				{
                    if (y-- < 0) {
                        if (x == 5)
                            y = 1;
                        else
                            y = 12;
                    }
                    break;
                }
                case 'w': case 'W': case 72: 
				{
                    if (x-- < 0) {
                        x = 5;
                        if (y < 5)
                            y = 0;
                        else
                            y = 1;
                    }
                    break;
                }
                case 'd': case 'D': case 77: 
				{
                    if (x == 5) {
                        if (++y > 1)
                            y = 0;
                    } else {
                        if (++y > 12)
                            y = 0;
                    }
                    break;
                }
                case 's': case 'S': case 80: 
				{
                    if (++x == 5)  {
                        if (y < 5)
                            y = 0;
                        else
                            y = 1;
                    } else if (x > 5)
                        x = 0;
                    break;
                }
                case 13: 
				{
                    if (x == 5) 
					{
                        if (y == 0 && idx > 0)
                            name[idx--] = '\0';
                        else {
                            if (confirm())
                                goto namingEnd;
                            else
                                goto namingStart;
                        }
                    } 
					else
                        name[idx++] = settings::NAMING_TABLE[x][y << 1];
                    break;
                }
                default: break;
            }
            if (idx == settings::MAX_NAME_LENGTH - 1)
                name[idx--] = '\0';
            if (oldx == 5) 
			{
                if (oldy == 0)
                    printStr(cli::getMid(settings::LOGO_HEIGHT + 5) + 5, getCol(strlen(settings::NAMING_TABLE[0])), "Backspace");
                else
                    printStr(cli::getMid(settings::LOGO_HEIGHT + 5) + 5, getCol(strlen(settings::NAMING_TABLE[0])) + 10, "Confirm");
            } else
                printStr(cli::getMid(settings::LOGO_HEIGHT + 5) + oldx, getCol(strlen(settings::NAMING_TABLE[0])) + (oldy << 1), charToStr(settings::NAMING_TABLE[oldx][oldy << 1], tmp));
            SetConsoleTextAttribute(hOutput, FOREGROUND_INTENSITY | 4);
            if (x == 5) 
			{
                if (y == 0)
                    printStr(cli::getMid(settings::LOGO_HEIGHT + 5) + 5, getCol(strlen(settings::NAMING_TABLE[0])), "Backspace");
                else
                    printStr(cli::getMid(settings::LOGO_HEIGHT + 5) + 5, getCol(strlen(settings::NAMING_TABLE[0])) + 10, "Confirm");
            } else
                printStr(cli::getMid(settings::LOGO_HEIGHT + 5) + x, getCol(strlen(settings::NAMING_TABLE[0])) + (y << 1), charToStr(settings::NAMING_TABLE[x][y << 1], tmp));
            SetConsoleTextAttribute(hOutput, FOREGROUND_INTENSITY | 7);
        }
        namingEnd:;
        cli::clearConsole();
        return name;
    }
} // namespace cli

namespace distribution 
{
    inline int init() 
	{
        gen.seed(rd());
        return 0;
    }

    inline int randInt(int minval, int maxval) 
	{
        return std::uniform_int_distribution<int>(minval, maxval)(gen);
    }
} // namespace distribution

/******** fAKe main ********/

int main() { return vs2::init() | vs2::run(); }
