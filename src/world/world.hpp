#pragma once
#include "chunk.hpp"
#include <vector>

namespace world {
    extern std::vector<Chunk> world;

    Chunk *chunk_find(int chunkX, int chunkZ);
}

