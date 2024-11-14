#include <iostream>
#include <cstdlib>
#include <ctime>

#ifdef _WIN32  // Check if we are compiling for Windows
#include <windows.h>  // For Windows sleep
#else
#include <unistd.h>  // For Unix/Linux/MacOS sleep
#endif

using namespace std;

// Simulate reading system parameters (temperature, pressure, vibration levels)
float readTemperature() {
    return rand() % 100 + 20;  // Simulate temperature between 20°C and 120°C
}

float readPressure() {
    return rand() % 101 + 900;  // Simulate pressure between 900 and 1000 hPa
}

float readVibration() {
    return rand() % 11;  // Simulate vibration levels (0 to 10)
}

// Monitor system function
void monitorSystem() {
    srand(time(0));  // Seed the random number generator

    // Define thresholds for triggering actions
    const float TEMPERATURE_THRESHOLD = 80.0f;  // Cooling system activation
    const float PRESSURE_THRESHOLD = 950.0f;    // Pressure relief system activation
    const float VIBRATION_THRESHOLD = 5.0f;     // Alarm activation for high vibration

    bool coolingSystemStatus = false;
    bool pressureReliefStatus = false;
    bool alarmStatus = false;

    int iterations = 0;
    const int maxIterations = 10;  // Set number of iterations

    // Infinite loop to simulate continuous monitoring, but limited to maxIterations
    while (iterations < maxIterations) {
        // Simulate sensor readings
        float temperature = readTemperature();
        float pressure = readPressure();
        float vibration = readVibration();

        // Display the sensor values
        cout << "Temperature: " << temperature << "°C, Pressure: " << pressure << " hPa, Vibration: " << vibration << endl;

        // Control logic based on sensor thresholds
        if (temperature > TEMPERATURE_THRESHOLD && !coolingSystemStatus) {
            cout << "Turning ON cooling system." << endl;
            coolingSystemStatus = true;
        } else if (temperature <= TEMPERATURE_THRESHOLD && coolingSystemStatus) {
            cout << "Turning OFF cooling system." << endl;
            coolingSystemStatus = false;
        }

        if (pressure < PRESSURE_THRESHOLD && !pressureReliefStatus) {
            cout << "Triggering pressure relief system." << endl;
            pressureReliefStatus = true;
        } else if (pressure >= PRESSURE_THRESHOLD && pressureReliefStatus) {
            cout << "Deactivating pressure relief system." << endl;
            pressureReliefStatus = false;
        }

        if (vibration > VIBRATION_THRESHOLD && !alarmStatus) {
            cout << "ALERT: High vibration detected!" << endl;
            alarmStatus = true;
        } else if (vibration <= VIBRATION_THRESHOLD && alarmStatus) {
            cout << "Vibration levels are normal." << endl;
            alarmStatus = false;
        }

        // Wait for 1 second before checking again
#ifdef _WIN32
        Sleep(1000);  // Windows Sleep (in milliseconds)
#endif

        iterations++;  // Increment the number of iterations
    }

    cout << "Monitoring completed after " << maxIterations << " iterations." << endl;
}

int main() {
    // Start the monitoring system
    monitorSystem();
    return 0;
}
