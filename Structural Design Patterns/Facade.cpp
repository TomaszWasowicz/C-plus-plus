/*

Facade Design Pattern in C++ provides a simplified interface 
to a larger body of code, hiding its complexity.

Explanation:
1. Subsystems (Amplifier, DVDPlayer, Projector):
- These are the individual components of the system, each providing specific functionality.
2. Facade (HomeTheaterFacade):
- Provides a unified interface for the client to interact with the system.
- Simplifies interaction by orchestrating calls to the subsystems.
3. Client Code:
- The client interacts only with the HomeTheaterFacade, 
avoiding direct interaction with the complex subsystems.

*/

#include <iostream>
#include <string>

//Subsystem A: Amplifier
class Amplifier {
public:
	void on() const { std::cout << "Amplifier is on." << std::endl; }
	void off() const { std::cout << "Amplifier is off." << std::endl; }
	void setVolume(int volumeLevel) const { std::cout << "Amplifier volume set to " << volumeLevel << std::endl; }
};

// Subsystem B: DVD Player
class DVDPlayer {
public:
	void on() const { std::cout << "DVD player is on." << std::endl; }
	void off() const { std::cout << "DVD player is off." << std::endl; }
	void play(const std::string& movie) const { std::cout << "Playing movie: " << movie << std::endl; }
	void stop() const { std::cout << "Stopping movie." << std::endl; }
};

// Susbsystem C: Projector
class Projector {
public:
	void on() const { std::cout << "Projector is on." << std::endl; }
	void off() const { std::cout << "Projector is off." << std::endl; }
	void wideScreenMode(const std::string& movie) const { std::cout << "Setting wide screen mode: " << movie << std::endl; }
};

// Facade: HomeTheaterFacade
class HomeTheaterFacade {
private:
	Amplifier amplifier;
	DVDPlayer dvdPlayer;
	Projector projector;

public:
	HomeTheaterFacade(const Amplifier& a, const DVDPlayer& d, const Projector& p)
		: amplifier(a), dvdPlayer(d), projector(p) {
	}

	void watchMovie(const std::string& movie) const {
		std::cout << "Get ready to watch: " << std::endl;
		amplifier.on();
		amplifier.setVolume(10);
		dvdPlayer.on();
		dvdPlayer.play(movie);
		projector.on();
		projector.wideScreenMode(movie);
		std::cout << "Movie is playing: " << std::endl;
	}

	void endMovie() const {
		std::cout << "Shutting movie theater down ... " << std::endl;
		amplifier.off();
		projector.off();
		dvdPlayer.stop();
		dvdPlayer.off();
	}
};

int main()
{
	//Subsystems

	Amplifier amp;
	DVDPlayer dvd;
	Projector projector;

	// Facade
	HomeTheaterFacade homeTheater(amp, dvd, projector);

	// use the Facade to constrol subsystems
	homeTheater.watchMovie("Avatar");
	homeTheater.endMovie();

	return 0;
}