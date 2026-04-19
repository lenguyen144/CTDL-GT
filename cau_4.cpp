#include <iostream> 

int p_x_de_quy(int n, int x) {
	if(n==0) return 1;
	if(n==1) return x;
	return p_x_de_quy(n-1,x)-p_x_de_quy(n-2,x);
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
    if (n == 0) return 1;
    if (n == 1) return 2*x + 3*y - 8;

    int p0 = 1; 
    int p1 = 2*x + 3*y - 8;
    int pn;

    for (int i = 2; i <= n; i++) {
        pn = p1 + p0;
        p0 = p1;
        p1 = pn;
    }

    return p1;
}


int main() {
	std::cout<<"p_x_de_quy(n=5 , x=2): "<<p_x_de_quy(5,2)<<'\n';
	std::cout << "p_x_y_de_quy(n = 10, x = -5, y = 3): " << p_x_y_de_quy(2, -5, 3) <<std::endl;
	std::cout << "p_x_y_ko_de_quy(n = 10, x = -5, y = 3): " << p_x_y_ko_de_quy(2, -5, 3) <<std::endl;
}
