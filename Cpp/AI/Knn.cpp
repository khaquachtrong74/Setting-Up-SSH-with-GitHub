#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include<string>
using namespace std;
// Cấu trúc để lưu trữ một điểm dữ liệu
struct DataPoint {
    vector<double> features;  // Các đặc trưng (feature) của điểm dữ liệu
    string label;             // Nhãn của điểm dữ liệu

};

// Hàm tính khoảng cách Euclid giữa hai điểm
double euclideanDistance(const vector<double>& a, const vector<double>& b) {
    
    double distance = 0.0;
    for (size_t i = 0; i < a.size(); ++i) {
        distance += pow(a[i] - b[i], 2);
    }
    return sqrt(distance);
}

// Hàm thực hiện thuật toán k-NN
string kNN(const vector<DataPoint>& trainingData, const vector<double>& testPoint, int k) {
    vector<pair<double, string>> distances;

    // Tính khoảng cách giữa testPoint và từng điểm trong trainingData
    for (const auto& dataPoint : trainingData) {
        double dist = euclideanDistance(testPoint, dataPoint.features);
        distances.push_back({dist, dataPoint.label});
    }
    
    // Sắp xếp các điểm theo khoảng cách tăng dần
    sort(distances.begin(), distances.end());

    // Đếm số lượng nhãn của k láng giềng gần nhất
    int countClass1 = 0, countClass2 = 0;
    for (int i = 0; i < k; ++i) {
        if (distances[i].second == "Class1") {
            ++countClass1;
        } else {
            ++countClass2;
        }
    }

    // Trả về nhãn chiếm ưu thế trong k láng giềng gần nhất
    return (countClass1 > countClass2) ? "Class1" : "Class2";
}

int main() {
    // Tập dữ liệu huấn luyện (training data)
    vector<DataPoint> trainingData = {
        {{1.0, 2.0}, "Class1"},
        {{2.0, 3.0}, "Class1"},
        {{3.0, 3.0}, "Class2"},
        {{6.0, 6.0}, "Class2"},
        {{7.0, 7.0}, "Class2"}
    };

    // Điểm dữ liệu mới cần phân loại
    vector<double> testPoint = {3.5, 3.5};

    // Thực hiện k-NN với k = 3
    string predictedClass = kNN(trainingData, testPoint, 3);

    cout << "Test Point is classified as: " << predictedClass << endl;

    return 0;
}

