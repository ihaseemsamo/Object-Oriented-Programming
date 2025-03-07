#include <iostream>
using namespace std;

class Level {
private:
    string levelName;
    int difficulty;

public:
    Level(string name, int diff) : levelName(name), difficulty(diff) {}

    void display() const {
        cout << "Level: " << levelName << "\nDifficulty: " << difficulty << "\n";
    }
};

class VideoGame {
private:
    string title;
    string genre;
    Level* levels[10];
    int levelCount;

public:
    VideoGame(string t, string g) : title(t), genre(g), levelCount(0) {}

    ~VideoGame() {
        for (int i = 0; i < levelCount; i++) {
            delete levels[i];
        }
    }

    void addLevel(string name, int diff) {
        if (levelCount < 10) {
            levels[levelCount++] = new Level(name, diff);
        }
    }

    void display() const {
        cout << "Game: " << title << "\nGenre: " << genre << "\nLevels:\n";
        for (int i = 0; i < levelCount; i++) {
            levels[i]->display();
            cout << "-----------------------\n";
        }
    }
};

int main() {
    VideoGame game("WATCH DOGS", "ARCADE");
    game.addLevel("Downtown ", 2);
    game.addLevel("The Beast", 5);
    
    cout << "Game Details:\n";
    game.display();
    
    return 0;
}

