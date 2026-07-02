#include <iostream>
#include <string>
using namespace std;

/*
================================================================================
                            INHERITANCE STRUCTURE
================================================================================

1. HYBRID / DIAMOND INHERITANCE (with Virtual Base Class):
               [ Device ]  (Virtual Base)
              /          \
      [ GPSReceiver ]  [ CameraSensor ]  (Hierarchical / Virtual Inheritance)
              \          /
         [ NavigationSystem ]            (Multiple / Diamond Resolution)

2. MULTILEVEL & MULTIPLE INHERITANCE:
      [ Vehicle ] (Base)
           |
    [ ElectricVehicle ]                  (Multilevel: Vehicle -> ElectricVehicle)
           |
           +----------------+
                            |
   [ AutonomousSystem ]     |
  (from NavigationSystem)   |
           \                /
         [ SmartElectricCar ]            (Multiple: AutonomousSystem + ElectricVehicle)

================================================================================
*/

// ==========================================
// 1. Diamond Base: Device
// ==========================================
class Device {
protected:
    string deviceID;
public:
    Device(string id) : deviceID(id) {
        cout << "[Device] Constructor called for ID: " << deviceID << endl;
    }
    virtual ~Device() {
        cout << "[Device] Destructor called for ID: " << deviceID << endl;
    }
    void showDeviceStatus() {
        cout << "Device ID: " << deviceID << " | Status: Active" << endl;
    }
};

// ==========================================
// 2. Virtual Inheritance: GPSReceiver & CameraSensor
// ==========================================
// Using 'virtual public' to prevent the Diamond Problem
class GPSReceiver : virtual public Device {
protected:
    double accuracy; // in meters
public:
    GPSReceiver(string id, double acc) : Device(id), accuracy(acc) {
        cout << "[GPSReceiver] Constructor called" << endl;
    }
    ~GPSReceiver() override {
        cout << "[GPSReceiver] Destructor called" << endl;
    }
    void showGPSAccuracy() {
        cout << "GPS Accuracy: " << accuracy << " meters" << endl;
    }
};

class CameraSensor : virtual public Device {
protected:
    int resolution; // in megapixels
public:
    CameraSensor(string id, int res) : Device(id), resolution(res) {
        cout << "[CameraSensor] Constructor called" << endl;
    }
    ~CameraSensor() override {
        cout << "[CameraSensor] Destructor called" << endl;
    }
    void showCameraResolution() {
        cout << "Camera Resolution: " << resolution << " MP" << endl;
    }
};

// ==========================================
// 3. Hybrid / Diamond Resolution: NavigationSystem
// ==========================================
// Inherits from both GPSReceiver and CameraSensor.
// Due to 'virtual' inheritance above, only ONE instance of 'Device' is created.
class NavigationSystem : public GPSReceiver, public CameraSensor {
protected:
    string mapVersion;
public:
    // NOTE: In virtual inheritance, the most-derived class is responsible 
    // for invoking the virtual base class constructor ('Device').
    NavigationSystem(string id, double acc, int res, string mapVer)
        : Device(id), GPSReceiver(id, acc), CameraSensor(id, res), mapVersion(mapVer) {
        cout << "[NavigationSystem] Constructor called" << endl;
    }
    ~NavigationSystem() override {
        cout << "[NavigationSystem] Destructor called" << endl;
    }
    void showNavigationDetails() {
        showDeviceStatus(); // Unique and unambiguous call thanks to virtual inheritance!
        showGPSAccuracy();
        showCameraResolution();
        cout << "Map Version: " << mapVersion << endl;
    }
};

// ==========================================
// 4. Base class for Vehicle Tree
// ==========================================
class Vehicle {
protected:
    string brand;
public:
    Vehicle(string b) : brand(b) {
        cout << "[Vehicle] Constructor called for brand: " << brand << endl;
    }
    virtual ~Vehicle() {
        cout << "[Vehicle] Destructor called for brand: " << brand << endl;
    }
};

// ==========================================
// 5. Multilevel Inheritance: ElectricVehicle
// ==========================================
// Vehicle -> ElectricVehicle
class ElectricVehicle : public Vehicle {
protected:
    int batteryCapacity; // in kWh
public:
    ElectricVehicle(string b, int cap) : Vehicle(b), batteryCapacity(cap) {
        cout << "[ElectricVehicle] Constructor called" << endl;
    }
    ~ElectricVehicle() override {
        cout << "[ElectricVehicle] Destructor called" << endl;
    }
    void showEVStats() {
        cout << "Brand: " << brand << " | Battery Capacity: " << batteryCapacity << " kWh" << endl;
    }
};

// ==========================================
// 6. Autonomous System (derived from NavigationSystem)
// ==========================================
class AutonomousSystem : public NavigationSystem {
protected:
    string autopilotVersion;
public:
    AutonomousSystem(string id, double acc, int res, string mapVer, string autoVer)
        : Device(id), NavigationSystem(id, acc, res, mapVer), autopilotVersion(autoVer) {
        cout << "[AutonomousSystem] Constructor called" << endl;
    }
    ~AutonomousSystem() override {
        cout << "[AutonomousSystem] Destructor called" << endl;
    }
    void showAutopilotVersion() {
        cout << "Autopilot Version: " << autopilotVersion << endl;
    }
};

// ==========================================
// 7. Multiple Inheritance: SmartElectricCar
// ==========================================
// Inherits from ElectricVehicle AND AutonomousSystem
class SmartElectricCar : public ElectricVehicle, public AutonomousSystem {
private:
    string modelName;
public:
    SmartElectricCar(string model, string brand, int battery, string devId, double gpsAcc, int camRes, string mapVer, string autoVer)
        : Device(devId),
          ElectricVehicle(brand, battery),
          AutonomousSystem(devId, gpsAcc, camRes, mapVer, autoVer),
          modelName(model) {
        cout << "[SmartElectricCar] Constructor called" << endl;
    }
    
    ~SmartElectricCar() override {
        cout << "[SmartElectricCar] Destructor called" << endl;
    }

    void showCarProfile() {
        cout << "\n--- Smart Electric Car Profile: " << modelName << " ---" << endl;
        showEVStats();
        showAutopilotVersion();
        showNavigationDetails();
        cout << "-------------------------------------------\n" << endl;
    }
};

// ==========================================
// 8. Main Execution
// ==========================================
int main() {
    cout << "=== Creating SmartElectricCar Object ===\n" << endl;
    
    SmartElectricCar myCar(
        "Model S",          // modelName
        "Tesla",            // brand
        100,                // battery capacity (kWh)
        "NAV-SYS-9000",     // device ID
        0.5,                // GPS accuracy (meters)
        48,                 // Camera resolution (MP)
        "v14.2",            // Map version
        "FSD Beta v12"      // Autopilot version
    );

    myCar.showCarProfile();

    cout << "=== Destroying SmartElectricCar Object (Check Destructor Order) ===\n" << endl;
    return 0;
}
