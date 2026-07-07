#include "terrain.hpp"

void Generate_Terrain(const int chunk_x, const int chunk_z, Chunk *chunk) {
    chunk->chunk_x = chunk_x;
    chunk->chunk_z = chunk_z;

    for (int x = 0; x < Chunk::WIDTH; x++) {
        for (int z = 0; z < Chunk::DEPTH; z++) {
            for (int y = 0; y < Chunk::HEIGH; y++) {
                if (y == 0) {
                    chunk->set(x, y, z, Block((y%2 == 0) ? Type::Grass : Type::Stone));
                } else {
                    chunk->set(x, y, z, Block(Type::AIR));
                }
            }
        }
    }

}