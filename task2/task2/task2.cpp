#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int pointPosition(double x_center, double y_center, double radius, double x_point, double y_point) {

    double distanceSquared = pow(x_point - x_center, 2) + pow(y_point - y_center, 2);
    double radiusSquared = pow(radius, 2);

    if (abs(distanceSquared - radiusSquared) < 1e-9) {
        return 0; 
    }
    else if (distanceSquared < radiusSquared) {
        return 1; 
    }
    else {
        return 2; 
    }
}

int main() {
    // Укажите пути к файлам 
    string circleFilePath = "C:\\Users\\fanto\\Desktop\\testing\\Testing\\task2\\task2\\circle.txt";
    string pointsFilePath = "C:\\Users\\fanto\\Desktop\\testing\\Testing\\task2\\task2\\points.txt";


    ifstream circleFile(circleFilePath);
    if (!circleFile.is_open()) {
        cerr << "Ошибка: не удалось открыть файл с окружностью." << endl;
        return 1;
    }

    double x_center, y_center, radius;
    circleFile >> x_center >> y_center >> radius;
    circleFile.close();

    ifstream pointsFile(pointsFilePath);
    if (!pointsFile.is_open()) {
        cerr << "Ошибка: не удалось открыть файл с точками." << endl;
        return 1;
    }

    double x_point, y_point;
    while (pointsFile >> x_point >> y_point) {
        int position = pointPosition(x_center, y_center, radius, x_point, y_point);
        cout << position << endl;
    }
    pointsFile.close();

    return 0;
}
