#ifndef GAMEDATA_HPP
#define GAMEDATA_HPP

class GameData {
public:
	GameData() {
		selected_level = 0;
		available_levels = 1;
		for (int i = 0; i < total_levels; i++)
			scores[i] = 0;
	}

	void set_score(int score) {
		scores[selected_level] = score;
	}

	int selected_level;
	int available_levels;

	constexpr static int total_levels = 4 * 5;

private:
	int scores[total_levels];
};

#endif // GAMEDATA_HPP