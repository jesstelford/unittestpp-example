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

enum {
    RENDERER_2D = 1,
    RENDERER_3D = 2,
    INPUT = 4
};

class Application
{
    private:
        long long enabledModules;

        std::vector<Module*> modules;

    public:

        Application() {}

        void addModule(Module* module) {
            modules->push_back(module);
        }

};

class 3DSApplication : Application
{
    public:
        Application() {
            addModule(new Module_2D_Renderer());
        }
}

void load3DSApplication()
{
    Application *app = new Application();
    app->addModule(new Module_2D_Renderer());
    return app;
}

void initApp()
{
#ifdef IS_3DS initApp
    return load3DSApplication();
#elif IS_VITA
    return load3DSApplication();
#endif
}
