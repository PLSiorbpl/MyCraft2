#include "mesh.hpp"
#include <glm/glm.hpp>

void Generate_Mesh(Chunk *chunk) {
    const float WorldOffsetX = chunk->chunk_x * Chunk::WIDTH;
    const float WorldOffsetZ = chunk->chunk_z * Chunk::DEPTH;

    for (int x = 0; x < Chunk::WIDTH; x++) {
        for (int z = 0; z < Chunk::DEPTH; z++) {
            for (int y = 0; y < Chunk::HEIGH; y++) {
                const glm::vec3 w = {WorldOffsetX + x, static_cast<float>(y), WorldOffsetZ + z};

                if (chunk->get(x, y, z).type != Type::AIR) {
                    chunk->mesh.push_back({{w.x, w.y, w.z}});
                    chunk->mesh.push_back({{w.x, w.y+1, w.z}});
                    chunk->mesh.push_back({{w.x+1, w.y+1, w.z}});
                }
            }
        }
    }
}