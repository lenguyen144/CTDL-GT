#include <iostream>


int p_x_de_quy(int n, int x) {
	return 0;
}


int p_x_y_de_quy(int n, int x, int y) {
	if (n <= 0) return 0;
	if (n == 1) return 2*x + 3*y - 8;

	return p_x_y_de_quy(n - 1, x, y) + p_x_y_de_quy(n - 2, x, y);
}


int p_x_ko_de_quy(int n, int x) {
	return 0;
}


int p_x_y_ko_de_quy(int n, int x, int y) {
	return 0;
}


int main() {
	std::cout << "p_x_y_de_quy(n = 10, x = -5, y = 3): " << p_x_y_de_quy(2, -5, 3);
}