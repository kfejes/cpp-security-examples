#include <iostream>

using namespace std;

enum class DeviceConfigType {
    Endpoint, 
    BaseStation, 
    DataConcentrator
};

void showDeviceConfig(DeviceConfigType config) {
    switch(config) {
        case DeviceConfigType::Endpoint: {
            cout << "CONFIG: Endpoint" << endl;        
        }
        break;
        case DeviceConfigType::BaseStation: {
            cout << "CONFIG: BaseStation" << endl;
        }
        break;
        case DeviceConfigType::DataConcentrator: {
            cout << "CONFIG: DataConcentrator" << endl;
        }
        break;
        default: {
            cout << "Not recognized " << endl;
        }
        break;
    }
}

auto createDeviceConfig(int IDType) {
    DeviceConfigType config = static_cast<DeviceConfigType>(IDType);

    return config;
}


int main() {
    showDeviceConfig(createDeviceConfig(2));

    return 0;
}