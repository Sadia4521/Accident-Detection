/*#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
// Vehicle class with graphical representation
class Vehicle {
private:
    sf::RectangleShape shape; // Representing the vehicle as a rectangle
    std::string name;
public:
    Vehicle(std::string vehicleName, float startX, float startY) {
        name = vehicleName;
        shape.setSize(sf::Vector2f(50.f, 30.f)); // size of the vehicle
        shape.setFillColor(sf::Color::Green); // default vehicle color
        shape.setPosition(startX, startY); // initial position
    }
    // Function to move the vehicle
    void move(float deltaX, float deltaY) {
        shape.move(deltaX, deltaY); // Move the shape
    }
    // Getters
    sf::RectangleShape getShape() const { return shape; }
    std::string getName() const { return name; }
};
// Function to check for collisions
bool detectCollision(const Vehicle& v1, const Vehicle& v2) {
    // Check for overlap between two vehicles
    return v1.getShape().getGlobalBounds().intersects(v2.getShape().getGlobalBounds());
}
// Main SFML application
int main() {
    // Create a window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Accident Detection Simulation");
    // Create vehicles
    Vehicle car1("Car 1", 100.f, 100.f);
    Vehicle car2("Car 2", 400.f, 300.f);
    sf::Clock clock; // To track time for smooth animation
    while (window.isOpen()) {
        sf::Time deltaTime = clock.restart(); // Time for frame rate control
        sf::Event event;
        // Event handling
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Move cars using keyboard inputs (WASD for car1, Arrow keys for car2)
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) car1.move(0.f, -100.f * deltaTime.asSeconds());
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) car1.move(0.f, 100.f * deltaTime.asSeconds());
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) car1.move(-100.f * deltaTime.asSeconds(), 0.f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) car1.move(100.f * deltaTime.asSeconds(), 0.f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) car2.move(0.f, -100.f * deltaTime.asSeconds());
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) car2.move(0.f, 100.f * deltaTime.asSeconds());
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) car2.move(-100.f * deltaTime.asSeconds(), 0.f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) car2.move(100.f * deltaTime.asSeconds(), 0.f);
        // Check for collision
        if (detectCollision(car1, car2)) {
            car1.getShape().setFillColor(sf::Color::Red); // Change car1 color to red on collision
            car2.getShape().setFillColor(sf::Color::Red); // Change car2 color to red on collision
            std::cout << "Collision Detected!" << std::endl;
        }
        // Clear the screen
        window.clear(sf::Color::White);
        // Draw vehicles
        window.draw(car1.getShape());
        window.draw(car2.getShape());
        // Display everything
        window.display();
    }
    return 0;
}*/
#include <iostream>
using namespace std;
// Vehicle class to represent the position and movement of a car
class Vehicle {
private:
    float x, y; // Position of the vehicle
    string name;
public:
    Vehicle(string vehicleName, float startX, float startY) : name(vehicleName), x(startX), y(startY) {}
    // Function to move the vehicle
    void move(float deltaX, float deltaY) {
        x += deltaX;
        y += deltaY;
        cout << name << " moved to position (" << x << ", " << y << ")." << endl << endl;
    }
    // Getters for position
    float getX() const { return x; }
    float getY() const { return y; }
    string getName() const { return name; }
};
// Function to check collision between two vehicles
bool detectCollision(const Vehicle& v1, const Vehicle& v2) {
    // If the distance between the two vehicles is less than a threshold, consider it a collision
    float distance = sqrt(pow(v2.getX() - v1.getX(), 2) + pow(v2.getY() - v1.getY(), 2));
    return distance <= 2.0f; // Assuming a collision threshold of 2 units
}
// Function to call an ambulance
void callAmbulance() {
    cout << "Collision detected! Calling an ambulance..." << endl;
}
void accidentHitCars() {
    cout << "\n\t\t********** Welcome to the AcciDrive **********" << endl;
    // Initialize two vehicles
    Vehicle car1("Car 1", 0, 0);
    Vehicle car2("Car 2", 5, 5);
    cout << "\nSimulation started. Move the cars to simulate a collision.\n" << endl;
    while (true) {
        // Display options to move the cars
        int choice;
        cout << "1. Move Car 1\n2. Move Car 2\n3. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 3) {
            cout << "\nExiting simulation. Drive safely!" << endl;
            break;
        }
        float dx, dy;
        cout << "Enter movement in X and Y directions: ";
        cin >> dx >> dy;
        if (choice == 1) {
            car1.move(dx, dy);
        }
        else if (choice == 2) {
            car2.move(dx, dy);
        }
        else {
            cout << "\nInvalid choice! Please try again." << endl;
            continue;
        }
        // Check for collision after moving the cars
        if (detectCollision(car1, car2)) {
            cout << "\nAlert! Collision detected between " << car1.getName() << " and " << car2.getName() << "." << endl;
            callAmbulance();
            break; // End simulation after collision
        }
    }
}
class AccidentDetectionSystem {
private:
    float currentSpeed;
    float previousSpeed;
    const float accidentThreshold; // Speed change threshold for detecting accidents
    bool accidentDetected;
public:
    AccidentDetectionSystem() : currentSpeed(0), previousSpeed(0), accidentThreshold(50.0f), accidentDetected(false) {
    }
    // Function to update speed and check for accidents
    void updateSpeed(float newSpeed) {
        previousSpeed = currentSpeed;
        currentSpeed = newSpeed;
        // Detect accident if speed change exceeds the threshold
        if ((currentSpeed - previousSpeed) >= accidentThreshold) {
            accidentDetected = true;
            alertAccident();
        }
        else {
            accidentDetected = false;
        }
    }
    // Function to display accident alert
    void alertAccident() {
        cout << "\nAccident Detected!" << endl;
        cout << "Sending alert to emergency services..." << endl;
    }
    // Function to display speeds
    void displaySpeeds() const {
        cout << "Previous Speed: " << previousSpeed << " km/h" << endl;
        cout << "Current Speed: " << currentSpeed << " km/h" << endl;
    }
    // Check if an accident has been detected
    bool isAccidentDetected() const {
        return accidentDetected;
    }
};
void AccidentDetectionSpeed() {
    AccidentDetectionSystem system;
    float newSpeed;
    cout << "\n\t\t********** Welcome to the SpeedCrash **********" << endl;
    cout << "\nEnter vehicle speeds to simulate accident detection." << endl;
    cout << "A speed change of 50 km/h or more will trigger an alert." << endl;
    while (true) {
        cout << "\nEnter current speed (km/h): ";
        cin >> newSpeed;
        if (newSpeed < 0) {
            cout << "\nExiting the system..." << endl;
            break;
        }
        system.updateSpeed(newSpeed);
        system.displaySpeeds();
        if (system.isAccidentDetected()) {
            cout << "\nPlease drive safely!" << endl;
        }
    }
}
int main() {
    int n;
    cout << "\t\t********** Welcome to the Accident Detection and Alert System **********\n" << endl;
    cout << "We have two systems: ";
    cout << "\n1. SpeedCrash. \n2. AcciDrive.";
    cout << "\nEnter your choice: ";
    cin >> n;
    switch (n) {
    case 1:
        AccidentDetectionSpeed();
        break;
    case 2:
        accidentHitCars();
        break;
    default:
        cout << "Invalid Choice!";
    }
    return 0;
}
