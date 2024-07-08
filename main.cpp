// Online C++ compiler to run C++ program online
#include <iostream>
#include <ctime>

using namespace std;

struct Bomb {
    int x;
    int y;
    bool operator==(Bomb &other) {
        return x == other.x && y == other.y;
    }
};

class Game {
    private:
        int size;
        int bombs_count;
        Bomb *bombs;
        char **place;
        bool start;
        void generate_bombs(int x, int y);
    public:
        Game(int n, int count);
        char **get_place();
};

Game::Game(int n, int count) {
    size = n;
    bombs_count = count;
    bombs = new Bomb[count];
    start = false;
    place = new char*[n];
    for (int i = 0; i < n; ++i) {
        place[i] = new char[n];
        for (int j = 0; j < n; ++j)
            place[i][j] = '?';
    }
}

char **Game::get_place() {
    return place;
}

void Game::generate_bombs(int x, int y) {
    bool success;
    srand((int) time(nullptr));
    Bomb control{x, y};
    for (int i = 0; i < bombs_count; ++i) {
        success = false;
        while (!success) {
            bombs[i] = Bomb{rand() % size, rand() % size};
            if (bombs[i] == control)
                continue;
            for (int j = 0; j < i; ++j) {
                if (bombs[i] == bombs[j])
                    break;
                if (j == i - 1) 
                    success = true;
            }
            if (i == 0)
                success = true;
        }
    }
}

int main() {

    return 0;
}
