#include <memory>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Point {
    float x;
    float y;
};

class DataHandler {
    private:
        vector<Point> coordinates;
    public:
        DataHandler() = default;
        ~DataHandler() = default;
        void addCoordinate(Point coordinate) {
            this->coordinates.emplace_back(coordinate);
        }
        auto getCoordinate(int place) {
            return this->coordinates.at(place); 
        }
};

class Model {
    private:
        string tag;
    public:
        Model(string tag) : tag(tag) {
            cout << "Constructed Tag: " << this->tag << endl; 
        }

        ~Model() {
            cout << "Destructed Tag: " << this->tag << endl; 
        }
};

int main() {
    Model AFirst("First");
    Model BSecond("Second");

    unique_ptr<DataHandler> resourceAccessor(new DataHandler());
    unique_ptr<DataHandler> anotherResourceAccessor(resourceAccessor.get());

    Point dot;
    dot.x = 4.0;
    dot.y = 3.3;

    resourceAccessor->addCoordinate(dot);
    auto value = anotherResourceAccessor->getCoordinate(0);
    cout << value.x << ":"<< value.y << endl;

    return 0;
}
