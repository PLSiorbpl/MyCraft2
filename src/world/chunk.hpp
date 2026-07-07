#pragma once
#include <cinttypes>
#include <array>
#include "glm/glm.hpp"

enum class Type : uint8_t {
    AIR = 0,
    Grass = 1,
};

class Chunk {
public:
    struct Block {
        Type type;
        explicit Block(const Type type = Type::AIR) : type(type) {}
    };

    struct Vertex {
        glm::vec3 position;
    };

    static constexpr int WIDTH = 16;
    static constexpr int HEIGH = 16;
    static constexpr int DEPTH = 16;
    static constexpr int SIZE = WIDTH*HEIGH*DEPTH;

    static int index(const int x, const int y, const int z) {
        const int idx = x + z * WIDTH + y * WIDTH * DEPTH;
        return idx;
    }

    [[nodiscard]] const Block &get(const int x, const int y, const int z) const {
        return blocks[index(x, y, z)];
    }

    void set(const int x, const int y, const int z, const Block &block) {
        blocks[index(x, y, z)] = block;
    }

    std::array<Block, SIZE> blocks;
    std::vector<Vertex> mesh;

    bool is_dirty = false;
    bool has_terrain = false;
    bool has_mesh = false;
    bool in_render = false;
};