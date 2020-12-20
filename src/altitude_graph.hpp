#ifndef STATISTICS_HPP
#define STATISTICS_HPP

// Include this first, to evade setjmp header bug
#include "image/format/png.hpp"

#include <string>
#include <vector>
#include <set>
#include <exception>

#include <boost/scoped_array.hpp>

#include "settings_t.hpp"

#include "players.hpp"

#include "image/image_base.hpp"
#include "image/memory_image.hpp"
#include "image/cached_image.hpp"
#include "image/algorithms.hpp"
#include "image/format/png.hpp"

#include "mc/world.hpp"
#include "mc/blocks.hpp"
#include "mc/utils.hpp"

#include "nbt/nbt.hpp"

class AltitudeGraph
{
public:
    AltitudeGraph(settings_t& _s);
    void createGraph();

    /* call this to register block information */
    void registerBloc(mc::MaterialT *material, int altitude);

    long getMax();
private:
    settings_t s;
    int width;
    int height;
    boost::scoped_array<long> altitudeRegistry;

};

#endif // STATISTICS_HPP
