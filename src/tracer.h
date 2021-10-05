#pragma once

#include <iostream>

class Tracer {
	static int objectsCreated;
public:
	Tracer() {
		std::cout << "default ctor\n";
		objectsCreated++;
	}

	Tracer(const Tracer& t) {
		std::cout << "copy ctor\n";
		objectsCreated++;
	}

	Tracer(Tracer&& t) {
		std::cout << "move ctor\n";
		objectsCreated++;
	}

	static int objectsMade() { return objectsCreated; }

protected:
	~Tracer() = default;
};

int Tracer::objectsCreated{0};
