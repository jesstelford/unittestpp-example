#include "/usr/src/unittest-cpp/UnitTest++/src/UnitTest++.h"
#include "PhysObject.h"
 
int main() {

    return UnitTest::RunAllTests();

}

TEST (PhysicsObjectPositionDefaultsTo40x10)
{
    PhysicsObject *phys = new PhysicsObject();

    Vector pos = phys->getPosition();

    CHECK_EQUAL (40, pos.x);
    CHECK_EQUAL (10, pos.y);
}

TEST (NoForcesOnDefaultPhysicsObject)
{
    PhysicsObject *phys = new PhysicsObject();

    std::vector<Vector> forces = phys->getForces();

    CHECK_EQUAL (0, forces.size());
}

TEST (AddingForceToPhysicsObject)
{
    PhysicsObject *phys = new PhysicsObject();

    Vector force;
    force.x = 0;
    force.y = 10;

    phys->addForce(force);

    std::vector<Vector> forces = phys->getForces();

    CHECK_EQUAL (1, forces.size());
}

TEST (UpdatingWithNoForcesWillNotMovePosition)
{
    PhysicsObject *phys = new PhysicsObject();

    Vector startPos = phys->getPosition();

    phys->update();

    Vector newPos = phys->getPosition();

    CHECK_EQUAL (startPos.x, newPos.x);
    CHECK_EQUAL (startPos.y, newPos.y);
}

TEST (UpdateWithForceOfZeroWillNotMovePosition)
{
    PhysicsObject *phys = new PhysicsObject();

    Vector startPos = phys->getPosition();

    Vector force;
    force.x = 0;
    force.y = 0;

    phys->addForce(force);
    phys->update();

    Vector newPos = phys->getPosition();

    CHECK_EQUAL (startPos.x, newPos.x);
    CHECK_EQUAL (startPos.y, newPos.y);
}

TEST (UpdateWithForceWillMovePosition)
{
    PhysicsObject *phys = new PhysicsObject();

    Vector startPos = phys->getPosition();

    Vector force;
    force.x = 0;
    force.y = 10;

    phys->addForce(force);
    phys->update();

    Vector newPos = phys->getPosition();

    CHECK_EQUAL (startPos.x, newPos.x);
    CHECK_EQUAL (startPos.y + force.y, newPos.y);
}

TEST (ApplicationHas2DRendererWhenSet)
{
    Application* myApp = new Application(RENDERER_2D | INPUT);
    CHECK (myApp->isModuleEnabled(RENDERER_2D));
}

TEST (ApplicationDoesntHave2DRenderWhenNotSet)
{
    Application* myApp = new Application(INPUT);
    CHECK_EQUAL (false, myApp->isModuleEnabled(RENDERER_2D) );
}
