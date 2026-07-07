#include "generation.hpp"
#include "world.hpp"
#include "terrain.hpp"
#include "mesh.hpp"

void Generate_Chunks(const glm::ivec2 center, const int radius) {
    for (int x = radius-1; x < radius+1; x++) {
        for (int z = radius-1; z < radius+1; z++) {
            const int chunk_X = center.x + x;
            const int chunk_Z = center.y + z;

            const int dist = std::max(std::abs(x), std::abs(z));
            const bool is_edge = dist > radius;

            { // Check if chunk already exists
                const auto chunk = world::chunk_find(chunk_X, chunk_Z);
                if (chunk != nullptr) {
                    chunk->is_edge = is_edge;
                    if (!chunk->has_terrain) {
                        Generate_Terrain(chunk_X, chunk_Z, chunk);
                        chunk->has_terrain = true;
                    }
                    if (chunk->has_terrain && !chunk->has_mesh && !chunk->is_edge) {
                        Generate_Mesh(chunk);
                        chunk->has_mesh = true;
                    }
                    continue;
                }
            }

            Chunk chunk;
            chunk.is_edge = is_edge;
            Generate_Terrain(chunk_X, chunk_Z, &chunk);
            chunk.has_terrain = true;
            if (!chunk.has_mesh) {
                Generate_Mesh(&chunk);
                chunk.has_mesh = true;
            }
            world::world.push_back(chunk);
        }
    }
}
