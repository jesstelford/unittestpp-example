#include <stdlib.h>
#include <vector>

struct Vector {
    float x;
    float y;
};

class PhysicsObject
{

    public:
        PhysicsObject() {
            position.x = 40;
            position.y = 10;
        }

        Vector getPosition() {
            return position;
        }

        void addForce(Vector force) {
            forces.push_back(force);
        }

        const std::vector<Vector>& getForces() const {
            return forces;
        }

        void update() {
            for (
                std::vector<Vector>::iterator i = forces.begin();
                i != forces.end();
                i++
            ) {
                position.x += i->x;
                position.y += i->y;
            }
        }

    private:
        Vector position;
        std::vector<Vector> forces;

    public:

};
