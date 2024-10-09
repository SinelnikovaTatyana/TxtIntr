#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <unistd.h>

using namespace std;

void h() {
    cout << "Использование логариф. калькулятора: ./calculator [-h] [-x] [-o]\n";
    cout << "  -h : вывод справки\n";
    cout << "  -x : значение для логарифма (обязательно)\n";
    cout << "  -o : основание логарифма (необязательно, по умолчанию - e)\n";
    cout << "Примеры использования:\n";
    cout << "./calculator -x 60\n";
    cout << "./calculator -x 60 -o 5\n";
}

double calc_Log(double x, double base = M_E) {
    return log(x) / log(base);
}

int main(int argc, char* argv[]) {
    double x = 0.0;
    double o = M_E; // основание по умолчанию e

    // Обработка аргументов командной строки
    int option;
    while ((option = getopt(argc, argv, "hx:o:")) != -1) {
        switch (option) {
            case 'h':
                h();
                return 0;
            case 'x':
                x = stod(optarg);
                break;
            case 'o':
                o = stod(optarg);
                break;
            case '?':
                h();
                return 1;
        }
    }

    if (x == 0.0) {
        cerr << "Ошибка: не указано значение для логарифма\n";
        return 1;
    }

    double result = calc_Log(x, o);
    cout << "log(" << x << ")_" << o << " = " << result << endl;

    return 0;
}
