#include "bridge.h"
#include "test.h"

TEST(bridge_test, circle_resize)
{
    Raster_renderer rr;
    Circle raster_circle(rr, 10, 10, 5);
    raster_circle.render();
    raster_circle.resize(2);
    ASSERT_EQ(raster_circle.radius, 10);
}
