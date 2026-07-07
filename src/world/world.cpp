#include "world.hpp"

namespace world {
    std::vector<Chunk> world;

    Chunk *chunk_find(const int chunkX, const int chunkZ) {
        for (auto &c : world) {
            if (c.chunk_x == chunkX && c.chunk_z == chunkZ) {
                return &c;
            }
        }
        return nullptr;
    }
}
