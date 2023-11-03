#include <iostream>

class USBDevice
{
private:
	long m_id{};

public:
	USBDevice(long id) : m_id{ id }{}

	long getID() const { return m_id; }
};

class NetworkDevice
{
private:
	long m_id{};

public: 
	NetworkDevice(long id): m_id{id}{}

	long getID() const { return m_id; }

};

class WirelessAdapter : public USBDevice, public NetworkDevice
{
public:
	WirelessAdapter(long usbId, long networkId): USBDevice{usbId}, NetworkDevice{networkId}{}
};

int main()
{
	WirelessAdapter c54G{ 442, 181742 };
	std::cout << c54G.getID();     //error, the WirelessAdapter can't be picked

	std::cout << c54G.USBDevice::getID(); // wskazuje z ktorej klasy chcê dziedziczyc


	return 0;
}