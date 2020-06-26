#include "renju.h"

bool renju::isCorrectCoords(int x, int y)
{
	if ((x >= 0) & (x < 15) & (y >= 0) & (y < 15))
		return true;
	else
		return false;
}

int renju::attack(int a, int b)
{
		if (a == 1 && b == 1) return 10;
		if (a == 2 && b == 1) return 200;
		if (a == 3 && b == 1) return 400;
		if (a == 4 && b == 1) return 600;
		if (a == 5 && b == 1) return 300000;

		if (a == 1 && b == 2) return 25;
		if (a == 2 && b == 2) return 500;
		if (a == 3 && b == 2) return 700;
		if (a == 4 && b == 2) return 10000;
		if (a == 5 && b == 2) return 300000;

		if (a == 5 && b == 0) return 300000;

		return 0;
}

int renju::artificial_intelligence(int i, int j, char color)
{
	int potential = 0, power = 0, tactic = 0, pozition = 0;
	int left, top, bot, right, sum = 0;

	left = i, right = i; top = j, bot = j; potential = 0;
	while (isCorrectCoords(left - 1, top - 1) && field[left - 1][top - 1] == color) left--, top--;
	while (isCorrectCoords(right + 1, bot + 1) && field[right + 1][bot + 1] == color) right++, bot++;
	if (isCorrectCoords(left - 1, top - 1) && field[left - 1][top - 1] == SPACE) potential++;
	if (isCorrectCoords(right + 1, bot + 1) && field[right + 1][bot + 1] == SPACE) potential++;
	power = right - left + 1;
	sum += attack(power, potential);

	left = i, right = i; top = j, bot = j; potential = 0;
	while (isCorrectCoords(left + 1, top - 1) && field[left + 1][top - 1] == color) left++, top--;
	while (isCorrectCoords(right - 1, bot + 1) && field[right - 1][bot + 1] == color) right--, bot++;
	if (isCorrectCoords(left + 1, top - 1) && field[left + 1][top - 1] == SPACE) potential++;
	if (isCorrectCoords(right - 1, bot + 1) && field[right - 1][bot + 1] == SPACE) potential++;
	power = left - right + 1;
	sum += attack(power, potential);

	//
	left = i, right = i; top = j, bot = j; potential = 0;
	while (isCorrectCoords(left - 1, top) && field[left - 1][top] == color) left--;
	while (isCorrectCoords(right + 1, bot) && field[right + 1][bot] == color) right++;
	if (isCorrectCoords(left - 1, top) && field[left - 1][top] == SPACE) potential++;
	if (isCorrectCoords(right + 1, bot) && field[right + 1][bot] == SPACE) potential++;
	power = right - left + 1;
	sum += attack(power, potential);

	left = i, right = i; top = j, bot = j; potential = 0;
	while (isCorrectCoords(left, top - 1) && field[left][top - 1] == color) top--;
	while (isCorrectCoords(right, bot + 1) && field[right][bot + 1] == color) bot++;
	if (isCorrectCoords(left, top - 1) && field[left][top - 1] == SPACE) potential++;
	if (isCorrectCoords(right, bot + 1) && field[right][bot + 1] == SPACE) potential++;
	power = bot - top + 1;
	sum += attack(power, potential);

	left = i; top = j;
	if ((isCorrectCoords(left - 1, top) && field[left - 1][top] == SPACE)&&(isCorrectCoords(left - 2, top) && field[left - 2][top] == SPACE)) tactic++;
	if ((isCorrectCoords(left + 1, top) && field[left + 1][top] == SPACE) && (isCorrectCoords(left + 2, top) && field[left + 2][top] == SPACE)) tactic++;
	//
	if ((isCorrectCoords(left - 1, top-1) && field[left - 1][top - 1] == SPACE) && (isCorrectCoords(left - 2, top - 2) && field[left - 2][top - 2] == SPACE)) tactic++;
	if ((isCorrectCoords(left + 1, top + 1) && field[left + 1][top + 1] == SPACE) && (isCorrectCoords(left + 2, top + 2) && field[left + 2][top + 2] == SPACE)) tactic++;
	//
	if ((isCorrectCoords(left, top + 1) && field[left][top + 1] == SPACE) && (isCorrectCoords(left, top + 2) && field[left][top + 2] == SPACE)) tactic++;
	if ((isCorrectCoords(left, top - 1) && field[left][top - 1] == SPACE) && (isCorrectCoords(left, top - 2) && field[left][top - 2] == SPACE)) tactic++;
	//
	if ((isCorrectCoords(left - 1, top + 1) && field[left - 1][top + 1] == SPACE) && (isCorrectCoords(left - 2, top + 2) && field[left - 2][top + 2] == SPACE)) tactic++;
	if ((isCorrectCoords(left + 1, top - 1) && field[left + 1][top - 1] == SPACE) && (isCorrectCoords(left + 2, top - 2) && field[left + 2][top - 2] == SPACE)) tactic++;
	//
	////
	//
	if ((isCorrectCoords(left - 1, top) && field[left - 1][top] == color) && (isCorrectCoords(left + 1, top) && field[left + 1][top] == SPACE)) tactic++;
	if ((isCorrectCoords(left - 1, top) && field[left - 1][top] == SPACE) && (isCorrectCoords(left + 1, top) && field[left + 1][top] == color)) tactic++;
	//
	if ((isCorrectCoords(left - 1, top - 1) && field[left - 1][top - 1] == color) && (isCorrectCoords(left + 1, top + 1) && field[left + 1][top + 1] == SPACE)) tactic++;
	if ((isCorrectCoords(left - 1, top - 1) && field[left - 1][top - 1] == SPACE) && (isCorrectCoords(left + 1, top + 1) && field[left + 1][top + 1] == color)) tactic++;
	//
	if ((isCorrectCoords(left, top + 1) && field[left][top + 1] == color) && (isCorrectCoords(left, top - 1) && field[left][top - 1] == SPACE)) tactic++;
	if ((isCorrectCoords(left, top + 1) && field[left][top + 1] == SPACE) && (isCorrectCoords(left, top - 1) && field[left][top - 1] == color)) tactic++;
	//
	if ((isCorrectCoords(left - 1, top + 1) && field[left - 1][top + 1] == SPACE) && (isCorrectCoords(left + 1, top - 1) && field[left + 1][top - 1] == color)) tactic++;
	if ((isCorrectCoords(left - 1, top + 1) && field[left - 1][top + 1] == color) && (isCorrectCoords(left + 1, top - 1) && field[left + 1][top - 1] == SPACE)) tactic++;
	//
	////
	//
	if ((isCorrectCoords(left + 1, top + 1)) && (field[left + 1][top + 1] == color)) pozition++;
	if ((isCorrectCoords(left - 1, top - 1)) && (field[left - 1][top - 1] == color)) pozition++;
	if ((isCorrectCoords(left + 1, top - 1)) && (field[left + 1][top - 1] == color)) pozition++;
	if ((isCorrectCoords(left - 1, top + 1)) && (field[left - 1][top + 1] == color)) pozition++;
	//
	if ((isCorrectCoords(left, top + 1)) && (field[left][top + 1] == color)) pozition++;
	if ((isCorrectCoords(left, top - 1)) && (field[left][top - 1] == color)) pozition++;
	if ((isCorrectCoords(left + 1, top)) && (field[left + 1][top] == color)) pozition++;
	if ((isCorrectCoords(left - 1, top)) && (field[left - 1][top] == color)) pozition++;

	return sum + tactic * 10 + pozition * 10;
}


// вывод игрового поля
void renju::display()
{
	system("cls");
	std::cout << "      a   b   c   d   e   f   g   h   i   j   k   l   m   n   o " << std::endl;
	for (int k = 0; k < 65; k++)
		std::cout << "-";
	std::cout << std::endl;
	for (int i = 0; i < 15; i++)
	{
		std::cout << std::setw(3)<< i+1 <<" | ";
		for (int j = 0; j < 15; j++)
		{
			std::cout << field[i][j] << " | ";
		}
		std::cout << std::endl;
		for (int k = 0; k < 65; k++)
			std::cout << "-";
		std::cout << std::endl;
	}
}

// проверка на победу
char renju::victory_check()
{	
	bool draw;
	int x, y, g;

	for (int i = 0; i < 15; i++)
		for (int j = 0; j < 15; j++)
		{
			if (field[i][j] != SPACE) {
				x = i; y = j; 
				g = 1;
				while (isCorrectCoords(x + 1, j) && field[x][j] == field[x + 1][j]) x++, g++;
				if (g == 5) return field[i][j];
				if (g > 5 && field[i][j] == WHITE) return field[i][j];
				g = 1;
				while (isCorrectCoords(i, y + 1) && field[i][y] == field[i][y + 1]) y++, g++;
				if (g == 5) return field[i][j];
				if (g > 5 && field[i][j] == WHITE) return field[i][j];
				x = i, y = j;
				g = 1;
				while (isCorrectCoords(x + 1, y + 1) && field[x][y] == field[x + 1][y + 1]) y++, g++, x++;
				if (g == 5) return field[i][j];
				if (g > 5 && field[i][j] == WHITE) return field[i][j];
				x = i, y = j;
				g = 1;
				while (isCorrectCoords(x + 1, y - 1) && field[x][y] == field[x + 1][y - 1]) y--, g++, x++;
				if (g == 5) return field[i][j];
				if (g > 5 && field[i][j] == WHITE) return field[i][j];
			}
		}

	draw = 1;
	for (int i = 0; i < 15; i++)
		for (int j = 0; j < 15; j++)
			if (field[i][j] == SPACE) draw = 0;
	if (draw) return 'd';

	return SPACE;

}

// ход человека
void renju::white_move()
{
	int x, y; char xxx;
	std::cout << "Ход белых. ";
	std::cout << "Введите 0, чтобы пропустить ход. " << std::endl;
	std::cout << "Буква: "; std::cin >> xxx;
	x = ((int)xxx)-97;
	if (x == -49) return;
	std::cout << "Цифра: "; std::cin >> y; y--;


	if ((field[y][x] != SPACE) || (y < 0) || (y > 14) || (x < 0) || (x > 14)) {
		while ((field[y][x] != SPACE) || (y < 0) || (y > 14) || (x < 0) || (x > 14))
		{
			std::cout << std::endl << "Ошибка! Повторите ввод! " << std::endl;
			std::cout << "Буква: "; std::cin >> xxx;
			x = ((int)xxx) - 97;
			if (x == -49) return;
			std::cout << "Цифра: "; std::cin >> y; y--;
		}
	}

	field[y][x] = WHITE;
}

// ход компьютера
void renju::black_move()
{
	srand(time(0));
	int x, y;
	int max_x, max_y, max = 0, sum;
	

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (field[i][j] == SPACE) {
				sum = 0;
				sum += artificial_intelligence(i, j, BLACK);
				sum += artificial_intelligence(i, j, WHITE);

				if (sum > max) { max = sum; max_x = i; max_y = j; }				
			}
		}
	}
	display();
	field[max_x][max_y] = BLACK;
	return;

	// рандомная клетка
	/*srand(time(0));
	int x, y;
	do
	{
		x = rand() % 15;
		y = rand() % 15;
	} while (field[x][y] != SPACE);

	field[x][y] = BLACK;*/
}

// ход компьютера за белых
void renju::white_move_comp()
{
	srand(time(0));
	int x, y;
	int max_x, max_y, max = 0, sum;


	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (field[i][j] == SPACE) {
				sum = 0;
				sum += artificial_intelligence(i, j, BLACK);
				sum += artificial_intelligence(i, j, WHITE);

				if (sum > max) { max = sum; max_x = i; max_y = j; }
			}
		}
	}
	display();
	field[max_x][max_y] = WHITE;
	return;
}

// начало игры
void renju::start_game()
{
	char check = SPACE;
	while (check == SPACE)
	{
		display();
		std::cout << check << std::endl;
		white_move_comp();
		step++;
		check = victory_check();
		if (check != SPACE) {
			if (check == 'd') {
				display();
				std::cout<< std::endl << "Ничья";
				return;
			}
			display();
			std::cout << "Победили " << check << std::endl;
			return;
		}

		black_move();
		step++;
		check = victory_check();
		if (check != SPACE) {
			if (check == 'd') {
				display();
				std::cout << std::endl << "Ничья";
				return;
			}
			display();
			std::cout << "Победили " << check << std::endl;
			return;
		}
	}
}
