#pragma once

enum class Player { None ,X, O }; // enum aan maken voor de spelers, kan zo ook geen ander waarde krijgen dan X of O

// struct voor de zetten
struct Move {
	int row;
	int col;
	Player player;
};