#pragma once

class Shape {
	static int gid;

protected:
	int id;

public:
	Shape() : id( ++gid ) { 	}

	virtual void draw() const = 0;
};

int Shape::gid{ 0 };
